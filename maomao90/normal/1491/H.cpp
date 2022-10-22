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
#define MAXN 100005
#define BLK 300

int n, q;
int a[MAXN];
int bmp[MAXN];

struct Block {
	int l, r;
	int lst[BLK + 5];
	int lazy;
	bool all;
	void calc() {
		all = 1;
		REP (i, l, r + 1) {
			if (a[i] < l) {
				lst[i - l] = i;
			} else {
				lst[i - l] = lst[a[i] - l];
				all = 0;
			}
			debug(" %d %d\n", i, lst[i - l]);
		}
	}
	void update(int x) {
		if (all) {
			lazy += x;
			mnto(lazy, n);
		} else {
			REP (i, l, r + 1) {
				a[i] -= x;
				mxto(a[i], 1);
			}
			calc();
		}
	}
	void update(int s, int e, int x) {
		if (s == l && e == r) {
			update(x);
			return;
		}
		if (all) {
			REP (i, l, r + 1) {
				a[i] -= lazy;
				mxto(a[i], 1);
			}
			lazy = 0;
		}
		REP (i, s, e + 1) {
			a[i] -= x;
			mxto(a[i], 1);
		}
		calc();
	}
} blk[MAXN / BLK + 5];

void update(int l, int r, int x) {
	REP (i, bmp[l], bmp[r] + 1) {
		blk[i].update(max(l, blk[i].l), min(r, blk[i].r), x);
	}
}

inline int geta(int i) {
	return max(a[i] - blk[bmp[i]].lazy, 1);
}
inline int getjmp(int i) {
	Block &cblk = blk[bmp[i]];
	return geta(cblk.lst[i - cblk.l]);
}
int lca(int u, int v) {
	if (u == 1 || v == 1) return 1;
	int tu = u, tv = v;
	debug("%d %d\n", u, v);
	while (getjmp(tu) != getjmp(tv)) {
		if (tu < tv) swap(tu, tv);
		tu = getjmp(tu);
		debug(" %d %d\n", tu, tv);
	}
	while (tu != tv) {
		if (tu < tv) swap(tu, tv);
		tu = geta(tu);
	}
	return tu;
}

int main() {
	scanf("%d%d", &n, &q);
	REP (i, 2, n + 1) {
		scanf("%d", &a[i]);
	}
	int i = 0;
	bmp[1] = -1;
	for (int l = 2; l <= n; l += BLK) {
		blk[i].l = l;
		blk[i].r = min(n, l + BLK - 1);
		blk[i].lazy = 0;
		blk[i].all = 0;
		blk[i].calc();
		REP (j, blk[i].l, blk[i].r + 1) {
			bmp[j] = i;
		}
		i++;
	}
	while (q--) {
		int t; scanf("%d", &t);
		if (t == 1) {
			int l, r, x; scanf("%d%d%d", &l, &r, &x);
			update(l, r, x);
		} else {
			int u, v; scanf("%d%d", &u, &v);
			printf("%d\n", lca(u, v));
		}
	}
	return 0;
}