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

#define INF 2000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 500005

int n, k;
int a[MAXN];
int b[MAXN];
set<ii> st;
int ans;

int solve(vi& a) {
	// value is decreasing
	st.clear();
	st.insert(MP(a[0], 0));
	debug("+ %d %d\n", a[0], 0);
	int res = INF;
	int n = a.size();
	REP (i, 1, n) {
		auto upper = st.upper_bound(MP(a[i] - i, INF));
		debug("%d\n", i);
		if (upper == st.begin()) continue;
		int dp = prev(upper) -> SE + i - 1;
		debug(" %d\n", dp);
		auto ptr = st.insert(MP(a[i] - i, dp - i)).FI;
		debug(" + %d %d\n", a[i] - 1, dp - i);
		if (ptr != st.begin() && prev(ptr) -> SE <= ptr -> SE) {
			debug(" -\n");
			st.erase(ptr);
			continue;
		}
		while (next(ptr) != st.end() && next(ptr) -> SE >= ptr -> SE) {
			debug(" - %d %d\n", next(ptr) -> FI, next(ptr) -> SE);
			st.erase(next(ptr));
		}
		if (i == n - 1) {
			res = dp;
		}
	}
	return res;
}

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 1, n + 1) {
		scanf("%d", &a[i]);
	}
	a[0] = -INF;
	a[n + 1] = INF;
	REP (i, 1, k + 2) {
		if (i == k + 1) {
			b[i] = n + 1;
		} else {
			scanf("%d", &b[i]);
		}
		if (b[i - 1] + 1 == b[i]) {
			if (a[b[i - 1]] >= a[b[i]]) {
				printf("-1\n");
				return 0;
			}
			continue;
		}
		vi v;
		REP (j, b[i - 1], b[i] + 1) {
			v.pb(a[j]);
		}
		int cur = solve(v);
		if (cur == INF) {
			printf("-1\n");
			return 0;
		}
		ans += cur;
	}
	printf("%d\n", ans);
	return 0;
}