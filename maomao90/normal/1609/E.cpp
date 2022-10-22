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
#define MAXN 100005

int n, q;
char s[MAXN];

struct thing {
	// a, b, c, ab, bc
	int dp[35];
	thing() {
		REP (i, 0, 35) {
			dp[i] = INF;
		}
	}
	int getans() {
		int res = INF;
		REP (i, 0, 35) {
			mnto(res, dp[i]);
		}
		return res;
	}
};

thing v[MAXN * 4];
#define MLR int mid = lo + hi >> 1; int lc = u << 1, rc = u << 1 ^ 1
thing merge(const thing& l, const thing& r) {
	thing res;
	REP (i, 0, 32) {
		if (l.dp[i] >= INF) continue;
		REP (j, 0, 32) {
			if (r.dp[j] >= INF) continue;
			if (((i & 1) && (j & (1 << 4))) ||
				   	((i & (1 << 3)) && (j & (1 << 2)))) {
				continue;
			}
			//debug(" %d %d %d %d\n", i, j, l.dp[i], r.dp[j]);
			int u = i | j;
			int x = l.dp[i] + r.dp[j];
			if ((i & 1) && (j & 2)) {
				u |= (1 << 3);
			}
			if ((i & 2) && (j & 4)) {
				u |= (1 << 4);
			}
			mnto(res.dp[u], x);
		}
	}
	return res;
}
void init(int u = 1, int lo = 0, int hi = n - 1) {
	if (lo == hi) {
		int x = s[lo] - 'a';
		REP (i, 0, 3) {
			v[u].dp[1 << i] = i != x;
		}
	} else {
		MLR;
		init(lc, lo, mid);
		init(rc, mid + 1, hi);
		debug("%d %d %d\n", lo, mid, hi);
		v[u] = merge(v[lc], v[rc]);
	}
}
void upd(int p, int x, int u = 1, int lo = 0, int hi = n - 1) {
	if (lo == hi) {
		REP (i, 0, 3) {
			v[u].dp[1 << i] = i != x;
		}
		return;
	}
	MLR;
	if (p <= mid) {
		upd(p, x, lc, lo, mid);
	} else {
		upd(p, x, rc, mid + 1, hi);
	}
	v[u] = merge(v[lc], v[rc]);
}

int main() {
	scanf("%d%d", &n, &q);
	scanf(" %s", s);
	init();
	while (q--) {
		int p; char c; scanf("%d %c", &p, &c);
		p--;
		upd(p, c - 'a');
		printf("%d\n", v[1].getans());
	}
	return 0;
}