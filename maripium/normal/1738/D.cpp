#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		vector<int> B(N); for (int &b : B) cin >> b, --b;

		map<int, int> last;

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
			par[u] = v;
		};

		for (int i = 0; i < N; ++i) {
			if (last.count(B[i])) {
				merge(last[B[i]], i);
			} else {
				last[B[i]] = i;
			}
		}

		vector<vector<int>> comp(N);
		for (int i = 0; i < N; ++i) comp[get_par(i)].push_back(i);

		vector<int> prv(N, -1);
		vector<int> nxt(N, -1);
		for (int i = 0; i < N; ++i) {
			if (0 <= B[i] && B[i] < N) {
				int st = get_par(B[i]);
				int en = get_par(i);
				nxt[st] = en;
				prv[en] = st;
			}
		}

		int st = 0;
		for (int i = 0; i < N; ++i) if (comp[i].size() && prv[i] == -1) st = i;

		vector<int> A;
		while (st != -1) {
			int tail = -1;
			for (int v : comp[st]) if (last.count(v)) tail = v;
			if (tail == -1) tail = comp[st].back();
			for (int v : comp[st]) if (v != tail) A.push_back(v);
			A.push_back(tail);
			st = nxt[st];
		}

		for (int i = 0; i < N; ++i) if (comp[i].size() && prv[i] == -1) st = i;

		int K;
		if (B[A[0]] == -1) {
			K = N;
			for (int i = 0; st != -1; ++i, st = nxt[st]) {
				if (i % 2 == 0) {
					for (int v : comp[st]) K = min(K, v - 1);
				}
			}
		} else {
			K = -1;
			for (int i = 0; st != -1; ++i, st = nxt[st]) {
				if (i % 2 == 0) {
					for (int v : comp[st]) K = max(K, v);
				}
			}
		}
		cout << K + 1 << '\n';
		for (int a : A) cout << a + 1 << ' '; cout << '\n';
	}
	return 0;
}