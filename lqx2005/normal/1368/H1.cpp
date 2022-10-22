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
int n, m, q;
int l[N], r[N], u[N], d[N];
int f[N][2]; 
int calc(int n, int m, int *l, int *r, int *u, int *d) {
	memset(f, 0, sizeof(f));
	rep(i, 1, m) f[1][u[i] ^ 1]++;
	f[1][l[1] ^ 1]++, f[1][r[1] ^ 1]++;
	rep(i, 2, n) {
		rep(j, 0, 1) {
			int s = (l[i] != j) + (r[i] != j);
			f[i][j] = min(f[i - 1][j], f[i - 1][j ^ 1] + m) + s;
		}
	}
	rep(i, 1, m) f[n][d[i] ^ 1]++;
	return min(f[n][0], f[n][1]);
}

int ok(char x) { return x == 'R' || x == 'B'; }
void red(int n, int *ch) {
	rep(i, 1, n) {
		char x;
		while(!ok(x = getchar()));
		ch[i] = x == 'B';
	}
	return;
}
int main() {
	scanf("%d%d%d", &n, &m, &q);
	red(n, l), red(n, r), red(m, u), red(m, d);
	int ans = min(calc(n, m, l, r, u, d), calc(m, n, u, d, l, r));
	printf("%d\n", ans);
	return 0;
}