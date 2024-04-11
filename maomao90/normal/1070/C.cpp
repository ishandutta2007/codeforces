#include <bits/stdc++.h>
using namespace std;

#define MAX_P 1000000

typedef pair <int, int> ii;
typedef long long ll;

int n, k, m;
vector<int> start[MAX_P + 5], finish[MAX_P + 5];
ii cp[200005];
ll ans;

ll cores[MAX_P + 5], cost[MAX_P + 5];
void update(int c, int p, int i) {
	for (; i <= MAX_P; i += i&-i) {
		cores[i] += c;
		cost[i] += (ll) p * c;
	}
}
ll queryCores(int i) {
	ll res = 0;
	for (; i > 0; i -= i&-i) res += cores[i];
	return res;
}
ll queryCost(int i) {
	ll res = 0;
	for (; i > 0; i -= i&-i) res += cost[i];
	return res;
}

int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int i = 0; i < m; i++) {
		int l, r, c, p; scanf("%d%d%d%d", &l, &r, &c, &p);
		start[l].push_back(i);
		finish[r].push_back(i);
		cp[i] = ii(c, p);
	}
	for (int i = 1; i <= n; i++) {
		for (int j : start[i]) {
			int c, p; tie(c, p) = cp[j];
			update(c, p, p);
		}
		if (queryCores(MAX_P) <= k) {
			ans += queryCost(MAX_P);
		} else {
			int maxp = -1;
			int lo = 1, hi = MAX_P, mid;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (queryCores(mid) >= k) {
					hi = mid - 1;
					maxp = mid;
				} else {
					lo = mid + 1;
				}
			}
			ll curcost = queryCost(maxp);
			int extra = queryCores(maxp) - k;
			curcost -= (ll) extra * maxp;
			ans += curcost;
		}
		for (int j : finish[i]) {
			int c, p; tie(c, p) = cp[j];
			update(-c, p, p);
		}
	}
	printf("%lld\n", ans);
	return 0;
}