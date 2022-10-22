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
#define MAXN 500005

int t;
int n, m;
vi a[MAXN], lmn[MAXN], rmn[MAXN], lmx[MAXN], rmx[MAXN];
char ans[MAXN];

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		REP (j, 0, m) {
			a[j].clear();
			a[j].resize(n);
			lmn[j].clear();
			lmn[j].resize(n, INF);
			rmn[j].clear();
			rmn[j].resize(n, INF);
			lmx[j].clear();
			lmx[j].resize(n, -INF);
			rmx[j].clear();
			rmx[j].resize(n, -INF);
		}
		REP (i, 0, n) {
			REP (j, 0, m) {
				scanf("%d", &a[j][i]);
			}
		}
		REP (i, 0, m) {
			REP (j, 0, n) {
				mnto(lmn[i][j], a[i][j]);
				if (i != 0) {
					mnto(lmn[i][j], lmn[i - 1][j]);
				}
				mxto(lmx[i][j], a[i][j]);
				if (i != 0) {
					mxto(lmx[i][j], lmx[i - 1][j]);
				}
			}
		}
		RREP (i, m - 1, 0) {
			REP (j, 0, n) {
				mnto(rmn[i][j], a[i][j]);
				if (i != m - 1) {
					mnto(rmn[i][j], rmn[i + 1][j]);
				}
				mxto(rmx[i][j], a[i][j]);
				if (i != m - 1) {
					mxto(rmx[i][j], rmx[i + 1][j]);
				}
			}
		}
		bool done = 0;
		REP (i, 0, m - 1) {
			vi id(n, 0);
			REP (j, 0, n) {
				id[j] = j;
			}
			sort(ALL(id), [&] (int a, int b) {
					return lmx[i][a] < lmx[i][b];
					});
			vi lb(n, -INF), lr(n, INF), rb(n, INF), rr(n, -INF);
			REP (j, 0, n) {
				mxto(lb[j], lmx[i][id[j]]);
				if (j != 0) {
					mxto(lb[j], lb[j - 1]);
				}
				mnto(rb[j], rmn[i + 1][id[j]]);
				if (j != 0) {
					mnto(rb[j], rb[j - 1]);
				}
			}
			RREP (j, n - 1, 0) {
				mnto(lr[j], lmn[i][id[j]]);
				if (j != n - 1) {
					mnto(lr[j], lr[j + 1]);
				}
				mxto(rr[j], rmx[i + 1][id[j]]);
				if (j != n - 1) {
					mxto(rr[j], rr[j + 1]);
				}
			}
			REP (j, 0, n) {
				ans[j] = 'R';
			}
			ans[n] = 0;
			REP (j, 0, n - 1) {
				ans[id[j]] = 'B';
				if (lb[j] < lr[j + 1] && rb[j] > rr[j + 1]) {
					printf("YES\n");
					printf("%s %d\n", ans, i + 1);
					done = 1;
					break;
				}
			}
			if (done) break;
		}
		if (!done) {
			printf("NO\n");
		}
	}
	return 0;
}