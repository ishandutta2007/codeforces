#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {
public:

	UL N, M;
	UL K[3];
	vector<UL> E[5000];
	int F[5000] = {};
	pair<int, int> T[5000] = {};
	bool dp[5001][5001] = {};

	void Solve() {
		scanf("%d%d", &N, &M);
		rep(i, 3) scanf("%d", K + i);
		rep(i, M) {
			UL u, v; scanf("%d%d", &u, &v);
			u--; v--;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		queue<UL> Q;
		rep(i, N) {
			if (F[i]) continue;
			F[i] = i + 1;
			Q.push(i);
			while (Q.size()) {
				UL p = Q.front();
				Q.pop();
				if (F[p] < 0) T[-F[p] - 1].second++;
				if (F[p] > 0) T[F[p] - 1].first++;
				for (UL e : E[p]) {
					if (F[e] == F[p]) { printf("NO\n"); return; }
					if (F[e]) continue;
					F[e] = -F[p];
					Q.push(e);
				}
			}
		}
		dp[0][0] = true;
		rep(i, N) {
			for (UL j = T[i].first; j <= N; j++)
				if (dp[i][j - T[i].first]) dp[i + 1][j] = true;
			for (UL j = T[i].second; j <= N; j++)
				if (dp[i][j - T[i].second]) dp[i + 1][j] = true;
		}

		UL p = K[1];
		if (!dp[N][p]) { printf("NO\n"); return; }

		for (UL i = N - 1; i != ~0u; i--) {
			if (p >= T[i].first) if (dp[i][p - T[i].first]) {
				p -= T[i].first;
				T[i].first = 1;
				continue;
			}
			if (p >= T[i].second) if (dp[i][p - T[i].second]) {
				p -= T[i].second;
				T[i].first = -1;
				continue;
			}
		}

		string ans;
		rep(i, N) {
			if (T[abs(F[i]) - 1].first * F[i] > 0)
				ans.push_back('2');
			else {
				if (K[0]) { ans.push_back('1'); K[0]--; }
				else ans.push_back('3');
			}
		}
		printf("YES\n%s", ans.c_str());
	}
};

int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}