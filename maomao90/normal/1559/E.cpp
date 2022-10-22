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

int n, m;
int l[MAXN], r[MAXN], tl[MAXN], tr[MAXN];
bool isp[MAXN];
int sf[MAXN];

ll dp[MAXN], sm[MAXN];
ll gsm(int s, int e) {
	if (e < s) return 0;
	return (sm[e] - (s == 0 ? 0 : sm[s - 1]) + MOD) % MOD;
}
ll solve(int m, int* l, int* r) {
	REP (i, 0, m + 1) {
		dp[i] = 0;
		sm[i] = 1;
	}
	dp[0] = 1;
	REP (i, 1, n + 1) {
		RREP (j, m, 0) {
			int s = max(0, j - r[i]), e = j - l[i];
			dp[j] = gsm(s, e) % MOD;
		}
		sm[0] = dp[0];
		REP (j, 1, m + 1) {
			sm[j] = (sm[j - 1] + dp[j]) % MOD;
		}
	}
	return sm[m];
}

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 1, n + 1) {
		scanf("%d%d", &l[i], &r[i]);
	}
	REP (i, 2, m + 1) {
		isp[i] = 1;
		sf[i] = i;
	}
	for (ll i = 2; i * i <= m; i++) {
		if (!isp[i]) continue;
		for (ll j = i * i; j <= m; j += i) {
			if (isp[j]) {
				sf[j] = i;
			}
			isp[j] = 0;
		}
	}
	ll ans = solve(m, l, r);
	REP (i, 2, m + 1) {
		set<int> st;
		int u = i;
		bool pos = 1;
		while (u != 1) {
			if (!st.insert(sf[u]).SE) {
				pos = 0;
				break;
			}
			u /= sf[u];
		}
		if (!pos) continue;
		int cnt = st.size();
		int tm = m / i;
		REP (j, 1, n + 1) {
			tl[j] = (l[j] - 1) / i + 1;
			tr[j] = r[j] / i;
		}
		if (cnt % 2 == 1) {
			ans = (ans - solve(tm, tl, tr) + MOD) % MOD;
		} else {
			ans = (ans + solve(tm, tl, tr) + MOD) % MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}