#include<bits/stdc++.h>

using namespace std;

#define rep(x, L, R) for(int x = (L), _x = (R); x <= _x; x++)
#define per(x, R, L) for(int x = (R), _x = (L); x >= _x; x--)
#define x first
#define y second
#define mp make_pair
#define broken fprintf(stderr, "running on %s %d\n", __FUNCTION__, __LINE__)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define SZ(v) (int)(v).size()
#define ALL(x) (x).begin(), (x).end()

typedef pair<int, int> P;
typedef long long LL;
typedef double db;
const int N = 500 + 10;
int t, n, m;
int g[N][N];
int ok(char x) { return x == '.' || x == 'X'; }
void work() {
	scanf("%d%d", &n, &m);
	rep(i, 1, n) {
		rep(j, 1, m) {
			char w;
			while(!ok(w = getchar())); 
			g[i][j] = w == 'X';
		}
	}
	for(int i = 1; i <= n; i += 3) rep(j, 1, m) g[i][j] = 1;
	for(int i = 1; i + 3 <= n; i += 3) {
		int flag = 0;
		rep(j, 1, m) {
			if(!g[i + 1][j] && !g[i + 2][j]) continue;
			g[i + 1][j] = g[i + 2][j] = flag = 1;
			break;
		}
		if(!flag) {
			g[i + 1][1] = g[i + 2][1] = 1;
		}
	}
	if(n % 3 == 0) {
		rep(i, 1, m) {
			if(!g[n - 1][i] && !g[n][i]) continue;
			g[n - 1][i] = g[n][i] = 1;
		}
	}
	rep(i, 1, n) {
		rep(j, 1, m) printf(g[i][j] ? "X" : ".");
		printf("\n");
	}
	return;
}

int main() {
	for(scanf("%d", &t); t--; ) work();
	return 0;
}