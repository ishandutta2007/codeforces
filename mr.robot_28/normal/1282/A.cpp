#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
#define int long long
const int  CONST = 998244353;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int a, b, c, r;
		cin >> a >> b >> c >> r;
		if(a > b)
		{
			swap(a, b);
		}
		if(c + r < a || c - r > b)
		{
			cout << b - a << "\n";
		}
		else if(c + r <= b && c - r <= a)
		{
			cout << b - a - (c + r - a) << "\n";
		}
		else if(c + r <= b && c - r >= a)
		{
			cout << b - a - 2 * r << "\n";
		}
		else if(c - r <= a && c + r >= b)
		{
			cout << 0 << "\n";
		}
		else if(c - r <= a && c + r <= b)
		{
			cout << b - a - (c + r - a) << "\n";
		}
		else if(c - r <= b && c + r >= b)
		{
			cout << b - a - (b - (c - r)) << "\n";
		}
		else 
		{
			cout << b - a - 2 * r << "\n";
		}
	}
	return 0;
}