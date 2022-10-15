#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ll n, a, b;
	cin >> n >> a >> b;
	ll c = -1, d = -1;
	for (ll i = 0; i < 10000000; i++)
		if (i * a <= n && (n - i * a) % b == 0)
		{
			c = i;
			d = (n - i * a) / b;
			break;
		}
	if (c == -1)
		cout << "NO";
	else
		cout << "YES\n" << c << ' ' << d;
	return 0;
}