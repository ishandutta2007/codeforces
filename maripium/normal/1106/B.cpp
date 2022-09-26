#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, q;
int a[N], cost[N];
set<pair<int,int>> s;

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", cost + i);
		s.insert(make_pair(cost[i], i));
	}
	while (q--) {
		int t, d;
		scanf("%d %d", &t, &d);
		if (a[t] > d) {
			printf("%lld\n", (long long) cost[t] * d);
			a[t] -= d;
		} else {
			long long ans = 1LL * cost[t] * a[t];
			d -= a[t];
			a[t] = 0;
			s.erase(make_pair(cost[t], t));
			while (d && s.size()) {
				int id = s.begin()->second;
				if (a[id] > d) {
					ans += (long long) d * cost[id];
					a[id] -= d;
					d = 0;
				} else {
					ans += (long long) a[id] * cost[id];
					d -= a[id];
					a[id] = 0;
					s.erase(s.begin());
				}
			}
			if (d) {
				ans = 0;
			}
			printf("%lld\n", ans);
		}
	}
}