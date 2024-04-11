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
int n;
int r[MAXN][5];
int mn[5], mnid[5];
int npos[MAXN];

int main() {
	mt19937 rnd(8);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 0, n) {
			REP (j, 0, 5) {
				scanf("%d", &r[i][j]);
			}
		}
		vi p(n);
		REP (i, 0, n) {
			p[i] = i;
		}
		shuffle(ALL(p), rnd);
		REP (i, 0, n) {
			npos[i] = 0;
		}
		int ans = -2;
		REP (_, 0, n) {
			int i = p[_];
			if (npos[i]) continue;
			debug("%d\n", i);
			bool isa = 1;
			REP (j, 0, n) {
				if (j == i) continue;
				int win = 0;
				REP (k, 0, 5) {
					if (r[i][k] < r[j][k]) {
						win++;
					}
				}
				if (win >= 3) {
					debug(" %d\n", j);
					npos[j] = 1;
				} else {
					isa = 0;
				}
			}
			if (isa) {
				ans = i;
				break;
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}