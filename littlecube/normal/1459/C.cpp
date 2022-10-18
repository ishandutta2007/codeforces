#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll _gcd(ll a, ll b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return abs(a);
}

int main()
{
	unsigned ll n, m, a[200005], b, gcd;
	cin >> n >> m;
	if (n == 1)
	{
		cin >> a[0];
		for (int i = 0; i < m; i++)
		{
			cin >> b;
			cout << a[0] + b << "  ";
		}
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	gcd = a[1] - a[0];
	for (int j = 2; j < n; j++)
	{
		gcd = _gcd(a[j] - a[0], gcd);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> b;
		cout << _gcd(gcd, a[0] + b) << " \n"[i == m - 1];
	}
}