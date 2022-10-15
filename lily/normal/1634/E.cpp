#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
const int N = 1e6 + 5;
const int M = 1e6 + 5;
/* comment : directed */
int n, e, cur[N]/*, deg[N]*/;
vector<int>E[N];
int id[M], vis[M];
//stack<int>stk;
void dfs(int u) {
	for (cur[u]; cur[u] < E[u].size(); cur[u]++) {
		int i = cur[u];
		if (vis[abs(E[u][i])]) continue;
		int v = id[abs(E[u][i])] ^ u;
		vis[abs(E[u][i])] = E[u][i] > 0 ? 1 : -1; dfs(v);
//		stk.push(E[u][i]);
} 
} void add(int u, int v) {
	id[++e] = u ^ v; // s = u
	E[u].push_back(e); E[v].push_back(-e);
/* 	E[u].push_back(e); deg[v]++; */
}  bool valid() {
	for (int i = 1; i <= n; i++)
		if (E[i].size() & 1) return 0;
/*		if (E[i].size() != deg[i]) return 0;*/
	return 1;
} // call dfs(i) for all when disconnected 

int m;

int main() {
	read(m);
	unordered_map <int, int> rel;
	vector <vector <int>> a;
	for (int i = 1; i <= m; i++) {
		int k; read(k);
		vector <int> tmp;
		for (int j = 0; j < k; j++) {
			int x; read(x);
			tmp.push_back(x);
			rel[x] = 1;
		}
		a.push_back(move(tmp));
	}
	n = m;
	for (auto &[k, v] : rel) {
		v = ++n;
	}
	for (int i = 0; i < m; i++) {
		for (auto j : a[i]) {
			add(i + 1, rel[j]);
		}
	}
	if (!valid()) {puts("NO"); return 0;}
	for (int i = 1; i <= m; i++) dfs(i);
	puts ("YES");
	for (int i = 1; i <= m; i++) {
		for (auto v : E[i]) {
			putchar (vis[v] > 0 ? 'L' : 'R');
		}
		putchar ('\n');
	}


}