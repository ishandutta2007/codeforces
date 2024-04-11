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
#define MAXL 31

int t;
int n, m;
int ban[MAXL][MAXN];
int a[MAXN];
int on[MAXL];
ll pw[MAXN];

int main() {
	scanf("%d", &t);
	pw[0] = 1;
	REP (i, 1, MAXN) {
		pw[i] = pw[i - 1] * 2 % MOD;
	}
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n + 5) {
			a[i] = 0;
			REP (k, 0, MAXL) {
				ban[k][i] = 0;
				on[k] = 0;
			}
		}
		REP (i, 0, m) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			REP (k, 0, MAXL) {
				if (!(x & (1 << k))) {
					ban[k][l]++;
					ban[k][r + 1]--;
				}
			}
		}
		REP (k, 0, MAXL) {
			REP (i, 1, n + 1) {
				ban[k][i] += ban[k][i - 1];
				if (!ban[k][i]) {
					a[i] += (1 << k);
					on[k]++;
				}
			}
		}
		REP (i, 1, n + 1) {
			debug("%d ", a[i]);
		}
		debug("\n");
		ll ans = 0;
		REP (k, 0, MAXL) {
			if (on[k] == 0) continue;
			int off = n - on[k];
			ans += pw[off] * (on[k] == 0 ? 1 : pw[on[k] - 1]) % MOD *
				(1 << k) % MOD;
			ans %= MOD;
			/*
			REP (i, 1, n + 1) {
				if (a[i] & (1 << k)) {
					on[k]--;
					int off = n - i - on[k];
					debug("%d %d: %d %d %lld\n", k, i, off, on[k], pw[off] * (on[k] == 0 ? 1 : pw[on[k] - 1]) % MOD * (1 << k) % MOD);
					ans += pw[off] * (on[k] == 0 ? 1 : pw[on[k] - 1]) % MOD *
					   	(1 << k) % MOD;
					ans %= MOD;
				}
			}
			*/
		}
		/*
		ans = 0;
		REP (i, 0, 1 << n) {
			int xr = 0;
			REP (j, 0, n) {
				if (i & (1 << j)) {
					xr ^= a[j + 1];
				}
			}
			ans += xr;
			ans %= MOD;
		}
		*/
		printf("%lld\n", ans);
	}
	return 0;
}