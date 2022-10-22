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

const int Maxn = 100005;

ll n, m, a, d;
ll t[Maxn];
ll res;

int main()
{
	scanf("%I64d %I64d %I64d %I64d", &n, &m, &a, &d);
	for (int i = 1; i <= m; i++)
		scanf("%I64d", &t[i]);
	ll p = d / a + 1;
	ll i = 1;
	ll j = 1;
	while (i <= n || j <= m)
		if (i <= n && j > m) {
			ll tk = (n - i) / p + 1;
			res += tk; i += p * tk;
		} else if (i <= n && a * i <= t[j]) {
			ll my = min(n, t[j] / a);
			if (i < my) {
				ll tk = (my - 1 - i) / p;
				res += tk; i += tk * p;
			}
			ll tim = a * i; res++;
			i += p;
			while (j <= m && t[j] <= tim + d) j++;
		} else {
			ll tim = t[j]; res++;
			ll lef = i, rig = n;
			while (lef <= rig) {
				ll mid = lef + rig >> 1;
				if (mid * a <= tim + d) lef = mid + 1;
				else rig = mid - 1;
			}
			i = lef;
			while (j <= m && t[j] <= tim + d) j++;
		}
	cout << res << endl;
	return 0;
}