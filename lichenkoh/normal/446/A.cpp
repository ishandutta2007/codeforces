#include <iostream>
using namespace std;
#define ll long
int main()
{
	ll n;
	cin >> n;
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll *f = new ll[n];
	ll *g = new ll[n];
	for (ll i = 0; i < n; i++) {
		f[i] = 1;
		g[i] = 1;
	}
	for (ll x = 0; x < n; x++) {
		if (x >= 1 && a[x] > a[x-1])
		{
			f[x] = max(f[x], f[x-1] + 1);
		}
	}
	for (ll x = 0; x < n; x++) {
		if (x >= 1 && a[x] > a[x-1])
		{
			g[x] = max(g[x], g[x-1] + 1);
		}
		if (x >= 2 && a[x] >= (a[x-2] + 2))
		{
			g[x] = max(g[x], f[x-2] + 2);
		}
	}
	ll ans = 0;
	for (ll x = 0; x < n; x++) {
		ans = max(ans, g[x]);
		ans = max(ans, f[x] + 1);
	}
	cout << min(ans, n) << endl;
}