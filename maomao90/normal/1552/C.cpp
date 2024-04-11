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
#define MAXN 205

int t;
int n, k;
ii xy[MAXN];
bool used[MAXN];
int isect[MAXN][MAXN];
int dp[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		int ans = 0;
		memset(used, 0, sizeof used);
		REP (i, 0, k) {
			scanf("%d%d", &xy[i].FI, &xy[i].SE);
			if (xy[i].FI > xy[i].SE) swap(xy[i].FI, xy[i].SE);
			used[xy[i].FI] = 1;
			used[xy[i].SE] = 1;
		}
		REP (i, 0, k) {
			auto [s, e] = xy[i];
			REP (j, i + 1, k) {
				auto [x, y] = xy[j];
				if (x < s && s < y && y < e) ans++;
				else if (s < x && x < e && y > e) ans++;
			}
		}
		debug("%d\n", ans);
		//sort(xy, xy + k);
		vi p;
		REP (i, 1, 2 * n + 1) {
			if (!used[i]) {
				p.pb(i);
			}
		}
		REP (i, 0, p.size() / 2) {
			int s = p[i], e = p[i + p.size() / 2];
			int cur = 0;
			REP (l, 0, k) {
				auto [x, y] = xy[l];
				if (x < s && s < y && y < e) cur++;
				else if (s < x && x < e && y > e) cur++;
			}
			debug("%d %d %d: %d\n", i, s, e, cur);
			ans += cur;
		}
		int x = p.size() / 2;
		ans += x * (x - 1) / 2;
		printf("%d\n", ans);
	}
	return 0;
}