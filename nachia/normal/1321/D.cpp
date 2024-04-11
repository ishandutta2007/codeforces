#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, M; cin >> N >> M;
		vector<vector<UL>> E(N);
		vector<vector<UL>> RE(N);
		rep(i, M) {
			UL u, v; cin >> u >> v; u--; v--;
			E[u].push_back(v);
			RE[v].push_back(u);
		}
		UL K; cin >> K;
		vector<UL> P(K); rep(i, K) { cin >> P[i]; P[i]--; }

		vector<UL> D(N, -1);
		queue<pair<UL, UL>> Q; Q.push({ P.back(), 0 });
		while (Q.size()) {
			UL p = Q.front().first, d = Q.front().second; Q.pop();
			if (D[p] != -1) continue;
			D[p] = d;
			for (UL e : RE[p]) Q.push({ e, d + 1 });
		}
		UL l = 0, r = 0;
		rep(i, K - 1) {
			UL paths = 0;
			UL p = P[i], nx = P[i + 1];
			for (UL e : E[p]) if (D[p] == D[e] + 1) paths++;
			if (D[p] == D[nx] + 1) {
				if (paths > 1) r++;
			}
			else {
				l++; r++;
			}
		}
		cout << l << " " << r << endl;
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}