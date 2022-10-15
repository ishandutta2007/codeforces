#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N 1011

int n;
vector <int> E[N];
int V[2], rt, siz[N], dep[N];

void dfs(int x, int fa) {
	siz[x] = 1;
	for (auto v : E[x]) if(v != fa) {
		dep[v] = dep[x] + 1;
		dfs(v, x);
		siz[x] += siz[v];
	}
}

bool dfscut(int x, int fa) {
	if (x == V[0]) return true;
	if (x == V[1]) return true;
	vector <int> cut;
	for (auto v : E[x]) if (v != fa) {
		if (dfscut(v, x)) cut.push_back(v);
	}
	if (x == rt) for (auto v : cut) {
		for (int i = 0; i < (int)E[x].size(); i++) {
			if (E[x][i] == v) {
				swap(E[x][i], E[x].back());
				E[x].pop_back();
				break;
			}
		}
	}
	else return !!cut.size();
		return false;
}

int main() {
	read(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		read(u); read(v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	rt = 1;
	while (true) {
		for (int i = 1; i <= n; i++) siz[i] = 0, dep[i] = 0;
		dep[rt] = 1;
		dfs(rt, -1);
		if (siz[rt] == 1) break;
		int mx = rt;
		for (int i = 1; i <= n; i++) if (dep[i] > dep[mx]) mx =i;
		rt = mx;
		dep[mx] = 1;
		dfs(mx, -1);
		for (int i = 1; i <= n; i++) if (dep[i] > dep[mx]) mx = i;
		printf("? %d %d\n", rt, mx);
		V[0] = rt, V[1] = mx;
		fflush(stdout);
		int ans;
		scanf("%d", &ans);
		rt = ans;
		if (ans == V[0] || ans == V[1]) break;
		dfscut(rt, -1);
	}
	printf("! %d\n", rt);
	fflush(stdout);
}