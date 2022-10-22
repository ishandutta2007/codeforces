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
typedef vector<ii> vii;

#define INF 1000000005
#define LINF 1000000000000000005
#define MOD 1000000007
#define MAXN 100005

int n, k;
int m;
vi adj[MAXN];
int q;

struct dsu {
	vi p, r;
	int comp;
	dsu(): comp(0) {}
	dsu(int n) {
		comp = n;
		p.clear(); r.clear();
		p.resize(n);
		r.resize(n);
		REP (i, 0, n) {
			p[i] = i;
			r[i] = 1;
		}
	}
	int find(int x) {
		if (p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	bool same(int a, int b) {
		return find(a) == find(b);
	}
	bool join(int a, int b) {
		int pa = find(a), pb = find(b);
		if (pa == pb) return 0;
		if (r[pa] < r[pb]) swap(pa, pb);
		if (r[pa] == r[pb]) r[pa]++;
		p[pb] = pa;
		comp--;
		return 1;
	}
};

dsu all[MAXN * 4];
void init(int cur, int lo, int hi) {
	if (lo == hi) {
		all[cur] = dsu(1);
	} else {
		int mid = lo + hi >> 1;
		int lc = cur * 2, rc = cur * 2 + 1;
		init(lc, lo, mid);
		init(rc, mid + 1, hi);
		all[cur] = dsu(hi - lo + 1);
		REP (i, lo, mid + 1) {
			all[cur].join(i - lo, all[lc].find(i - lo));
		}
		int gap = mid - lo + 1;
		REP (i, mid + 1, hi + 1) {
			all[cur].join(i - lo, all[rc].find(i - (mid + 1)) + gap);
		}
		RREP (i, mid, max(lo, mid - k + 1)) {
			for (int v : adj[i]) {
				if (v <= i || v > hi) continue;
				all[cur].join(i - lo, v - lo);
			}
		}
	}
}
void init() {
	init(1, 1, n);
}
int query(int s, int e, int cur, int lo, int hi) {
	if (lo == s && hi == e) {
		return all[cur].comp;
	}
	int mid = lo + hi >> 1;
	int lc = cur * 2, rc = cur * 2 + 1;
	if (e <= mid) return query(s, e, lc, lo, mid);
	else if (s > mid) return query(s, e, rc, mid + 1, hi);
	else {
		int lans = query(s, mid, lc, lo, mid),
		   	rans = query(mid + 1, e, rc, mid + 1, hi);
		int ans = lans + rans;
		int lower = max(s, mid - k + 1), upper = min(e, mid + k);
		dsu tmp = dsu(upper - lower + 1);
		REP (i, lower, upper + 1) {
			for (int j : adj[i]) {
				if (j < lower || j > upper) continue;
				bool a = i <= mid, b = j <= mid;
				if (a != b) continue;
				tmp.join(i - lower, j - lower);
			}
		}
		ans -= tmp.comp;
		REP (i, lower, upper + 1) {
			for (int j : adj[i]) {
				if (j < lower || j > upper) continue;
				tmp.join(i - lower, j - lower);
			}
		}
		ans += tmp.comp;
		return ans;
	}
}
int query(int s, int e) {
	return query(s, e, 1, 1, n);
}

int main() {
	scanf("%d%d", &n, &k);
	scanf("%d", &m);
	REP (i, 0, m) {
		int u, v; scanf("%d%d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	init();
	scanf("%d", &q);
	while (q--) {
		int l, r; scanf("%d%d", &l, &r);
		printf("%d\n", query(l, r));
	}
	return 0;
}

/*
10 5
3
5 7
8 9
3 6
3
7 10
6 8
7 8
*/