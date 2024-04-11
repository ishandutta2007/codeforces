#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		string S; cin >> S;
		vector<int> par(2 * N); iota(par.begin(), par.end(), 0);
		auto get_par = [&](int v) {
			while (v != par[v]) {
				v = par[v] = par[par[v]];
			}
			return v;
		};
		auto merge = [&](int v, int u) {
			v = get_par(v);
			u = get_par(u);
			par[u] = v;
		};

		vector<int> st;
		for (int i = 0; i < 2 * N; ++i) {
			if (S[i] == '(') {
				st.push_back(i);
			} else {
				merge(st.back(), i);
				st.pop_back();
			}
		}
		for (int i = 0; i + 1 < 2 * N; ++i) {
			if (S[i] != S[i + 1]) merge(i, i + 1);
		}
		int ans = 0;
		for (int i = 0; i < 2 * N; ++i) if (get_par(i) == i) ans++;
		cout << ans << '\n';
	}
	return 0;
}