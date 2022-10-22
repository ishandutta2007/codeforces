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
#define debug(args...) printf(args)
#else
#define debug(args...)
#endif

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 305

int t;
int n, m;
ii a[MAXN * MAXN];
int grid[MAXN][MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (i, 0, n) {
			REP (j, 0, m) {
				int k = i * m + j;
				scanf("%d", &a[k].FI);
				a[k].SE = k;
			}
		}
		sort(a, a + n * m, [&] (ii l, ii r) {
				if (l.FI == r.FI) return l.SE > r.SE;
				return l.FI < r.FI;
				});
		int ptr = 0;
		int r = 0, c = 0;
		while (ptr < n * m) {
			int prv = a[ptr].FI;
			vi v;
			vii pos;
			for (int i = ptr; i < n * m && a[i].FI == prv; i++) {
				v.pb(a[i].SE);
				pos.pb(MP(r, c));
				c++;
				if (c >= m) {
					c = 0;
					r++;
				}
			}
			sort(ALL(pos), [&] (ii l, ii r) {
					if (l.FI == r.FI) return l.SE < r.SE;
					return l.FI > r.FI;
					});
			REP (i, 0, v.size()) {
				grid[pos[i].FI][pos[i].SE] = v[i];
			}
			for (int i = ptr; i < n * m && a[i].FI == prv; i++) {
				ptr = i;
			}
			ptr++;			
		}
		debug("\n");
		REP (i, 0, n) {
			REP (j, 0, m) {
				debug(" %d", grid[i][j]);
			}
			debug("\n");
		}
		int ans = 0;
		REP (i, 0, n) {
			REP (j, 0, m) {
				REP (k, 0, j) {
					ans += grid[i][j] > grid[i][k];
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}