// time-limit: 2000
// problem-url: https://codeforces.com/contest/1608/problem/E

// For the earth will be filled with the knowledge of the glory
// of the Lord as the waters cover the sea
// Habakkuk 2:14
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
#define MAXN 200005

int n;
vii lr[3], du[3];

struct bound {
	int l = INF, r = -INF, u = -INF, d = INF;
	inline void add(ii pt) {
		mnto(l, pt.FI);
		mxto(r, pt.FI);
		mxto(u, pt.SE);
		mnto(d, pt.SE);
	}
};

bool isPos(int x) {
	REP (i, 0, 3) {
		bound lft;
		REP (j, 0, x) {
			lft.add(lr[i][j]);
		}
		REP (j, 0, 3) {
			if (i == j) {
			   	continue;
			}
			bound rht;
			REP (k, 0, x) {
				rht.add(lr[j][n - k - 1]);
			}
			if (lft.r >= rht.l) {
				continue;
			}
			int c = 3 - i - j;
			int cnt = 0;
			REP (k, 0, n) {
				if (lr[c][k].FI > lft.r && lr[c][k].FI != lft.l &&
					   	lr[c][k].FI < rht.l && lr[c][k].FI != rht.r) {
					cnt++;
				}
			}
			if (cnt >= x) {
				return 1;
			}

			cnt = 0;
			bound down;
			REP (k, 0, n) {
				if (du[j][k].FI > lft.r && du[j][k].FI != lft.l) {
					cnt++;
					down.add(du[j][k]);
				}
				if (cnt >= x) {
					break;
				}
			}
			if (cnt < x) {
				continue;
			}
			cnt = 0;
			REP (k, 0, n) {
				if (lr[c][k].FI > lft.r && lr[c][k].FI != lft.l &&
					   	lr[c][k].SE > down.u && lr[c][k].SE != down.d) {
					cnt++;
				}
			}
			if (cnt >= x) {
				return 1;
			}
		}
	}
	return 0;
}

int main() {
	int _t = 1;
   	//scanf("%d", &_t);
	while (_t--) {
		scanf("%d", &n);	
		REP (i, 0, n) {
			int x, y, c; scanf("%d%d%d", &x, &y, &c);
			lr[c - 1].pb(MP(x, y));
			du[c - 1].pb(MP(x, y));
		}
		n /= 3;
		REP (i, 0, 3) {
			assert(lr[i].size() == n && du[i].size() == n);
		}
		int ans = 1;
		REP (_, 0, 4) {
			REP (i, 0, 3) {
				sort(ALL(lr[i]), [] (ii l, ii r) {
						if (l.FI == r.FI) return l.SE < r.SE;
						return l.FI < r.FI;
						});
				sort(ALL(du[i]), [] (ii l, ii r) {
						if (l.SE == r.SE) return l.FI < r.FI;
						return l.SE < r.SE;
						});
			}
			int lo = 1, hi = n, mid;
			while (lo < hi) {
				mid = lo + hi + 1 >> 1;
				if (isPos(mid)) {
					lo = mid;
				} else {
					hi = mid - 1;
				}
			}
			mxto(ans, lo);
			REP (i, 0, 3) {
				REP (j, 0, n) {
					int nx = lr[i][j].SE, ny = -lr[i][j].FI;
					lr[i][j] = MP(nx, ny);
				}
				REP (j, 0, n) {
					int nx = du[i][j].SE, ny = -du[i][j].FI;
					du[i][j] = MP(nx, ny);
				}
			}
		}
		printf("%d\n", ans * 3);
	}
	return 0;
}