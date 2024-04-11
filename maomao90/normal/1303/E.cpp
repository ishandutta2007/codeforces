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

int tc;
char s[MAXN], t[MAXN];
int scnt[35], tcnt[35];
int dp[MAXN][MAXN];
int nxt[MAXN][35];

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf(" %s", s + 1);
		scanf(" %s", t + 1);
		int n = strlen(s + 1), m = strlen(t + 1);
		REP (i, 0, 30) {
			scnt[i] = tcnt[i] = 0;
		}
		REP (i, 1, n + 1) {
			scnt[s[i] - 'a']++;
		}
		REP (i, 1, m + 1) {
			tcnt[t[i] - 'a']++;
		}
		bool pos = 1;
		REP (i, 0, 30) {
			if (scnt[i] < tcnt[i]) {
				pos = 0;
				break;
			}
		}
		if (!pos) {
			printf("NO\n");
			continue;
		}
		REP (i, 0, 30) {
			nxt[n + 1][i] = INF;
		}
		RREP (i, n, 0) {
			REP (j, 0, 30) {
				if (i > 0 && s[i] - 'a' == j) {
					nxt[i][j] = i;
				} else {
					nxt[i][j] = nxt[i + 1][j];
				}
			}
		}
		bool ans = 0;
		REP (i, 1, m + 1) {
			REP (j, 0, m + 1) {
				REP (k, 0, m + 1) {
					dp[j][k] = INF;
				}
			}
			debug("%d\n", i);
			REP (j, 0, i) {
				REP (k, i - 1, m + 1) {
					if (j == 0 && k == i - 1) {
						dp[j][k] = 0;
						continue;
					}
					if (j > 0) {
						int u = dp[j - 1][k];
						if (u != INF) {
							mnto(dp[j][k], nxt[u + 1][t[j] - 'a']);
						}
					}
					if (k >= i) {
						int u = dp[j][k - 1];
						if (u != INF) {
							mnto(dp[j][k], nxt[u + 1][t[k] - 'a']);
						}
					}
					debug(" %d %d: %d\n", j, k, dp[j][k]);
				}
			}
			if (dp[i - 1][m] <= n) {
				ans = 1;
				break;
			}
		}
		if (ans) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}


/*
1
bbaadcacdc
bbaacdcda
*/