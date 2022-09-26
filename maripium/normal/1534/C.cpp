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
		auto get_par = [&](int v) {
			while (v != par[v]) {
				v = par[v] = par[par[v]];
			}
			return v;
		};
		auto merge = [&](int v, int u) {
			v = get_par(v);
			u = get_par(u);
			if (v == u) return 0;
			else {
				par[u] = v;
				return 1;
			}
		};
		int cc = N;
		for (int i = 0; i < N; ++i) cc -= merge(A[i], B[i]);
		int ans = 1;
		while (cc--) {
			ans += ans;
			if (ans >= 1000000007) ans -= 1000000007;
		}
		cout << ans << '\n';
	}
	return 0;
}