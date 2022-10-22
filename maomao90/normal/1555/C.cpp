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
#define MAXN 200005

int t;
int m;
int a[2][MAXN];

int sum(int i, int s, int e) {
	if (s > e) return 0;
	return a[i][e] - a[i][s - 1];
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &m);
		REP (i, 0, 2) {
			REP (j, 1, m + 5) {
				if (j <= m) {
					scanf("%d", &a[i][j]);
				}
				a[i][j] += a[i][j - 1];
			}
		}
		int ans = INF;
		REP (i, 1, m + 1) {
			mnto(ans, max(sum(1, 1, i - 1), sum(0, i + 1, m)));
		}
		printf("%d\n", ans);
	}
	return 0;
}