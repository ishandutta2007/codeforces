#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 10;
const int mod = 1e9 + 7;
 
vector<int> g[N][10];
vector<int> wait[N];
int dis[N];
 
inline void adde (int u, int v, int w) { g[u][w].push_back(v); }
 
int _k, ww;
inline void add (int u, int v, int & k, int w) {
	if (w < 10) { adde(u, v, w); adde(v, u, w); return; }
	adde(++k, v, w % 10); for (ww = w / 10; ww >= 10; ww /= 10, k ++) adde(k + 1, k, ww % 10); adde(u, k, ww);
	adde(++k, u, w % 10); for (ww = w / 10; ww >= 10; ww /= 10, k ++) adde(k + 1, k, ww % 10); adde(v, k, ww);
}
 
int main (void) {
	int n, m;
	scanf("%d%d", &n, &m);
	int k = n;
	for (int i = 1, u, v; i <= m; i++) {
		scanf("%d%d", &u, &v);
		add(u, v, k, i);
	}
 
 
 
	memset(dis, -1, sizeof(dis));
	dis[1] = 0;
	wait[0].push_back(1);
	int  cnt = 0;
	for (int i = 0; i <= cnt; i++) {
		for (int j = 0; j < 10; j++) {
			++ cnt;
			for (int & u : wait[i]) {
				for (int & v : g[u][j]) {
					if (~dis[v]) continue;
					dis[v] = (10ll * dis[u] + j) % mod;
					wait[cnt].push_back(v);
				}
			}
			if (!wait[cnt].size()) -- cnt;
		}
	}
	for (int i = 2; i <= n; i++) {
		printf("%d\n", dis[i]);
	}
}