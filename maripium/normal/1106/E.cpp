#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m, k;
vector<pair<int,int>> add[N], del[N];
multiset<pair<int,int>> ms;
pair<int,int> nxt[N];
long long f[N][205];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; ++i) {
		int s, t, d, w;
		scanf("%d %d %d %d", &s, &t, &d, &w);
		add[s].push_back(make_pair(w, d));
		del[t].push_back(make_pair(w, d));
	}
	for (int i = 0; i <= n; ++i) {
		for (auto v : add[i]) {
			ms.insert(v);
		}
		if (ms.empty()) {
			nxt[i] = make_pair(i + 1, 0);
		} else {
			auto v = ms.rbegin();
			nxt[i] = make_pair(v->second + 1, v->first);
		}
		for (auto v : del[i]) {
			ms.erase(ms.find(v));
		}
	}
	for (int i = 0; i <= n + 1; ++i) {
		for (int j = 0; j <= m; ++j) {
			f[i][j] = (long long) 1e18;
		}
	}
	f[0][0] = 0;
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			f[nxt[i].first][j] = min(f[nxt[i].first][j], f[i][j] + nxt[i].second);
			if (j < m) {
				f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j]);
			}
		}
	}
	printf("%lld\n", *min_element(f[n + 1], f[n + 1] + m + 1));
}