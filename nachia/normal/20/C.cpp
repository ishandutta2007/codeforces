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
		vector<vector<pair<UL, ULL>>> E(N);
		rep(i, M) {
			UL u, v, w; cin >> u >> v >> w; u--; v--;
			E[u].push_back({ v, w });
			E[v].push_back({ u, w });
		}
		vector<ULL> D(N, (ULL)1e15);
		priority_queue<pair<ULL, UL>, vector<pair<ULL, UL>>, greater<pair<ULL, UL>>> Q;
		Q.push({ 0, 0 });
		while (Q.size()) {
			ULL w = Q.top().first;
			UL v = Q.top().second; Q.pop();
			if (D[v] < w) continue;
			D[v] = w;
			for (auto e : E[v]) {
				Q.push({ w + e.second, e.first });
			}
		}
		if (D[N - 1] == (ULL)1e15) { cout << -1 << endl; return; }
		UL p = N - 1;
		vector<UL> ans;
		while (p != 0) {
			ans.push_back(p);
			for (auto e : E[p]) {
				if (D[e.first] + e.second == D[p]) {
					p = e.first;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		cout << 1;
		rep(i, ans.size()) cout << " " << (ans[i] + 1);
		cout << endl;
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