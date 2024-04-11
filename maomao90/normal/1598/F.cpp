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
#define MAXX 400005
#define MAXN 20
#define MAXP 1100000

int n;
char s[MAXN + 5][MAXX];
int m[MAXN + 5];
int a[MAXN + 5][MAXX];
unordered_map<int, int> cnt[MAXN + 5], sofar[MAXN + 5];
int mn[MAXN + 5], sm[MAXN + 5];
int dp[MAXP];

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf(" %s", s[i]);
		m[i] = strlen(s[i]);
	}
	REP (i, 0, n) {
		mn[i] = INF;
		REP (j, 0, m[i]) {
			a[i][j] = s[i][j] == '(' ? 1 : -1;
			sm[i] += a[i][j];
			cnt[i][sm[i]]++;
			mnto(mn[i], sm[i]);
			mxto(sofar[i][mn[i]], cnt[i][mn[i]]);
		}
		debug("%d %d %d\n", i, sm[i], mn[i]);
	}
	int ans = 0;
	REP (i, 1, 1 << n) {
		dp[i] = -INF;
		int csm = 0;
		REP (j, 0, n) {
			if (i & (1 << j)) {
				csm += sm[j];
			}
		}
		REP (j, 0, n) {
			if (i & (1 << j)) {
				csm -= sm[j];
				if (-mn[j] <= csm) {
					mxto(dp[i], dp[i ^ (1 << j)] + cnt[j][-csm]);
				} else {
					mxto(ans, dp[i ^ (1 << j)] + sofar[j][-csm]);
				}
				csm += sm[j];
			}
		}
		debug("%s: %d\n", bitset<4>(i).to_string().c_str(), dp[i]);
		mxto(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}