/*input
5
1 2 1
4 3 1
3 5 1
1 3 1
5
1 1
1 5
2 4
2 1
3 5
*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define __builtin_popcount __builtin_popcountll
#define int long long
#define bit(x,y) ((x>>y)&1LL)
#define loop(i,l,r) for(int i=(int)l; i<=(int)r; i++)
#define rloop(i,l,r) for(int i=(int)l; i>=(int)r; i--)
const int N = 100005;
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
	return os << '(' << a.first << ", " << a.second << ')';
}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &a) {
	os << '[';
	for (unsigned int i = 0; i < a.size(); i++)
		os << a[i] << (i < a.size() - 1 ? ", " : "");
	os << ']';
	return os;
}

int n;
vector<vector<pair<int, int> > > a(N);
const int mod = 1e9 + 7;

void norm(int &x) {x %= mod; x += (x < 0 ? mod : 0);}
struct LCAOn {
	pair<int, int> tour[2 * N], rmq[2 * N][22];
	int depth[N], par[N], dis[N], sta[N], en[N], lg2[2 * N], Time = 0;
	bool firstTime = true;
	void dfs(int u, int p) {
		tour[++Time] = {depth[u], u}; sta[u] = Time;
		par[u] = p;
		for (auto v : a[u])
			if (v.fi != p)depth[v.fi] = depth[u] + 1, dis[v.fi] = dis[u] + v.se, dfs(v.fi, u);
		tour[++Time] = {depth[u], u}; en[u] = Time;
	}
	void build_rmq() {
		for (int i = 1; i <= Time; ++i)
			rmq[i][0] = tour[i];
		for (int j = 1; (1 << j) <= Time; ++j)
			for (int i = 1; i + (1 << j) - 1 <= Time; ++i)
				rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
	}
	int lca(int u, int v) {
		if (sta[v] < sta[u]) swap(u, v);
		if (en[u] >= en[v]) return u;
		int dist = lg2[sta[v] - en[u] + 1];
		auto ans = min(rmq[en[u]][dist], rmq[sta[v] - (1 << dist) + 1][dist]);
		return par[ans.second];
	}
	int distance(int u, int v) {
		int p = lca(u, v);
		int ret = dis[u] + dis[v] - 2 * dis[p];
		norm(ret);
		return ret;
	}
	void init() {
		if (firstTime)
			for (int i = 1; i < 2 * N; i++) lg2[i] = log2(i);
		firstTime = false; Time = 0;
		dfs(1, 1);
		build_rmq();
	}
} LCA;

struct data {
	int cnt, dis1, dis2;
	data(int _cnt = 0, int _dis1 = 0, int _dis2 = 0): cnt(_cnt), dis1(_dis1), dis2(_dis2) {};
};

void norm(data &x) {
	norm(x.dis1); norm(x.dis2);
}

data up[N], down[N];

bool inSubtree(int p, int u) {
	if (LCA.lca(u, p) == p) return true;
	return false;
}

int calAllTree(int u) {
	return (up[u].dis2 + down[u].dis2) % mod;
}

int calInSub(int root, int u) {
	if (root == 1) return calAllTree(u);
	int w = LCA.distance(root, u);
	int ret = up[root].dis2 + 2 * w * up[root].dis1 + up[root].cnt * w % mod * w % mod; norm(ret);
	ret = calAllTree(u) - ret; norm(ret);
	return ret;
}

int calOutSub(int root, int u) {
	int w = LCA.distance(root, u);
	int ret = down[root].dis2 + 2 * w * down[root].dis1 + down[root].cnt * w % mod * w;
	norm(ret);
	return ret;
}

void dfsUp(int u, int p) {
	auto cur = down[u];
	cur.cnt += up[u].cnt; cur.dis1 += up[u].dis1; cur.dis2 += up[u].dis2;
	norm(cur);
	for (auto it : a[u]) {
		int v = it.fi; int w = it.se;
		if (v == p) continue;
		auto tmp = cur;
		tmp.cnt -= down[v].cnt; tmp.dis1 -= down[v].dis1 + w * down[v].cnt; tmp.dis2 -= down[v].dis2 + 2 * w * down[v].dis1 + down[v].cnt * w % mod * w;
		norm(tmp);
		up[v].cnt += tmp.cnt; up[v].dis1 += tmp.dis1 + w * tmp.cnt; up[v].dis2 += tmp.dis2 + 2 * w * tmp.dis1 + tmp.cnt * w % mod * w;
		norm(up[v]);
		dfsUp(v, u);
	}
}

void dfsDown(int u, int p) {
	for (auto it : a[u]) {
		int v = it.fi; int w = it.se;
		if (v != p) {
			dfsDown(v, u);
			down[u].cnt += down[v].cnt; down[u].dis1 += down[v].dis1 + w * down[v].cnt; down[u].dis2 += down[v].dis2 + 2 * w * down[v].dis1 + down[v].cnt * w % mod * w;
			norm(down[u]);
		}
	}
	down[u].cnt++;
}

void prepDis() {
	dfsDown(1, 1);
	dfsUp(1, 1);
}


void preCheck() {
	loop(u, 1, n) {
		int tup = 0; int tdown = 0;
		loop(v, 1, n) {
			if (inSubtree(u, v)) tdown += LCA.distance(u, v) * LCA.distance(u, v) % mod;
			else tup += LCA.distance(u, v) * LCA.distance(u, v) % mod;
		}
		norm(tup); norm(tdown);
		assert(tup == up[u].dis2);
	}
}

signed main() {
#ifndef UncleGrandpa
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
	cin >> n;
	loop(i, 1, n - 1) {
		int u, v, w; cin >> u >> v >> w;
		a[u].push_back(mp(v, w));
		a[v].push_back(mp(u, w));
	}
	LCA.init();
	prepDis();
	// preCheck();
	int q; cin >> q;
	loop(_, 1, q) {
		int u, v; cin >> u >> v;
		int ret = 0;
		if (inSubtree(v, u)) ret = 2 * calInSub(v, u) - calAllTree(u);
		else ret = 2 * calOutSub(v, u) - calAllTree(u);
		norm(ret);
		cout << ret << endl;
	}
}