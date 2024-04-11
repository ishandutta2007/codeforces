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
#define pb emplace_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005

int n, m;
int a[MAXN], b[MAXN];

ll memo[MAXN][2];
ll dp(int u, bool same) {
	if (memo[u][same] != -1) {
		return memo[u][same];
	}
	if (u == n) {
		return 1 - same;
	}
	ll res = 0;
	if (!same) {
		res = 1;
		if (a[u] == 0) {
			res *= m;
		}
		if (b[u] == 0) {
			res *= m;
		}
		res %= MOD;
		res *= dp(u + 1, 0);
		res %= MOD;
		return memo[u][same] = res;
	}
	if (a[u] == 0 && b[u] == 0) {
		res += (ll) (m - 1) * (m) / 2 % MOD * dp(u + 1, 0) % MOD;
		res %= MOD;
		res += (ll) m * dp(u + 1, 1) % MOD;
		res %= MOD;
	} else if (a[u] == 0) {
		res += (m - b[u]) * dp(u + 1, 0) % MOD;
		res %= MOD;
		res += dp(u + 1, 1) % MOD;
		res %= MOD;
	} else if (b[u] == 0) {
		res += (a[u] - 1) * dp(u + 1, 0) % MOD;
		res %= MOD;
		res += dp(u + 1, 1) % MOD;
		res %= MOD;
	} else {
		if (a[u] == b[u]) {
			res += dp(u + 1, 1) % MOD;
		} else if (a[u] > b[u]) {
			res += dp(u + 1, 0) % MOD;
		}
		res %= MOD;
	}
	return memo[u][same] = res;
}

ll fastExp(ll b, ll p) {
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
ll inv(ll x) {
	return fastExp(x, MOD - 2);
}

int cnt;

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		if (a[i] == 0) cnt++;
	}
	REP (i, 0, n) {
		scanf("%d", &b[i]);
		if (b[i] == 0) cnt++;
	}
	memset(memo, -1, sizeof memo);
	printf("%lld\n", dp(0, 1) * inv(fastExp(m, cnt)) % MOD);
	return 0;
}