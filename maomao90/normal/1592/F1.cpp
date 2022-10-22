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
#define MAXN 505

int n, m;
int g[MAXN][MAXN], tg[MAXN][MAXN];
int ans;

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 0, n) {
		REP (j, 0, m) {
			char c; scanf(" %c", &c);
			g[i][j] = c == 'B';
		}
	}
	REP (i, 0, n) {
		REP (j, 0, m) {
			tg[i][j] = (g[i][j] + g[i + 1][j] + g[i][j + 1] + g[i + 1][j + 1]) % 2;
			ans += tg[i][j];
			debug("%d", tg[i][j]);
		}
		debug("\n");
	}
	bool found = 0;
	REP (i, 0, n - 1) {
		REP (j, 0, m - 1) {
			if (tg[i][j] == 1 && tg[i][m - 1] == 1 && tg[n - 1][j] == 1 && tg[n - 1][m - 1] == 1) {
				found = 1;
				break;
			}
		}
		if (found) {
			break;
		}
	}
	ans -= found;
	printf("%d\n", ans);
	return 0;
}