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
		UL M; cin >> M;
		vector<vector<UL>> E(N);
		vector<UL> Cat(N);
		rep(i, N) cin >> Cat[i];
		rep(i, N - 1) {
			UL x, y; cin >> x >> y; x--; y--;
			E[x].push_back(y);
			E[y].push_back(x);
		}
		UL ans = 0;
		vector<UL> F(N);
		queue<pair<UL, UL>> Q;
		Q.push({ 0, 0 });
		while (Q.size()) {
			UL p = Q.front().second;
			UL d = Q.front().first; Q.pop();
			if (F[p]) continue;
			F[p] = 1;
			if (Cat[p]) d++; else d = 0;
			if (d > M) continue;
			if (p != 0) if (E[p].size() == 1) ans++;
			for (UL e : E[p]) Q.push({ d, e });
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