#include <bits/stdc++.h> 
using namespace std;

#define mnto(x, y) x = min(x, (__typeof__(x)) y)
#define mxto(x, y) x = max(x, (__typeof__(x)) y)
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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 998244353
#define MAXN 25
#define MAXM 50005

int n, m;
int d[MAXN][MAXM];
ll ans, fact;

ll fastExp(ll b, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1) res = res * b % MOD;
		b = b * b % MOD;
		p >>= 1;
	}
	return res;
}
ll inv(ll x) {
	return fastExp(x, MOD - 2);
}

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		REP (j, 0, m) {
			scanf("%d", &d[i][j]);
		}
	}
	fact = 1;
	REP (i, 1, n + 1) {
		fact = fact * i % MOD;
	}
	REP (i, 0, m) {
		vi v;
		REP (j, 0, n) {
			v.pb(d[j][i] - 1);
		}
		sort(ALL(v));
		ll res = 1;
		int cnt = 0;
		for (int j : v) {
			res = res * (j - cnt) % MOD;
			cnt++;
		}
		res = (fact - res + MOD) % MOD;
		ans = (ans + res) % MOD;
	}
	ans = ans * inv(fact) % MOD;
	printf("%lld\n", ans);
	return 0;
}