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
#define BLK 450

int n, m;
int x[MAXN], y[MAXN];
int o[MAXN], k[MAXN];
int p[MAXN];
vi v[MAXN];
int blk[BLK][BLK];
int lst[MAXN];

int main() {
	scanf("%d%d", &n, &m);
	REP (i, 1, n + 1) {
		scanf("%d%d", &x[i], &y[i]);
		mnto(x[i], m + 1);
		mnto(y[i], m + 1);
	}
	REP (i, 0, m) {
		scanf("%d%d", &o[i], &k[i]);
		if (x[k[i]] + y[k[i]] < BLK) {
			continue;
		}
		debug("HI\n");
		v[k[i]].pb(i);
	}
	REP (i, 1, n + 1) {
		if (v[i].size() % 2 == 1) {
			v[i].pb(m);
		}
	}
	REP (i, 1, n + 1) {
		for (int j = 0; j < v[i].size(); j += 2) {
			int u = v[i][j];
			while (u < v[i][j + 1]) {
				int s = u + x[i], e = min(u + x[i] + y[i] - 1, v[i][j + 1] - 1);
				if (s <= e) {
					debug(" %d %d\n", s, e);
					p[s]++; p[e + 1]--;
				}
				u += x[i] + y[i];
			}
		}
	}
	REP (i, 1, m + 1) {
		p[i] += p[i - 1];
	}
	REP (i, 0, m) {
		int u = k[i];
		int b = x[u] + y[u];
		if (b < BLK) {
			if (o[i] == 1) {
				lst[u] = i;
			}
			REP (j, x[u], x[u] + y[u]) {
				if (o[i] == 1) {
					debug(" %d %d++\n", b, i + j);
					blk[b][(i + j) % b]++;
				} else {
					debug(" %d %d--\n", b, lst[u] + j);
					blk[b][(lst[u] + j) % b]--;
				}
			}
		}
		int ans = p[i];
		REP (j, 2, BLK) {
			ans += blk[j][i % j];
		}
		printf("%d\n", ans);
	}
	return 0;
}