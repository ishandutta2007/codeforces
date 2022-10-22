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
#define MAXN 150005

int n[4];
int a[4][MAXN];
int m[4];
vi adj[4][MAXN];
int dp[4][MAXN];
int lg2[MAXN];
int ans;

int sparse[25][MAXN];
int getMn(int i, int j) {
	int k = lg2[j - i + 1];
	return min(sparse[k][i], sparse[k][j - (1 << k) + 1]);
}

int main() {
	REP (i, 0, 4) {
		scanf("%d", &n[i]);
	}
	int cur = 0;
	REP (i, 1, MAXN) {
		if (i == (1 << cur + 1)) cur++;
		lg2[i] = cur;
	}
	REP (i, 0, 4) {
		REP (j, 1, n[i] + 1) {
			scanf("%d", &a[i][j]);
		}
	}
	REP (i, 1, 4) {
		scanf("%d", &m[i]);
		REP (j, 0, m[i]) {
			int x, y; scanf("%d%d", &x, &y);
			adj[i][y].pb(x);
		}
	}
	REP (i, 1, 4) {
		REP (j, 1, n[i] + 1) {
			adj[i][j].pb(0);
			adj[i][j].pb(n[i - 1] + 1);
			sort(ALL(adj[i][j]));
		}
	}
	REP (i, 1, n[0] + 1) {
		dp[0][i] = a[0][i];
	}
	ans = INF;
	REP (i, 1, 4) {
		REP (j, 1, n[i - 1] + 1) {
			sparse[0][j] = dp[i - 1][j];
		}
		REP (k, 1, 20) {
			REP (j, 1, n[i - 1] + 1) {
				if (j + (1 << k) - 1 > n[i - 1]) break;
				sparse[k][j] = min(sparse[k - 1][j], sparse[k - 1][j + (1 << k - 1)]);
			}
		}
		REP (j, 1, n[i] + 1) {
			dp[i][j] = INF;
			REP (k, 1, adj[i][j].size()) {
				if (adj[i][j][k - 1] + 1 > adj[i][j][k] - 1) continue;
				mnto(dp[i][j], getMn(adj[i][j][k - 1] + 1, adj[i][j][k] - 1) + a[i][j]);
			}
			if (i == 3) {
				mnto(ans, dp[i][j]);
			}
		}
	}
	if (ans == INF) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}