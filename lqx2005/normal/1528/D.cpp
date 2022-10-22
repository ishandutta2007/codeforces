#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sit set<int>::iterator

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> par;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 600 + 10, oo = 0x3f3f3f3f;
int n, m;
int e[N][N];
int dis[N], used[N], ans[N][N], tmp[N];
void BFS(int s) {
	memset(dis, 0x3f, sizeof(dis));
	memset(used, 0, sizeof(used));
	dis[s] = 0;
	for(int i = 0; i < n; i++) {
		int u = -1;
		for(int j = 0; j < n; j++) if(!used[j] && (u == -1 || dis[u] > dis[j])) u = j;
		used[u] = 1;
		int p = 0;
		for(int j = 1; j < n; j++) if(e[u][p] > e[u][j]) p = j;
		memset(tmp, 0x3f, sizeof(tmp));
		tmp[p] = e[u][p];
		for(int j = (p + 1) % n; j != p; j = (j + 1) % n) tmp[j]  = min(e[u][j], tmp[(j - 1 + n) % n] + 1);
		for(int j = 0; j < n; j++) dis[(j + dis[u]) % n] = min(tmp[j] + dis[u], dis[(j + dis[u]) % n]);
	}
	return;
}
int main() {
	scanf("%d%d", &n, &m);
	memset(e, 0x3f, sizeof(e));
	for(int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		scanf("%d", &e[a][b]);
	}
	for(int i = 0; i < n; i++) {
		BFS(i);
		for(int j = 0; j < n; j++) ans[i][j] = dis[j];
	}
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) printf("%d%c", ans[i][j], " \n"[j == n - 1]);
	return 0;
}