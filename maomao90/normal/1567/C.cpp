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
#define MAXN 20

int t;
char s[MAXN];
int a[MAXN];
int n;

ll memo[MAXN][5][5];
ll dp(int i, int cur, int nxt) {
	if (i == -1) {
		if (cur == 0 && nxt == 0) return 1;
		return 0;
	}
	if (memo[i][cur][nxt] != -1) return memo[i][cur][nxt];
	ll res = 0;
	REP (j, 0, 10) {
		REP (k, 0, 10) {
			int sm = j + k + cur;
			if (sm % 10 != a[i]) continue;
			int nnxt = sm / 10;
			res += dp(i - 1, nxt, nnxt);
		}
	}
	debug("%d %d %d: %lld\n", i, cur, nxt, res);
	return memo[i][cur][nxt] = res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf(" %s", s);
		n = strlen(s);
		REP (i, 0, n) {
			a[i] = s[i] - '0';
		}
		memset(memo, -1, sizeof memo);
		printf("%lld\n", dp(n - 1, 0, 0) - 2);
	}
	return 0;
}