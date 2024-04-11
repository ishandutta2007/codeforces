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
const int N = 500 + 10;

int t, n, m, a[N][N], mx[N], vis[N];
int ok(char w){return w == '.' || w == '*';}

int main() {
	scanf("%d", &t);
	rep(amo, 1, t) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) {
			rep(j, 1, m) {
				char w;
				while(!ok(w = getchar()));
				a[i][j] = (w == '*');
			}
		}
		int ans = 0;
		rep(i, 1, m) mx[i] = 0;
		rep(i, 1, n) {
			rep(j, 1, m) {
				if(!a[i][j]) mx[j] = i;
			}
			rep(j, 1, m) {
				rep(k, 1, m) {
					vis[k] = (i - mx[k]) + abs(j - k);
				}
				int mn = vis[j];
				rep(k, 1, min(vis[j], min(j, m - j + 1))) {
					mn = min(mn, vis[j - k + 1]);
					mn = min(mn, vis[j + k - 1]);
					if(mn >= k) ans++;
					else break;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}