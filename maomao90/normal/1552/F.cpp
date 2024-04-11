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
#define debug(args...) _debug(args)
void _debug(const char* format, ...) {
	va_list args;
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
}
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 998244353
#define MAXN 200005

int n;
set<ii> st;
ll psum[MAXN];
ll ans;

ll qsm(int s, int e) {
	ll res = psum[e] - (s == 0 ? 0 : psum[s - 1]);
	res %= MOD;
	if (res < 0) res += MOD;
	return res;
}

int main() {
	scanf("%d", &n);
	REP (i, 0, n) {
		int x, y, s; scanf("%d%d%d", &x, &y, &s);
		ll cur = x - y;
		auto lower = st.lower_bound(MP(y, -1));
		if (lower != st.end()) {
			int j = lower -> SE;
			debug(" %d %d\n", j, qsm(j, i - 1));
			cur += qsm(j, i - 1);
			cur %= MOD;
		}
		debug("%d: %lld\n", i, cur);
		psum[i] = ((i == 0 ? 0 : psum[i - 1]) + cur) % MOD;
		if (s == 1) {
			ans += cur;
			ans %= MOD;
		}
		st.insert(MP(x, i));
		if (i == n - 1) {
			ans += x + 1;
			ans %= MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}