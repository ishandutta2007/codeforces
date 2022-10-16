// Skyqwq
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define int long long

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 5;

int n, b[N], t, ans = 2e9;

PII a[N], d[N];

vector<int> g, s;

signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", b + i), a[i] = mp(b[i], b[i]);
	t = n;
	while (t) {
		bool o1 = 1, o2 = 1; int c = 0;
		for (int i = 1; i <= t; i++) {
			if (a[i].fi & 1) o2 = 0, c++;
			if (a[i].fi % 2 == 0) o1 = 0;
		}
		if (o1) {
			if (s.size() < ans)
				ans = s.size(), g = s;
			break;
		} if (o2) {
			for (int i = 1; i <= t; i++)
				a[i].fi /= 2;
		} else {
			if (t - c + s.size() < ans) {
				ans = t - c + s.size();
				g = s;
				for (int i = 1; i <= t; i++)
					if (a[i].fi % 2 == 0) g.pb(a[i].se);
			}
			int len = 0;
			for (int i = 1; i <= t; i++) {
				if (a[i].fi & 1) {
					s.pb(a[i].se);
				} else {
					d[++len] = a[i];
				}
			}
			for (int i = 1; i <= len; i++) a[i] = d[i];
			t = len;
		}
	}
	printf("%lld\n", ans);
	for (int v: g)
		printf("%lld ", v);
	return 0;
}