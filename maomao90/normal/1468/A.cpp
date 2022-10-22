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
#define MOD 1000000007
#define MAXN 500005

int t;
int n;
int a[MAXN];
int dp[MAXN];

int fw[MAXN];
void upset(int i, int x) {
	for (; i < MAXN; i += i & -i) mxto(fw[i], x);
}
int qmx(int i) {
	int res = 0;
	for (; i > 0; i -= i & -i) mxto(res, fw[i]);
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
			dp[i] = 0;
			fw[i] = 0;
		}
		int ans = 0;
		stack<int> stk;
		a[0] = 1;
		dp[0] = 0;
		stk.push(0);
		REP (i, 1, n + 1) {
			dp[i] = qmx(a[i]) + 1;
			debug("%d: %d\n", i, dp[i]);
			upset(a[i], dp[i]);
			debug("%d -> %d\n", a[i], dp[i]);
			while (!stk.empty() && a[stk.top()] <= a[i]) {
				int tp = stk.top(); stk.pop();
				mxto(ans, ++dp[tp]);
				upset(a[tp], dp[tp]);
				debug("%d -> %d\n", a[tp], dp[tp]);
			}
			mxto(ans, dp[i]);
			stk.push(i);
		}
		printf("%d\n", ans);
	}
	return 0;
}