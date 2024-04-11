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
#define MAXN 1005

int n, k;
int g[MAXN][MAXN];
int ans;

void solve(int l, int r, int x) {
	if (l >= r) return;
	mxto(ans, x);
	int s = (r - l) / k + 1;
	debug("%d %d %d %d\n", l, r, x, s);
	REP (i, 0, k) {
		int pl = l + i * s, pr = l + (i + 1) * s - 1;
		mnto(pr, r);
		assert(i == k - 1 ? pr == r : 1);
		debug(" %d %d\n", pl, pr);
		solve(pl, pr, x + 1);
	}
	REP (i, l, r + 1) {
		REP (j, i + 1, r + 1) {
			if (g[i][j] == 0) {
				g[i][j] = x;
			}
		}
	}
}

int main() {
	scanf("%d%d", &n, &k);
	solve(1, n, 1);
	printf("%d\n", ans);
	REP (i, 1, n + 1) {
		REP (j, i + 1, n + 1) {
			printf("%d ", g[i][j]);
		}
	}
	printf("\n");
	return 0;
}