#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
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
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifdef DEBUG
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 405

int t;
int n, m;
char tmp[MAXN][MAXN];
int a[MAXN][MAXN];
int cost[MAXN][MAXN][MAXN];

inline int sum(int i, int j, int k, int l, bool inv = 0) {
	int res = a[j][l] - a[j][k - 1] - a[i - 1][l] + a[i - 1][k - 1];
	if (inv) {
		res = (j - i + 1) * (l - k + 1) - res;
	}
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 1, n + 1) {
			scanf(" %s", tmp[i] + 1);
			REP (j, 1, m + 1) {
				a[i][j] = tmp[i][j] - '0';
			}
		}
		REP (i, 1, n + 1) {
			REP (j, 1, m + 1) {
				a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
			}
		}
		REP (i, 1, m + 1) {
			REP (j, i + 3, m + 1) {
				REP (k, 1, n + 1) {
					cost[i][j][k] = sum(1, k, i + 1, j - 1) + 
						sum(1, k, i, i, 1) + sum(1, k, j, j, 1);
					debug("%d %d %d: %d\n", i, j, k, cost[i][j][k]);
				}
			}
		}
		int ans = INF;
		REP (i, 1, m + 1) {
			REP (j, i + 3, m + 1) {
				int cmn = INF;
				RREP (k, n - 4, 1) {
					mnto(cmn, cost[i][j][k + 3] +
							sum(k + 4, k + 4, i + 1, j - 1, 1));
					debug(" %d %d %d %d\n", k + 4, k + 4, i + 1, j - 1);
					debug(" %d %d %d: %d %d\n", i, j, k, cmn, sum(k + 4, k + 4, i + 1, j - 1, 1));
					mnto(ans, cmn - cost[i][j][k] + sum(k, k, i + 1, j - 1, 1));
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}