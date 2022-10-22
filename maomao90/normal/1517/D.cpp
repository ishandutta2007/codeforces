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

int n, m, k;
vector<pair<ii, int> > adj[MAXN][MAXN];
ll dp[25][MAXN][MAXN];

int main() {
	scanf("%d%d%d", &n, &m, &k);
	REP (i, 0, n) {
		REP (j, 0, m - 1) {
			int x; scanf("%d", &x);
			adj[i][j].pb(MP(i, j + 1), x);
			adj[i][j + 1].pb(MP(i, j), x);
		}
	}
	REP (i, 0, n - 1) {
		REP (j, 0, m) {
			int x; scanf("%d", &x);
			adj[i][j].pb(MP(i + 1, j), x);
			adj[i + 1][j].pb(MP(i, j), x);
		}
	}
	if (k % 2 == 1) {
		REP (i, 0, n) {
			REP (j, 0, m) {
				printf("-1 ");
			}
			printf("\n");
		}
		return 0;
	}
	k /= 2;
	REP (i, 0, k + 5) {
		REP (j, 0, n + 5) {
			REP (l, 0, m + 5) {
				dp[i][j][l] = LINF;
			}
		}
	}
	REP (j, 0, n + 5) {
		REP (l, 0, m + 5) {
			dp[0][j][l] = 0;
		}
	}
	REP (l, 1, k + 1) {
		REP (i, 0, n) {
			REP (j, 0, m) {
				REP (_, 0, adj[i][j].size()) {
					ii v = adj[i][j][_].FI; int w = adj[i][j][_].SE;
					REP (x, 0, l) {
						mnto(dp[l][i][j], dp[x][v.FI][v.SE] + w * (l - x));
					}
				}
			}
		}
	}
	REP (i, 0, n) {
		REP (j, 0, m) {
			printf("%lld ", dp[k][i][j] * 2);
		}
		printf("\n");
	}
	return 0;
}