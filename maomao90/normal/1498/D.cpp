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
#define MAXN 200005

int n, m;
int dp[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, m + 1) {
		dp[i] = INF;
	}
	dp[0] = 0;
	REP (i, 1, n + 1) {
		int t;
	   	ll x, y; scanf("%d%lld%lld", &t, &x, &y);
		if (t == 1) {
			x = (x - 1) / 100000 + 1;
			REP (j, 0, m + 1) {
				if (dp[j] == INF || dp[j] == i) continue;
				int u = j;
				REP (k, 0, y) {
					u += x;
					if (u <= m && dp[u] == INF) {
						//debug("%d %d\n", i, u);
						dp[u] = i;
					} else {
						break;
					}
				}
			}
		} else {
			REP (j, 1, m + 1) {
				if (dp[j] == INF || dp[j] == i) continue;
				ll u = j;
				REP (k, 0, y) {
					u = u * x;
					if (u % 100000 == 0) {
						u /= 100000;
					} else {
						u /= 100000;
						u++;
					}
					if (u <= m && dp[u] == INF) {
						//debug("%d %lld\n", i, u);
						dp[u] = i;
					} else {
						break;
					}
				}
			}
		}
	}
	REP (i, 1, m + 1) {
		printf("%d ", dp[i] == INF ? -1 : dp[i]);
	}
	printf("\n");
	return 0;
}