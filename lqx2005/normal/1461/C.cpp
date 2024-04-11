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
const int N = 1e5 + 10;

int t, n, m, a[N];
db s[N];
int main() {
	scanf("%d", &t);
	rep(amo, 1, t) {
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%d", &a[i]), s[i] = 1;
		rep(i, 1, m) {
			int r;
			db q;
			scanf("%d%lf", &r, &q);
			s[r] *= (1 - q);
		}
		int p;
		for(p = n; p >= 1; p--) if(a[p] != p) break;
		if(p == 0) {
			printf("1.0000000000\n");
			continue;		
		}
		db ans = 1;
		rep(i, p, n) ans *= s[i];
		printf("%.10lf\n", 1 - ans);
	}
	return 0;
}