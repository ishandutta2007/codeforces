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
#define MAXN 25

int t;
int h, w;
int grid[MAXN][MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &h, &w);
		memset(grid, 0, sizeof grid);
		for (int i = 0; i < w; i += 2) {
			grid[0][i] = 1;
		}
		for (int i = 2; i < h; i += 2) {
			grid[i][w - 1] = 1;
		}
		for (int i = w - 3; i >= 0; i -= 2) {
			grid[h - 1][i] = 1;
		}
		for (int i = 2; i < h - 2; i += 2) {
			grid[i][0] = 1;
		}
		REP (i, 0, h) {
			REP (j, 0, w) {
				printf("%d", grid[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}