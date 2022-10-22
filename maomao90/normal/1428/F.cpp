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

int n;
char s[MAXN];
int a[MAXN];

ll ans;
int dp[MAXN];
void dnc(int l, int r) {
	if (l > r) return;
	int m = l + r >> 1;
	int csum = 0;
	REP (i, m, r + 1) {
		if (a[i] == 1) {
			csum++;
		} else {
			csum = 0;
		}
		if (i != m) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = 0;
		}
		mxto(dp[i], csum);
	}
	csum = 0;
	RREP (i, m - 1, l) {
		if (a[i] == 1) {
			csum++;
		} else {
			csum = 0;
		}
		if (i != m - 1) {
			dp[i] = dp[i + 1];
		} else {
			dp[i] = 0;
		}
		mxto(dp[i], csum);
	}
	csum = 0;
	REP (i, m, r + 1) {
		if (a[i] == 1) {
			csum++;
		} else {
			break;
		}
	}
	debug("%d %d %d\n", l, r, m);
	ll sum = 0;
	REP (i, m, r + 1) {
		sum += dp[i];
		debug("  %d: %d\n", i, dp[i]);
	}
	deque<ii> v;
	REP (i, m + csum, r + 1) {
		if (i == m + csum || dp[i] != dp[i - 1]) {
			v.pb(MP(dp[i], i));
		}
	}
	debug(" %d\n", sum);
	ans += sum;
	bool stop = 0;
	int cmx = csum;
	RREP (i, m - 1, l) {
		if (a[i] == 0 && !stop) {
			stop = 1;
			int ptr = 1;
			RREP (j, cmx, cmx - csum + 1) {
				v.push_front(MP(j, m + csum - ptr));
				ptr++;
			}
		}
		if (!stop) {
			cmx++;
			sum += csum;
		} else {
			cmx = dp[i];
		}
		while (!v.empty() && v.front().FI < cmx) {
			int s = v.front().SE; 
			int diff = cmx - v.front().FI;
			v.pop_front();
			int e = r;
			if (!v.empty()) {
				e = v.front().SE - 1;
			}
			debug("   %d %d %d\n", diff, s, e);
			sum += (ll) diff * (e - s + 1);
		}
		if (!stop) {
			v.push_front(MP(cmx, m + csum));
		} else {
			v.push_front(MP(cmx, m));
		}
		ans += sum;
	}
	dnc(l, m - 1); dnc(m + 1, r);
}

int main() {
	scanf("%d", &n);
	scanf(" %s", s);
	REP (i, 0, n) {
		a[i] = s[i] - '0';
	}
	dnc(0, n - 1);
	printf("%lld\n", ans);
	return 0;
}