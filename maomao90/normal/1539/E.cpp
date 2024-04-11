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
#define pb emplace_back
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

int n, m;
int k[MAXN];
int al[MAXN], bl[MAXN], ar[MAXN], br[MAXN];
bool dpl[MAXN], dpr[MAXN];
bool ans[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 1, n + 1) {
		scanf("%d", &k[i]);
		scanf("%d%d", &al[i], &bl[i]);
		scanf("%d%d", &ar[i], &br[i]);
	}
	k[0] = 0;
	al[0] = al[0] = ar[0] = br[0] = 0;
	int lmn = -1, lmx = INF, rmn = -1, rmx = INF, rcan = 1, lcan = 1;
	RREP (i, n, 0) {
		mxto(lmn, al[i]);
		mnto(lmx, bl[i]);
		mxto(rmn, ar[i]);
		mnto(rmx, br[i]);
		auto [nlmn, nlmx, nrmn, nrmx, nlcan, nrcan] = MT(lmn, lmx, rmn, rmx, lcan, rcan);
		if (lmn <= k[i] && k[i] <= lmx && rcan) {
			dpl[i] = 1;
			nrmn = ar[i];
			nrmx = br[i];
			nlcan = 1;
		}
		if (rmn <= k[i] && k[i] <= rmx && lcan) {
			dpr[i] = 1;
			nlmn = al[i];
			nlmx = bl[i];
			nrcan = 1;
		}
		if (!(al[i] <= k[i] && k[i] <= bl[i])) {
			nlcan = 0;
		}
		if (!(ar[i] <= k[i] && k[i] <= br[i])) {
			nrcan = 0;
		}
		lmn = nlmn; lmx = nlmx; rmn = nrmn; rmx = nrmx; lcan = nlcan; rcan = nrcan;
	}
	REP (i, 0, n + 1) {
		debug("%d: %d %d\n", i, dpl[i], dpr[i]);
	}
	if ((!dpl[0] && !dpr[0]) || (!dpl[n] && !dpr[n])) {
		printf("No\n");
		return 0;
	}
	bool cur = dpl[0];
	REP (i, 1, n + 1) {
		ans[i] = cur;
		if (cur) {
			if (dpr[i]) {
				cur = !cur;
			}
		} else {
			if (dpl[i]) {
				cur = !cur;
			}
		}
	}
	printf("Yes\n");
	REP (i, 1, n + 1) {
		printf("%d ", ans[i]);
	}
	printf("\n");
	return 0;
}

/*
4 10
3
0 3
0 3
7
0 3
3 7
2
3 5
1 3
7
6 9
2 4

5 10
5
0 5
0 5
4
0 5
1 4
3
0 5
0 3
2
0 5
0 2
6
2 2
6 6


2 100
2
0 10
1 99
3
3 3
3 5


2 2
1
0 2
0 0
2
0 2
2 2
*/