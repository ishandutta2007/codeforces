// time-limit: 3000
// problem-url: https://codeforces.com/contest/1623/problem/D

// he refreshes my soul. He guides me along the right
// paths for his name's sake
// Psalms 23:3
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

int t;
int n, m, r1, c1, r2, c2;
ll p;
vi v;

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
inline ll inv(ll a) {
	return fpow(a, MOD - 2);
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d%d%d%d%lld", &n, &m, &r1, &c1, &r2, &c2, &p);
		p = p * inv(100) % MOD;
		ll pm = (1 - p + MOD) % MOD;
		v.clear();
		int r = r1, c = c1;
		int dr = 1, dc = 1;
		ll time = 0;
		while (time < (2 * n - 2) * (2 * m - 2)) {
			if (r == r2 || c == c2) {
				v.pb(time);
			}
			if (r + dr <= 0 || r + dr > n) {
				dr *= -1;
			}
			if (c + dc <= 0 || c + dc > m) {
				dc *= -1;
			}
			r += dr; c += dc;
			time++;
		}
		debug(" %d %d %d %d\n", r, c, r1, c1);
		debug(" %d\n", time);
		debug("%d\n", (int) v.size());
		for (int i : v) {
			debug("%d ", i);
		}
		debug("\n");
		int s = v.size();
		ll cmp = 1;
		ll ans = 0;
		REP (i, 0, s) {
			ll x = inv((1 - fpow(pm, s) + MOD) % MOD);
			ll a = v[i] * x % MOD, b = time * (x * x % MOD - x + MOD) % MOD;
			ans += (a + b) % MOD * p % MOD * cmp % MOD;
			ans %= MOD;
			cmp = cmp * pm % MOD;
		}
		printf("%lld\n", ans);
	}
	return 0;
}