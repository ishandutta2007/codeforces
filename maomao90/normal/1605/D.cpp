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

int t;
int n;
vi adj[MAXN];
bool col[MAXN];
int ans[MAXN];

void dfs(int u, int p) {
	for (int v : adj[u]) {
		if (v == p) continue;
		col[v] = 1 - col[u];
		dfs(v, u);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		REP (i, 1, n + 1) {
			adj[i].clear();
		}
		REP (i, 1, n) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].pb(b);
			adj[b].pb(a);
		}
		col[1] = 0;
		dfs(1, -1);
		int cnt = 0;
		REP (i, 1, n + 1) {
			cnt += col[i];
		}
		bool use = 1;
		if (cnt > n - cnt) {
			cnt = n - cnt;
			use = 0;
		}
		vi f, s;
		REP (k, 0, 20) {
			REP (i, 1 << k, min(n + 1, 1 << k + 1)) {
				if (cnt & (1 << k)) {
					f.pb(i);
				} else {
					s.pb(i);
				}
			}
		}
		REP (i, 1, n + 1) {
			if (col[i] == use) {
				debug("%d %d\n", i, f.back());
				ans[i] = f.back();
				f.pop_back();
			} else {
				ans[i] = s.back();
				s.pop_back();
			}
		}
		assert(f.empty() && s.empty());
		REP (i, 1, n + 1) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}