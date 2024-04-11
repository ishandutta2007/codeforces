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

int t;
int n, m;
int x1, yy, x2, y2;
int w, h;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		scanf("%d%d%d%d", &x1, &yy, &x2, &y2);
		scanf("%d%d", &w, &h);
		int ans = INF;
		if (x2 - x1 + w <= n) {
			mnto(ans, max(0, w - x1));
			mnto(ans, max(0, w - (n - x2)));
		}
		if (y2 - yy + h <= m) {
			mnto(ans, max(0, h - yy));
			mnto(ans, max(0, h - (m - y2)));
		}
		if (ans == INF) {
			printf("-1\n");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}