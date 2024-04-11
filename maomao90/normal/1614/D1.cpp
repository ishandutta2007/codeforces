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
#define MAXN 20000005

int n, m;
int a[MAXN];
int len[MAXN];

ll memo[MAXN];
ll dp(int x) {
	if (memo[x] != -1) return memo[x];
	ll res = (ll) x * len[x];
	for (int j = 2 * x; j <= m; j += x) {
		if (len[j] == 0) continue;
		mxto(res, dp(j) + (ll) x * (len[x] - len[j]));
	}
	debug("%d: %lld\n", x, res);
	return memo[x] = res;
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		mxto(m, a[i]);
		for (int j = 1; (ll) j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				len[j]++;
				if (j * j != a[i]) {
					len[a[i] / j]++;
				}
			}
		}
	}
	REP (i, 1, m + 1) {
		debug("%d: %d\n", i, len[i]);
	}
	memset(memo, -1, sizeof memo);
	printf("%lld\n", dp(1));
	return 0;
}