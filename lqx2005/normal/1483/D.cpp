#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef pair<int, int> P;
typedef long long LL;
typedef unsigned long long uLL;
typedef double db;
const int N = 600 + 10, M = N * N;
int n, m, q;
int u[M], v[M];
LL f[N][N], h[N][N], w[M];
vector<P> g[N];
int main() {
	scanf("%d%d", &n, &m);
	memset(f, 0x3f, sizeof(f)), memset(h, 0xc0, sizeof(h)); 
	rep(i, 1, n) f[i][i] = 0;
	rep(i, 1, m) {
		scanf("%d%d%lld", &u[i], &v[i], &w[i]);
		ckmin(f[u[i]][v[i]], w[i]), ckmin(f[v[i]][u[i]], w[i]);
	}
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				ckmin(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	scanf("%d", &q);
	rep(i, 1, q) {
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		g[u].push_back(mp(v, l));
		g[v].push_back(mp(u, l));
	}
	for(int u = 1; u <= n; u++) {
		for(auto p : g[u]) {
			for(int v = 1; v <= n; v++) ckmax(h[u][v], p.y - f[p.x][v]);
		}
	}
	int ans = 0;
	rep(i, 1, m) {
		rep(k, 1, n) {
			if(w[i]	+ f[v[i]][k] <= h[k][u[i]]) {
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}