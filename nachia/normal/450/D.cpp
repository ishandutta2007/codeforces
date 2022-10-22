#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N, M, K; cin >> N >> M >> K;
		using Node = pair<pair<ULL, UL>, bool> ;
		priority_queue<Node, vector<Node>, greater<Node>> Q;
		vector<vector<pair<UL, UL>>> E(N);
		rep(i, M) {
			UL u, v, d; cin >> u >> v >> d; u--; v--;
			E[u].push_back({ v, d });
			E[v].push_back({ u, d });
		}
		rep(i, K) {
			UL v, d; cin >> v >> d; v--;
			Q.push({ { d, v }, true });
		}
		Q.push({ { 0, 0 }, false });
		vector<ULL> D(N, -1);
		UL ans = 0;
		while (Q.size()) {
			ULL d = Q.top().first.first;
			UL p = Q.top().first.second;
			bool train = Q.top().second;
			Q.pop();
			if (train) if (D[p] != -1) { ans++; }
			if (D[p] != -1) continue;
			D[p] = d;
			for (auto e : E[p]) {
				Q.push({ {d + e.second, e.first}, false });
			}
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