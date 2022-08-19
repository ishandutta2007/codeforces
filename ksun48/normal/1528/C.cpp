#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -1;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -1;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};


template <bool VALS_EDGES> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(),dfsHld();}
	void dfsSz(int v = 0) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		trav(u, adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v = 0) {
		pos[v] = tim++;
		trav(u, adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v] + 1);
	}
	void modifyPath(int u, int v, int val) {
		process(u, v, [&](int l, int r) { tree->add(l, r, val); });
	}
	int queryPath(int u, int v) { // Modify depending on query
		int res = -1e9;
		process(u, v, [&](int l, int r) {
				res = max(res, tree->query(l, r));
		});
		return res;
	}
	int querySubtree(int v) { // modifySubtree is similar
		return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
};


namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std

void solve(){
	int n;
	cin >> n;
	vector<int> par1(n);
	vector<vector<int> > ch1(n);
	par1[0] = -1;
	for(int i = 1; i < n; i++){
		cin >> par1[i];
		par1[i]--;
		ch1[par1[i]].push_back(i);
	}
	vector<int> par2(n);
	vector<vector<int> > ch2(n);

	vector<vector<int> > e2(n);
	par2[0] = -1;
	for(int i = 1; i < n; i++){
		cin >> par2[i];
		par2[i]--;
		ch2[par2[i]].push_back(i);
		e2[i].push_back(par2[i]);
		e2[par2[i]].push_back(i);
	}
	vector<pair<int,int> > events;
	y_combinator([&](auto self, int v) -> void {
		events.push_back({0, v});
		for(int w : ch1[v]){
			self(w);
		}
		events.push_back({1, v});
	})(0);
	vector<int> st(n);
	vector<int> en(n);
	int T = 0;
	y_combinator([&](auto self, int v) -> void {
		st[v] = T;
		T++;
		for(int w : ch2[v]){
			self(w);
		}
		en[v] = T-1;
	})(0);

	vector<int> idx(n);
	for(int i = 0; i < n; i++){
		idx[st[i]] = i;
	}

	HLD<false> hld(e2);
	set<int> alive_set;
	int ans = 0;
	int cnt = 0;
	vector<int> used(n, 0);
	for(auto [type, v] : events){
		if(type == 0){
			int w = hld.queryPath(0, v);
			if(w >= 0){
				w = idx[w];
				if(used[w]){
					used[w] = 0;
					cnt--;
				}
			}
			hld.modifyPath(v, v, 1 + st[v]);
			alive_set.insert(st[v]);
			auto f = alive_set.upper_bound(st[v]);
			if(f == alive_set.end() || *f > en[v]){
				used[v] = 1;
				cnt++;
			}
		} else if(type == 1){
			hld.modifyPath(v, v, -(1 + st[v]));
			alive_set.erase(st[v]);
			if(used[v]){
				used[v] = 0;
				cnt--;
			}
			int w = hld.queryPath(0, v);
			if(w >= 0){
				w = idx[w];
				if(!used[w]){
					auto f = alive_set.upper_bound(st[w]);
					if(f == alive_set.end() || *f > en[w]){
						used[w] = 1;
						cnt++;
					}					
				}
			}
		} else assert(false);
		ans = max(ans, cnt);
	}
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}