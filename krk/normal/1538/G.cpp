#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
ll x, y, a, b;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%I64d %I64d %I64d %I64d", &x, &y, &a, &b);
		if (a == b) printf("%I64d\n", min(x / a, y / b));
		else {
			if (a < b) swap(a, b);
			ll lef = 0, rig = 1000000007;
			while (lef <= rig) {
				ll t = lef + rig >> 1ll;
				ll L = t * a - y;
				ll R = x - t * b;
				bool ok = false;
				if (R >= 0) {
					ll k = min(t, R / (a - b));
					ok = L <= (a - b) * k;
				}
				if (ok) lef = t + 1ll;
				else rig = t - 1ll;
			}
			printf("%I64d\n", rig);
		}
	}
    return 0;
}