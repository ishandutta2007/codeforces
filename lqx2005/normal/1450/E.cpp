#include<bits/stdc++.h>

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define forgp(u, g, v) for(int iu = 0, v; iu < (int)g[u].size() && (v = g[u][iu], 1); iu++)
#define mp make_pair
#define siz(v) (int)(v).size()
#define x first
#define y second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef double db;
const int inf = 0x3f3f3f3f, N = 200 + 10;
int n, m, f[N][N], e[N][N];
int ind[N], dis[N], vis[N], cnt[N];

void adde(int u, int v, int w) {
	f[u][v] = max(f[u][v], w);
	e[u][v] = 1;
}

int Floyd() {
	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				if(f[i][j] < f[i][k] + f[k][j]) {
					f[i][j] = f[i][k] + f[k][j];
				}
			}
		}
	}
	rep(k, 1, n) if(f[k][k] > 0) return 0;
	return 1;
}

int main() {
	scanf("%d%d", &n, &m);
	memset(f, 0xc0, sizeof(f));
	rep(i, 1, n) f[i][i] = 0;
	rep(i, 1, m) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(w) adde(u, v, 1), adde(v, u, -1);
		else adde(v, u, -1), adde(u, v, -1);
	}
	if(!Floyd()) return printf("NO\n"), 0;
	rep(u, 1, n) {
		rep(v, 1, n) {
			if(!e[u][v]) continue;
			if(f[1][u] == f[1][v]) return printf("NO\n"), 0;
		}
	}
	int ans = -inf, s = -1;
	rep(u, 1, n) {
		int mn = inf;
		rep(v, 1, n) mn = min(mn, f[u][v]);
		if(ans < - mn) ans = - mn, s = u;
	}
	printf("YES\n%d\n", ans);
	int mn = inf;
	rep(i, 1, n) mn = min(mn, f[s][i]);
	rep(i, 1, n) {
		printf("%d ", f[s][i] - mn);
	}
	printf("\n");
	return 0;
}