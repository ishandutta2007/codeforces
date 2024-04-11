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
#define MAXN 100005

int t;
int n;
int k[MAXN];
vi a[MAXN];
int mx[MAXN];
vi vs;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		vs.clear();
		REP (i, 0, n) {
			scanf("%d", &k[i]);
			mx[i] = -INF;
			a[i].clear();
			a[i].resize(k[i] + 5);
			REP (j, 0, k[i]) {
				scanf("%d", &a[i][j]);
				a[i][j] -= j;
				mxto(mx[i], a[i][j]);
			}
			vs.pb(i);
		}
		sort(ALL(vs), [&] (int i, int j) {
				return mx[i] < mx[j];
				});
		ll power = 0, ans = 0;
		for (int i : vs) {
			REP (j, 0, k[i]) {
				ll arm = a[i][j] + j + 1;
				ll ex = max(0ll, arm - power);
				ans += ex;
				power += ex;
				power++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}