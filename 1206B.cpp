#include <bits/stdc++.h>
using namespace std;

int main() //TODO: debug why neg change its value entirely after escaping the for loop?
{
	const long long k = 1e5;
	long long int n;
	long long int a[k];
	long long int neg = 0; 
	long long int ans = 0;
	bool zero = false;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] < 0) // is it possible to replace this? what is the alternative to find odd or even number? no
		{
			neg += 1;
			ans += -1 - a[i];
		}
		if (a[i] == 0)//no matter even or odd
		{
			zero = true;
			ans += 1;
		}

		if (a[i] > 0) // positive 
		{	
			ans += a[i] - 1; // if 1, ans += 0;
		}
	}
 	if (zero == false && neg % 2 != 0) //if there is odd number of -1, and no 0 is available, just change one of the -1 into 1
	{
		ans += 2;
	}
	cout << ans << "\n";	
}

/*
idea 1:
ans = 0
number of n < 0
	if odd
	ans + 2
if n != 1
	if n < 0
		ans += -1 -n;
	if n > 0
		ans += n - 1
	if n = 0
		ans = 1

if there is 0, no need to consider about the even or odd number of -1
	always one step, no matter -1 or 1
	if there is odd number of -1, 0 become -1
	if there is no need to change 1, 0 become 1
	so when there is 0, negative change to -1, positive change to 1, and answer +1



/*
* bug 1: program thought a[1*10^5] is a[15], so the input only takes 15 numbers, so it somehow affect the value of neg
* change to a[1e5]
* bug 2: a[1e5], 1e5 is seen as double, and number of array can only take numbers; but a[long long int(1e5)] is wrong
* change: add const long long k = 1e5 and a[k];
*/
