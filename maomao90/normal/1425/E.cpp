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
#define MAXN 200005

int n, k;
ll a[MAXN];
int d[MAXN];
ll dp[MAXN];
ll ans;

ll sum(int s, int e) {
	return a[e] - (s == 0 ? 0 : a[s - 1]);
}

int main() {
	scanf("%d%d", &n, &k);
	REP (i, 1, n + 1) {
		scanf("%lld", &a[i]);
		a[i] += a[i - 1];
	}
	REP (i, 1, n + 1) {
		scanf("%d", &d[i]);
	}
	RREP (i, n, 1) {
		dp[i] = max(dp[i + 1], sum(i, n) - d[i]);
		debug("%d: %lld\n", i, dp[i]);
	}
	if (k == 0) {
		printf("%lld\n", dp[1]);
		return 0;
	}
	if (k == 1) {
		int mn = INF, smn = INF;
		int amn = INF;
		REP (i, 1, n + 1) {
			mnto(amn, (int) sum(i, i));
			if (d[i] <= mn) {
				smn = mn;
				mn = d[i];
			} else if (d[i] < smn) {
				smn = d[i];
			}
			if (i != 1) {
				mxto(ans, dp[i]);
			}
		}
		mxto(ans, sum(1, n - 1) - mn);
		mxto(ans, sum(1, n) - mn - smn);
		mxto(ans, sum(1, n) - d[1] - amn);
		printf("%lld\n", ans);
		return 0;
	}
	int mn = INF;
	REP (i, 1, n) {
		mnto(mn, d[i]);
	}
	mxto(ans, sum(1, n) - mn);
	mxto(ans, sum(n, n) - d[n]);
	printf("%lld\n", ans);
	return 0;
}


/*
4 0
5 3 2 2
13 8 5 1
*/