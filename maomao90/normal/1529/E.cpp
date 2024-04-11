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

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 300005

struct node {
	ll lo, hi;
	ll val, lazy;
	node *l, *r;
	node(ll lo, ll hi): lo(lo), hi(hi), val(0), lazy(-1), l(nullptr), r(nullptr) {}
	void makeChild() {
		if (lo != hi && l == nullptr) {
			ll mid = lo + hi >> 1;
			l = new node(lo, mid), r = new node(mid + 1, hi);
		}
	}
	void propo() {
		if (lazy == -1) return;
		val = lazy;
		makeChild();
		if (lo != hi) {
			l -> lazy = lazy;
			r -> lazy = lazy;
		}
		lazy = -1;
	}
	void update(ll s, ll e, ll v) {
		if (lo >= s && hi <= e) {
			lazy = v;
			propo();
			return;
		}
		makeChild();
		propo();
		l -> propo(); r -> propo();
		ll mid = lo + hi >> 1;
		if (s <= mid) l -> update(s, e, v);
		if (e > mid) r -> update(s, e, v);
		val = max(l -> val, r -> val);
	}
	ll query(ll s, ll e) {
		propo();
		if (lo >= s && hi <= e) return val;
		makeChild();
		ll mid = lo + hi >> 1;
		if (e <= mid) return l -> query(s, e);
		else if (s > mid) return r -> query(s, e);
		else return max(l -> query(s, e), r -> query(s, e));
	}
	~node() {
		if (l != nullptr) delete l;
		if (r != nullptr) delete r;
	}
} *root;

int t;
int n;
vi aadj[MAXN], badj[MAXN];

int cnt = 1;
int pre[MAXN], pst[MAXN];
void dfsb(int u, int p) {
	pre[u] = cnt++;
	for (int v : badj[u]) {
		dfsb(v, u);
	}
	pst[u] = cnt;
}

int dfs(int u) {
	int res = 0;
	for (int v : aadj[u]) {
		if (root -> query(pre[v], pst[v] - 1) == 0) {
			root -> update(pre[v], pst[v] - 1, v);
			mxto(res, dfs(v) + 1);
			root -> update(pre[v], pst[v] - 1, 0);
		} else {
			int tmp = root -> query(pre[v], pst[v] - 1);
			if (pre[tmp] <= pre[v] & pst[tmp] >= pst[v]) {
				root -> update(pre[tmp], pst[tmp] - 1, 0);
				root -> update(pre[v], pst[v] - 1, v);
				mxto(res, dfs(v));
				root -> update(pre[v], pst[v] - 1, 0);
				root -> update(pre[tmp], pst[tmp] - 1, tmp);
			} else {
				mxto(res, dfs(v));
			}
		}
	}
	return res;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		cnt = 1;
		REP (i, 1, n + 5) {
			aadj[i].clear();
			badj[i].clear();
		}
		REP (i, 2, n + 1) {
			int p; scanf("%d", &p);
			aadj[p].pb(i);
		}
		REP (i, 2, n + 1) {
			int p; scanf("%d", &p);
			badj[p].pb(i);
		}
		root = new node(0, n + 5);
		dfsb(1, -1);
		printf("%d\n", dfs(1));
	}
}