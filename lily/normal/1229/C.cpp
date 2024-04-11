#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define read(a) scanf("%d", &a)

#define N 111111

int n, m, Q;

vector <int> E[N];
vector <int> nxt[N];

LL ans = 0;

int main() {
	read(n); read(m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		read(u); read(v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	read(Q);
	for (int i = 1; i <= n; i++) {
		for (auto &j : E[i]) {
			if (j > i) nxt[i].push_back(j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto &j : nxt[i]) {
			ans += nxt[j].size(); 
		}
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= Q; i++) {
		int x; read(x);
		ans -= (E[x].size() - nxt[x].size()) * nxt[x].size();
		for (auto &j : nxt[x]) {
			ans -= nxt[j].size();
			nxt[j].push_back(x);
			ans += (E[j].size() - nxt[j].size());
		}
		nxt[x].clear();
		printf("%lld\n", ans);
	}
}