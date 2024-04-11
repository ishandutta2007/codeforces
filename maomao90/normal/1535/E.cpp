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
#define MAXN 300005
#define MAXL 20

int q;
int a[MAXN], c[MAXN], p[MAXL][MAXN];

int main() {
	scanf("%d%d%d", &q, &a[0], &c[0]);
	memset(p, -1, sizeof p);
	REP (i, 1, q + 1) {
		int t; scanf("%d", &t);
		if (t == 1) {
			scanf("%d%d%d", &p[0][i], &a[i], &c[i]);
			REP (k, 1, MAXL) {
				if (p[k - 1][i] == -1) {
					p[k][i] = -1;
				} else {
					p[k][i] = p[k - 1][p[k - 1][i]];
				}
			}
		} else {
			int v, w; scanf("%d%d", &v, &w);
			ll gold = 0, money = 0;
			while (w) {
				int u = v;
				RREP (k, MAXL - 1, 0) {
					if (p[k][u] == -1 || a[p[k][u]] == 0) continue;
					u = p[k][u];
				}
				if (a[u] == 0) break;
				int mn = min(w, a[u]);
				gold += mn;
				money += (ll) mn * c[u];
				a[u] -= mn;
				w -= mn;
			}
			printf("%lld %lld\n", gold, money);
			fflush(stdout);
		}
	}
	return 0;
}