#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

template<typename T>
struct FenwickTree{
	int N;
	vector<T> ft;

	FenwickTree(int N, vector<T> & arr): N(N) {
		ft.resize(N + 1);
	}

	void update(int i, T value){
		i++;
		while (i <= N) {
			ft[i] += value;
			i += i & -i;
		}
	}

	void update(int l, int r, T value){
		update(l, value);
		update(r + 1, -value);
	}

	T query(int i){
		T res = 0;
		i++;
		while (i) {
			res += ft[i];
			i -= i & -i;
		}
		return res;
	}
};

vector<vector<int>> adj;

struct HeavyLight{
	int n;
	vector<int> parent, level, size, heavy, head, pos, ipos;
	int cur_pos;
	FenwickTree<int> * st;

	HeavyLight(int n, FenwickTree<int> * st): n(n), st(st){
		adj.resize(n), ipos.resize(n);
		parent.resize(n), level.resize(n), size.resize(n);
		heavy.resize(n, -1), head.resize(n), pos.resize(n);
	}

	void dfs(int u){
		size[u] = 1;
		int mx = 0;
		for(int v : adj[u]){
			if(v != parent[u]){
				parent[v] = u;
				level[v] = level[u] + 1;
				dfs(v);
				if(size[v] > mx){
					mx = size[v];
					heavy[u] = v;
				}
				size[u] += size[v];
			}
		}
	}

	void build(int u, int h){
		head[u] = h;
		pos[u] = cur_pos;
		ipos[cur_pos++] = u;
		if(heavy[u] != -1) build(heavy[u], h);
		for(int v : adj[u])
			if(v != parent[u] && v != heavy[u])
				build(v, v);
	}

	void init(int root = 0){
		cur_pos = 0;
		dfs(root);
		build(root, root);
	}

	int query(int a){
		return st->query(pos[a]);
	}
	
	int update(int a, int b, int k){
		while(head[a] != head[b]){
			if(level[head[a]] > level[head[b]]) swap(a, b);
			st->update(pos[head[b]], pos[b], k);
			b = parent[head[b]];
		}
		if(level[a] > level[b]) swap(a, b);
		st->update(pos[a], pos[b], k);
		return a;
	}
};

const int MX = 200005;
int n, q;
HeavyLight *ori[22], *top[22];

void main_() {
	cin >> n;
	
	forn (i, 22) {
		vi aux(n);
		ori[i] = new HeavyLight(n, new FenwickTree<int>(n, aux));
		top[i] = new HeavyLight(n, new FenwickTree<int>(n, aux));
	}
	
	forn (i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	
	forn (i, 22) {
		ori[i]->init();
		top[i]->init();
	}
	
	vi par = ori[0]->parent;
	par[0] = -1;
	
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		
		if (op == 1) {
			int v;
			cin >> v;
			v--;
			
			ll res = 0;
			forn (d, 21) {
				if (!v) {
					forr (j, d, 20)
						res += ori[j]->query(v);
					break;
				}
				res += top[d]->query(v);
				v = par[v];
			}
			
			cout << res << endl;
		} else {
			int u, v, k, d;
			cin >> u >> v >> k >> d;
			u--, v--;
			
			int lca = ori[d]->update(u, v, k);
			top[d]->update(u, v, k);
			if (d) top[d - 1]->update(lca, lca, k);
			
			while (lca && d) {
				lca = par[lca];
				d--;
				
				ori[d]->update(lca, lca, k);
				top[d]->update(lca, lca, k);
				if (d) top[d - 1]->update(lca, lca, k);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}