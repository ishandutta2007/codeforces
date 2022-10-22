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
#define MAXN 120005

int k, n;
char s[10];
map<ll, int> mp;
int m;
int p[MAXN];
int fx[MAXN];
int dp[MAXN][3];
vi c[MAXN];

ll fpow(ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) {
			res = res * b % MOD;
		}
		b = b * b % MOD;
		p >>= 1;
	}
	return res;
}

inline int getsc() {
	if (s[0] == 'w' || s[0] == 'y') return 0;
	else if (s[0] == 'g' || s[0] == 'b') return 1;
	else return 2;
}

int main() {
	scanf("%d%d", &k, &n);
	memset(fx, -1, sizeof fx);
	REP (i, 0, n) {
		ll v; scanf("%lld", &v);
		scanf(" %s", s);
		int c = getsc();
		int lg = 0;
		ll tv = v;
		while (v) {
			if (mp.find(v) != mp.end()) {
				break;
			}
			lg++;
			v >>= 1;
		}
		int tmp = lg;
		lg--;
		mxto(lg, 0);
		v = tv;
		bool f = 1;
		while (v) {
			if (lg < 0) break;
			if (mp.find(v) == mp.end()) {
				mp[v] = m + lg;
				lg--;
			}
			if (f) {
				fx[mp[v]] = c;
			}
			f = 0;
			v >>= 1;
		}
		v = tv;
		while (v) {
			p[mp[v]] = mp[v >> 1];
			v >>= 1;
		}
		m += tmp;
	}
	REP (i, 1, m) {
		c[p[i]].pb(i);
	}
	RREP (i, m - 1, 0) {
		REP (j, 0, 3) {
			if (fx[i] != -1 && fx[i] != j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = 1;
			for (int v : c[i]) {
				int tmp = 0;
				REP (k, 0, 3) {
					if (j == k) continue;
					tmp += dp[v][k];
					if (tmp >= MOD) {
						tmp -= MOD;
					}
				}
				dp[i][j] = (ll) dp[i][j] * tmp % MOD;
			}

			if (fx[i] == -1) {
				dp[i][j] *= 2;
				if (dp[i][j] >= MOD) {
					dp[i][j] -= MOD;
				}
			}
		}
	}
	ll ans = 0;
	REP (j, 0, 3) {
		ans = (ans + dp[0][j]) % MOD;
	}
	ans = ans * fpow(4, (1ll << k) - 1 - m) % MOD;
	printf("%lld\n", ans);
	return 0;
}