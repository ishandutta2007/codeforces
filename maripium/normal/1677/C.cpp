#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> A(N); for (int &a : A) cin >> a, --a;
		vector<int> B(N); for (int &a : B) cin >> a, --a;
		vector<int> par(N); iota(par.begin(), par.end(), 0);
		vector<int> sz(N, 1);

		auto get_par = [&](int v) {
			while (v != par[v]) {
				v = par[v] = par[par[v]];
			}
			return v;
		};

		auto merge = [&](int v, int u) {
			v = get_par(v);
			u = get_par(u);
			if (v == u) {
			} else {
				par[u] = v;
				sz[v] += sz[u];
			}
		};

		for (int i = 0; i < N; ++i) merge(A[i], B[i]);
		int c = 0;
		for (int i = 0; i < N; ++i) if (get_par(i) == i) c += sz[i] / 2;
		int64_t ans = 0;
		for (int i = 0; i < c; ++i) {
			ans -= i;
			ans += N - 1 - i;
		}
		cout << ans*2 << '\n';
	}
	return 0;
}