#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<vector<UL>> E(N);
		rep(i, N - 1) {
			UL u, v; cin >> u >> v; u--; v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		vector<UL> F(N);
		UL s; rep(i, N) if (E[i].size() == 1) s = i;
		queue<UL> Q; F[s] = 1; Q.push(s);
		while (Q.size()) {
			UL p = Q.front(); Q.pop();
			for (UL e : E[p]) {
				if (F[e]) continue;
				F[e] = 3 - F[p];
				Q.push(e);
			}
		}
		bool dual = false;
		rep(i, N) if (E[i].size() == 1) if (F[i] == 2) dual = true;
		UL ans = (dual ? 3 : 1);
		cout << ans << " ";
		ans = N - 1;
		rep(i, N) if (E[i].size() != 1) {
			UL n = 0; for (UL e : E[i]) if (E[e].size() == 1) n++;
			n = max(n, 1u) - 1;
			ans -= n;
		}
		cout << ans << endl;
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