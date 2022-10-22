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
#define MAXN 3005

int t;
int n;
int a[MAXN];
vi mp[MAXN];
int dp[MAXN][MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			mp[i].clear();
		}
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			mp[a[i]].pb(i);
		}
		REP (i, 1, n + 1) {
			dp[i][i] = 0;
			RREP (j, i - 1, 1) {
				dp[j][i] = dp[j + 1][i] + 1;
				for (int k : mp[a[j]]) {
					if (k <= j || k > i) continue;
					mnto(dp[j][i], dp[j][k - 1] + dp[k][i]);
				}
			}
		}
		printf("%d\n", dp[1][n]);
	}
	return 0;
}