#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	int n;
	ll k;
	cin >> n >> k;
	ll x = 1ll;
	for(int i = 1; i <= n; i ++) x *= 2ll;
	for(int i = n; i >= 1; i --)
	{
		if(k == x / 2) {cout << i; return 0;}
		if(k > x / 2) k = x - k;
		x /= 2ll;
	}

	return 0;
}