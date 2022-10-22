#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

int t;
int n, m;
ii ab[100005];
int a[100005];
ll sum[100005];
ll ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			int b; scanf("%d%d", &a[i], &b);
			ab[i] = ii(a[i], b);
		}
		sort(a, a + m, greater<int>());
		for (int i = 0; i < m; i++) {
			sum[i] = a[i];
			if (i > 0) sum[i] += sum[i - 1];
		}
		ans = 0;
		if (n <= m) ans = sum[n - 1];
		for (int i = 0; i < m; i++) {
			int b = ab[i].second;
			int bigger = upper_bound(a, a + m, b, greater<int>()) - a - 1;
			bigger = min(n - 1, bigger);
			ll cur = 0;
			if (bigger != -1) {
				cur += sum[bigger];
			}
			if (ab[i].first >= b) {
				cur += (ll) b * (n - bigger - 1);
			} else {
				cur += (ll) b * (n - bigger - 2) + ab[i].first;
			}
			ans = max(ans, cur);
		}
		printf("%lld\n", ans);
	}
	return 0;
}