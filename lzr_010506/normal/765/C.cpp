#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll k,a,b;
int main()
{
	cin >> k >> a >> b;
	if(a < k && b < k)
	{
		cout << -1;
		return 0;
	}
	if(b < k && a % k)
	{
		cout << -1;
		return 0;
	}
	if(a < k && b % k)
	{
		cout << -1;
		return 0;
	}
	cout << a / k + b / k;
	return 0;
}