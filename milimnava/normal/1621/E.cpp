#include <bits/stdc++.h>
using namespace std;

int sum[400055], minn[400055], tmp[400055];

void update(int u) {
	sum[u] = sum[u << 1] + sum[u << 1 | 1];
	minn[u] = min(minn[u << 1 | 1], minn[u << 1] + sum[u << 1 | 1]);
}

void modify(int u, int l, int r, int x, int y) {
	if (l == r) {
		sum[u] = minn[u] = y;
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= x) modify(u << 1, l, mid, x, y);
	else modify(u << 1 | 1, mid + 1, r, x, y);
	update(u);
}

void add(int x, int y) {
	tmp[x] += y;
	modify(1, 1, 100000, x, tmp[x]);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		vector<int> a(n + 1, 0), b(1, 0), bel(1, 0);
		for (int i = 1; i <= n; i++) cin >> a[i];
		vector<long long> sum(m + 1, 0);
		vector<int> cnt(m + 1, 0);
		int tot = 0;
		for (int i = 1; i <= m; i++) {
			int k; cin >> k; cnt[i] = k;
			for (int j = 1; j <= k; j++) {
				int x; cin >> x;
				++tot;
				bel.push_back(i);
				b.push_back(x);
				sum[i] += x;
			}
		}
		for (int i = 1; i <= n; i++) add(a[i], 1);
		for (int i = 1; i <= m; i++) add((sum[i] + cnt[i] - 1) / cnt[i], -1);
		for (int i = 1; i <= tot; i++) {
			int v1 = (sum[bel[i]] + cnt[bel[i]] - 1) / cnt[bel[i]];
			int v2 = (sum[bel[i]] - b[i] + cnt[bel[i]] - 2) / (cnt[bel[i]] - 1);
			add(v1, 1); add(v2, -1);
			if (minn[1] < 0) cout << 0;
			else cout << 1;
			add(v1, -1); add(v2, 1);
		}
		cout << endl;
		for (int i = 1; i <= n; i++) add(a[i], -1);
		for (int i = 1; i <= m; i++) add((sum[i] + cnt[i] - 1) / cnt[i], 1);
	}
	return 0;
}