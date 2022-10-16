#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int64,int64> pii;
typedef vector<int64> vi;
typedef pair<int64,pii> edge;

const int64 oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
const int64 maxn = 200010;
const int64 maxl = 20;

int64 _f[maxn];
int64 _root(int64 u) { return u == _f[u] ? u : _f[u] = _root(_f[u]); }
bool join(int64 u, int64 v) { 
	u = _root(u), v = _root(v); 
	if (u == v) return false;
	if (rand() & 1) swap(u, v);
	_f[u] = v; return true;
}

vector<pii> tree[maxn];
pii lcaT[maxn][maxl];
int64 height[maxn];

void dfs(int64 s, int64 f){
	for (int64 i = 1; i < maxl; ++i){
		int64 lca_f = lcaT[lcaT[s][i - 1].first][i - 1].first;
		int64 max_w = max(lcaT[s][i - 1].second, lcaT[lcaT[s][i - 1].first][i - 1].second);
		lcaT[s][i] = pii(lca_f, max_w);
	}

	for (auto nxt : tree[s]) if (nxt.first != f){
		height[nxt.first] = height[s] + 1;
		lcaT[nxt.first][0] = pii(s, nxt.second);
		dfs(nxt.first, s);
	}
}

int64 lca(int64 u, int64 v){
	if (height[u] < height[v]) swap(u, v);
	int64 d = height[u] - height[v];
	int64 ans = 0;
	
	for (int64 i = 0; d; ++i){
		if (d & (1 << i)){
			d ^= 1 << i;
			ans = max(ans, lcaT[u][i].second);
			u = lcaT[u][i].first;
		}
	}

	if (u == v) return ans;

	for (int64 i = maxl - 1; i >= 0; --i){
		if (lcaT[u][i].first != lcaT[v][i].first){
			ans = max(ans, lcaT[u][i].second);
			ans = max(ans, lcaT[v][i].second);
			u = lcaT[u][i].first;
			v = lcaT[v][i].first;
		}
	}

	ans = max(ans, lcaT[u][0].second);
	ans = max(ans, lcaT[v][0].second);

	assert(u != v);
	assert(lcaT[u][0].first == lcaT[v][0].first);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int64 n, m;
	cin >> n >> m;
	vector<edge> redge(m);
	vector<edge> sedge(m);

	for (int64 i = 1; i <= n; ++i) _f[i] = i;
	
	for (int64 i = 0; i < m; ++i){
		cin >> redge[i].second.first >> redge[i].second.second >> redge[i].first;
		sedge[i] = redge[i];
	}

	int64 mst = 0;
	sort(sedge.begin(), sedge.end());
	for (auto e : sedge)
		if (join(e.second.first, e.second.second)){
			tree[e.second.first].push_back(pii(e.second.second, e.first));
			tree[e.second.second].push_back(pii(e.second.first, e.first));
			mst += e.first;
		}

	for (int64 i = 0; i < maxl; ++i)
		lcaT[0][i] = pii(0, 0);

	lcaT[1][0] = pii(0, 0);
	height[1] = 1;
	dfs(1, 0);

	for (int64 i = 0; i < m; ++i){
		int64 q = lca(redge[i].second.first, redge[i].second.second);
		cout << mst - q + redge[i].first << endl;
	}

	return 0;
}