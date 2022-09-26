#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> P(N); for (int &p : P) cin >> p, --p;

		vector<int> Q;
		vector<bool> used(N);
		Q.push_back(0);
		used[0] = true;
		vector<int> par(N);

		auto get_par = [&](int v) {
			while (v != par[v]) {
				v = par[v] = par[par[v]];
			}
			return v;
		};

		auto merge = [&](int v, int u) {
			v = get_par(v);
			u = get_par(u);
			if (v != u) {
				par[u] = v;
				return true;
			}
			return false;
		};

		auto solve = [&] {
			iota(par.begin(), par.end(), 0);
			for (int i = 0; i < N; ++i) merge(i, P[i]);

			vector<bool> to_left(N - 1);
			vector<bool> to_right(N - 1);
			vector<bool> in_left(N - 2);
			vector<bool> in_right(N - 2);
			vector<bool> single(N);
			vector<int> cnt_left(N);
			vector<int> cnt_right(N);
			for (int z = 0; z + 1 < int(Q.size()); ++z) {
				int st = Q[z];
				int en = P[Q[z + 1]];

				if (st < en) {
					for (int i = st; i < en; ++i) {
						if (to_right[i]) return false;
						to_right[i] = true;
					}

					for (int i = st + 1; i < en; ++i) {
						if (in_right[i - 1]) return false;
						in_left[i - 1] = true;
					}
					cnt_left[st] ++;
					cnt_right[en] ++;
				} else if (st > en) {
					for (int i = st - 1; i >= en; --i) {
						if (to_left[i]) return false;
						to_left[i] = true;
					}
					for (int i = st - 1; i > en; --i) {
						if (in_left[i - 1]) return false;
						in_right[i - 1] = true;
					}
					cnt_right[st]++;
					cnt_left[en]++;
				} else {
					single[st] = true;
				}
			}

			for (int i = 0; i + 1 < N; ++i) {
				if (to_left[i] || to_right[i]) {
					if (single[i] || single[i + 1]) return false;
					if (!merge(i, i + 1)) return false;
				}
			}

			for (int i = 0; i + 1 < N; ++i) {
				if (single[i] || single[i + 1] || cnt_left[i + 1] == 2 || cnt_right[i] == 2) continue;
				merge(i, i + 1);
			}
			for (int i = 0; i < N; ++i) if (merge(0, i)) return false;
			return true;
		};

		for (int z = 0; z < N - 1; ++z) {
			for (int nxt = 0; nxt < N; ++nxt) {
				if (used[nxt]) continue;
				Q.push_back(nxt);
				used[nxt] = true;
				if (solve()) {
					break;
				} else {
					Q.pop_back();
					used[nxt] = false;
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			cout << Q[i] + 1 << " \n"[i == N - 1];
		}
	}
	return 0;
}