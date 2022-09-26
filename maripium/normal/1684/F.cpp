#include <bits/stdc++.h>

using namespace std;

void troll_tle() {
	while (true);
}

void my_assert(bool b) {
	if (!b) troll_tle();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<int> A(N); for (int &a : A) cin >> a;
		map<int, int> last;
		vector<int> prv(N);
		vector<int> nxt(N);
		for (int i = 0; i < N; ++i) {
			if (last.count(A[i])) {
				prv[i] = last[A[i]];
				nxt[prv[i]] = i;
			} else {
				prv[i] = i;
			}
			last[A[i]] = i;
		}

		for (auto it : last) nxt[it.second] = it.second;
		vector<int> low(N); for (int i = 0; i < N; ++i) low[i] = i;
		for (int i = 0; i < M; ++i) {
			int l, r; cin >> l >> r;
			--l, --r;
			low[r] = min(low[r], l);
		}
		for (int i = N - 2; i >= 0; --i) low[i] = min(low[i], low[i + 1]);


		vector<array<int, 18>> par(N);
		for (int i = 0; i < N; ++i) par[i][0] = prv[i];
		for (int j = 1; j < 18; ++j) {
			for (int i = 0; i < N; ++i) {
				par[i][j] = par[par[i][j - 1]][j - 1];
			}
		}

		vector<pair<int, int>> segs;
		int l0 = N;
		int r0 = -1;
		for (int i = 0; i < N; ++i) {
			int v = i;
			for (int j = 17; j >= 0; --j) {
				if (par[v][j] >= low[i]) v = par[v][j];
			}
			if (v < i) {
				segs.push_back({v, i});
				if (v < prv[i]) {
					l0 = min(l0, nxt[v]);
					r0 = max(r0, prv[i]);
				}
			} 
		}

		if (segs.empty()) {
			cout << 0 << '\n';
			continue;
		}

		int ans = N;
		{
			// use all l
			int l = l0;
			int r = r0;
			for (auto it : segs) {
				l = min(l, it.first);
				r = max(r, it.first);
			}
			ans = min(ans, r - l + 1);
		}
		{
			// use all r
			int l = l0;
			int r = r0;
			for (auto it : segs) {
				l = min(l, it.second);
				r = max(r, it.second);
			}
			ans = min(ans, r - l + 1);
		}

		int ml = -1;
		vector<vector<int>> Rs(N);
		for (auto it : segs) {
			ml = max(ml, it.first);
			Rs[it.first].push_back(it.second);
		}
		multiset<int> st;
		for (auto it : segs) st.insert(it.second);
		for (int i = N - 1; i >= 0; --i) if (Rs[i].size()) {
 			for (int r : Rs[i]) st.erase(st.find(r));

 			int l = min({l0, i, ml});
 			int r = max({r0, i, ml});

 			if (st.size()) {
 				l = min(l, *st.begin());
 				r = max(r, *prev(st.end()));
 			}
 			ans = min(ans, r - l + 1);
		}
		cout << ans << '\n';
	}
	return 0;
}