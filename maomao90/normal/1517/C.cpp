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
#define MAXN 505

int n;
int p[MAXN];
int grid[MAXN][MAXN];

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &p[i]);
	}
	memset(grid, -1, sizeof grid);
	RREP (i, n - 1, 0) {
		int r = i, c = i;
		REP (j, 0, p[i]) {
			grid[r][c] = p[i];
			if (r != n - 1 && grid[r + 1][c] == -1) {
				r++;
			} else {
				c--;
			}
		}
	}
	REP (i, 0, n) {
		REP (j, 0, i + 1) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}