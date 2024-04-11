// time-limit: 4000
// problem-url: https://codeforces.com/contest/1591/problem/E
// Be kind and compassionate to one another, forgiving each other,
// just as in Christ God forgave you. Ephesians 4:32
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
#define MAXN 1000005

struct thing {
	int l, k, id;
};

int n, q;
int a[MAXN];
vi adj[MAXN];
vector<thing> qry[MAXN];
int ans[MAXN];

int occ[MAXN], p[MAXN], invp[MAXN], lb[MAXN];
inline void swp(int a, int b) {
	swap(invp[p[a]], invp[p[b]]);
	swap(p[a], p[b]);
}
void dfs(int u) {
	int hi = lb[++occ[a[u]]] - 1;
	swp(invp[a[u]], hi);
	lb[occ[a[u]]]--;
	for (thing t : qry[u]) {
		if (lb[t.l] + t.k - 1 > n) {
			ans[t.id] = -1;
		} else {
			ans[t.id] = p[lb[t.l] + t.k - 1];
		}
	}
	for (int v : adj[u]) {
		dfs(v);
	}
	lb[occ[a[u]]]++;
	int lo = lb[occ[a[u]]--] - 1;
	swp(invp[a[u]], lo);
}

int main() {
	int _t = 1;
   	scanf("%d", &_t);
	while (_t--) {
		scanf("%d%d", &n, &q);
		REP (i, 0, n + 1) {
			adj[i].clear();
			qry[i].clear();
			p[i] = invp[i] = i;
			lb[i] = n + 1;
			occ[i] = 0;
		}
		lb[0] = 1;
		REP (i, 1, n + 1) {
			scanf("%d", &a[i]);
		}
		REP (i, 2, n + 1) {
			int p; scanf("%d", &p);
			adj[p].pb(i);
		}
		REP (i, 0, q) {
			int v, l, k; scanf("%d%d%d", &v, &l, &k);
			qry[v].pb({l, k, i});
		}
		dfs(1);
		REP (i, 0, q) {
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
	return 0;
}