#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef long long ll;

ll f, T, t0;
ll a1, t1, p1;
ll a2, t2, p2;
ll res = -1;

ll Div(ll x, ll y) { return x / y + ll(bool(x % y > 0)); }

ll Solve2(ll f, ll T, ll t0, ll a1, ll t1, ll p1)
{
	if (f * t0 <= T) return 0;
	if (t0 <= t1) return -1;
	ll a = f * t0 - T;
	ll b = t0 - t1;
	ll x = Div(a, b);
	if (x > f) return -1;
	return Div(x, a1) * p1;
}

int main()
{
	cin >> f >> T >> t0;
	cin >> a1 >> t1 >> p1;
	cin >> a2 >> t2 >> p2;
	if (t0 <= t1 && t0 <= t2) {
		if (f * t0 <= T) printf("0\n");
		else printf("-1\n");
		return 0;
	}
	if (t1 < t2) { swap(a1, a2); swap(t1, t2); swap(p1, p2); }
	for (ll y = 0; y <= f && y * t2 <= T; y++) {
		ll cand = Div(y, a2) * p2;
		ll got = Solve2(f - y, T - y * t2, t0, a1, t1, p1);
		if (got == -1) continue;
		cand += got;
		if (res == -1 || res > cand) res = cand;
	}
	cout << res << endl;
	return 0;
}