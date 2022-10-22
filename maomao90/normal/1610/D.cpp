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

// anything with at least 1 odd number works
// 2^even * (2^odd - 1)

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

int n;
int a[MAXN];
ll ans;

void solve(vi v) {
	int n = v.size();
	if (n == 0) return;
	int odd = 0;
	vi nv;
	REP (i, 0, n) {
		if (v[i] % 2 == 1) {
			odd++;
		} else {
			nv.pb(v[i] / 2);
		}
	}
	if (odd > 0) {
		ans += (fpow(2, odd - 1) - 1) * fpow(2, n - odd) % MOD;
	}
	if (ans >= MOD) {
		ans -= MOD;
	}
	solve(nv);
}

int main() {
	scanf("%d", &n);
	int odd = 0;
	REP (i, 0, n) {
		scanf("%d", &a[i]);
		odd += a[i] % 2 == 1;
	}
	ans = fpow(2, n - odd) * (fpow(2, odd) - 1) % MOD;
	vi v;
	REP (i, 0, n) {
		if (a[i] % 2 == 0) {
			v.pb(a[i] / 2);
		}
	}
	solve(v);
	printf("%lld\n", ans);
	return 0;
}

/*
5
12391240 103904 1000000000 4142834 1032840
*/