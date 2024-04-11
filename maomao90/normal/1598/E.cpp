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

int n, m, q;
int block[MAXN][MAXN];
int tot;
ll ans;

ll dwn[MAXN][MAXN], rht[MAXN][MAXN];
void upd(int r, int c) {
	int tr = r, tc = c;
	int pr = -1, pc = 0;
	while (1) {
		tr += pr; tc += pc;
		if (block[tr][tc]) break;
		ans -= dwn[tr][tc];
		ans -= rht[tr][tc];
		dwn[tr][tc] = rht[tr + 1][tc] + 1;
		rht[tr][tc] = dwn[tr][tc + 1] + 1;
		ans += dwn[tr][tc];
		ans += rht[tr][tc];
		swap(pr, pc);
	}
	tr = r, tc = c;
	pr = 0, pc = -1;
	while (1) {
		tr += pr; tc += pc;
		if (block[tr][tc]) break;
		ans -= dwn[tr][tc];
		ans -= rht[tr][tc];
		dwn[tr][tc] = rht[tr + 1][tc] + 1;
		rht[tr][tc] = dwn[tr][tc + 1] + 1;
		ans += dwn[tr][tc];
		ans += rht[tr][tc];
		swap(pr, pc);
	}
}

int main() {
	scanf("%d%d%d", &n, &m, &q);
	tot = n * m;
	REP (i, 0, n + 1) {
		block[i][0] = 1;
	}
	REP (j, 0, m + 1) {
		block[0][j] = 1;
	}
	RREP (i, n, 1) {
		RREP (j, m, 1) {
			dwn[i][j] = rht[i + 1][j] + 1;
			rht[i][j] = dwn[i][j + 1] + 1;
			ans += dwn[i][j];
			ans += rht[i][j];
		}
	}
	REP (i, 1, n + 1) {
		REP (j, 1, n + 1) {
			debug("%d %d: %lld %lld\n", i, j, dwn[i][j], rht[i][j]);
		}
	}
	while (q--) {
		int x, y; scanf("%d%d", &x, &y);
		if (block[x][y] == 0) {
			ans -= dwn[x][y];
			ans -= rht[x][y];
			dwn[x][y] = rht[x][y] = 0;
			tot--;
		} else {
			dwn[x][y] = rht[x + 1][y] + 1;
			rht[x][y] = dwn[x][y + 1] + 1;
			ans += dwn[x][y];
			ans += rht[x][y];
			tot++;
		}
		block[x][y] ^= 1;
		upd(x, y);
		printf("%lld\n", ans - tot);
	}
	return 0;
}