#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}
void read(LL &a) {scanf("%lld", &a);}

const int N = 2e5 + 5;

int n;
vector <int> E[N], tot;

bool dfs(int x, int fa = -1) {
	int son = 0;
	for (auto v : E[x]) if (v != fa) if (dfs(v, x)) son ++;
	if (!son) return 1;
	else tot.push_back(son);
	return 0;
}

void work() {
	read(n);
	for (int i = 1; i <= n; i++) E[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	tot.clear();
	dfs(1);
	int ans = 1;
	for (auto i : tot) {
		ans += i - 1;
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	read(T);
	while (T--) work();
}