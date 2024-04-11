# include <iostream>
# include <cstdio>
# include <vector>
using namespace std;

const int Mod = 1000000007;

bool flag = true;
bool v[100010];
vector<int> g[100010];
vector<int> G[100010];
int a[100010];
int root = 0;
void DFS(int u,int fa) {
	v[u] = true;
	for(size_t k = 0; k < g[u].size(); ++k) {
		int w = g[u][k], d = G[u][k];
		if (w == fa) continue;
		//cout << "(" << u << ',' << w << ")" << endl;
		if (!v[w]) {
			if (u == root)
				a[w] = d;
			else
				a[w] = d ? a[u] : 1 - a[u];
			DFS(w, u);
		} else {
			if(w == root) {
				if(a[u] != d) flag = false;
			} else {
				if(a[u] + a[w] + d == 0 || a[u] + a[w] + d == 2) 
					flag = false;
			}
		}
	}
}

int main() {
	int n, m, x, y, w;
	scanf("%d%d", &n, &m);
	for(int k = 0; k < m; ++k) {
		scanf("%d%d%d", &x, &y, &w);
		g[x].push_back(y);
		G[x].push_back(w);
		g[y].push_back(x);
		G[y].push_back(w);
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i)
		if(!v[i]) a[i] = 1, root = i, DFS(i, i), ++cnt;
	if(!flag) { cout << 0 << endl; return 0; }
	int ans = 1;
	while(--cnt) ans = (ans << 1) % Mod;
	cout << ans << endl;
}