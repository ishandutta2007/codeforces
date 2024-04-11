#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define MP make_pair
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
#define MT make_tuple
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 4005

int dirr[] = {1, 0, -1, 0}, dirc[] = {0, 1, 0, -1};

int n;
int t;
int grid[MAXN * 2][MAXN * 2];
queue<ii> q;

int main() {
	scanf("%d%d", &n, &t);
	grid[MAXN][MAXN] = n;
	if (n >= 4) q.push(MP(MAXN, MAXN));
	while (!q.empty()) {
		int r, c; tie(r, c) = q.front(); q.pop();
		if (grid[r][c] < 4) continue;
		int div = grid[r][c] / 4;
		grid[r][c] %= 4;
		REP (i, 0, 4) {
			int nr = r + dirr[i], nc = c + dirc[i];
			grid[nr][nc] += div;
			if (grid[nr][nc] >= 4) q.push(MP(nr, nc));
		}
	}
	while (t--) {
		int x, y; scanf("%d%d", &x, &y);
		x += MAXN; y += MAXN;
		if (x >= MAXN * 2 || y >= MAXN * 2 || x < 0 || y < 0) printf("0\n");
		else printf("%d\n", grid[x][y]);
	}
	return 0;
}