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
#define MOD 998244353
#define MAXN 200005

int n;
char s[MAXN][3];
int w, q;
ll fact[MAXN], ifact[MAXN];

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
ll choose(ll n, ll r) {
	if (r < 0 || n < r) return 0;
	return fact[n] * ifact[n - r] % MOD * ifact[r] % MOD;
}

int main() {
	scanf("%d", &n);
	fact[0] = 1;
	REP (i, 1, 2 * n + 1) {
		fact[i] = fact[i - 1] * i % MOD;
	}
	ifact[2 * n] = fpow(fact[2 * n], MOD - 2);
	RREP (i, 2 * n - 1, 0) {
		ifact[i] = ifact[i + 1] * (i + 1) % MOD;
	}
	int wb = 1, bw = 1;
   	ll all = 1;
	REP (i, 0, n) {
		scanf(" %s", s[i]);
		REP (j, 0, 2) {
			if (s[i][j] == 'W') {
				w++;
			} else if (s[i][j] == '?') {
				q++;
			}
		}
		if (s[i][0] == 'B' || s[i][1] == 'W') {
			wb = 0;
		}
		if (s[i][0] == 'W' || s[i][1] == 'B') {
			bw = 0;
		}
		if (s[i][0] == s[i][1]) {
			if (s[i][0] == '?') {
				all = all * 2 % MOD;
			} else {
				all = 0;
			}
		}
	}
	debug("%d c %d = %lld\n", q, n - w, choose(q, n - w));
	ll ans = (choose(q, n - w) - all + wb + bw) % MOD;
	if (ans < 0) {
		ans += MOD;
	}
	printf("%lld\n", ans);
	return 0;
}