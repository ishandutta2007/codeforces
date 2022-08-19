#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef vector<pii> vpi;

struct Tree {
	typedef int T;
	const T LOW = -1234567890;
	T f(T a, T b) { return max(a, b); }

	int n;
	vi s;
	vector<vector<int> > stuff;
	Tree() {}
	Tree(int m, T def=0) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		stuff.resize(2 * n);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int l, int r, int id) {
		return que(1, l, r, 0, n, id);
	}
	T que(int pos, int l, int r, int lo, int hi, int id) {
		if (r <= lo || hi <= l) return LOW;
		if (l <= lo && hi <= r){
			stuff[pos].push_back(id);
			return s[pos];
		}
		int m = (lo + hi) / 2;
		return f(que(2 * pos, l, r, lo, m, id),
				que(2 * pos + 1, l, r, m, hi, id));
	}
};

struct Node {
	int d, par, val, chain = -1, pos = -1;
	vector<int> stuff;
};

struct Chain {
	int par, val;
	vector<int> nodes;
	Tree tree;
};

struct HLD {
	typedef int T;
	const T LOW = -(1<<29);
	void f(T& a, T b) { a = max(a, b); }

	vector<Node> V;
	vector<Chain> C;

	HLD(vector<vpi>& g) : V(sz(g)) {
		dfs(0, -1, g, 0);
		trav(c, C){
			c.tree.init(sz(c.nodes), 0);
			for (int ni : c.nodes)
				c.tree.update(V[ni].pos, V[ni].val);
		}
	}

	void update(int node, T val) {
		Node& n = V[node]; n.val = val;
		if (n.chain != -1) C[n.chain].tree.update(n.pos, val);
	}

	int pard(Node& nod) {
		if (nod.par == -1) return -1;
		return V[nod.chain == -1 ? nod.par : C[nod.chain].par].d;
	}

	// query all *edges* between n1, n2
	pair<T, int> query(int i1, int i2, int id) {
		T ans = LOW;
		while(i1 != i2) {
			Node n1 = V[i1], n2 = V[i2];
			if (n1.chain != -1 && n1.chain == n2.chain) {
				int lo = n1.pos, hi = n2.pos;
				if (lo > hi) swap(lo, hi);
				f(ans, C[n1.chain].tree.query(lo, hi, id));
				i1 = i2 = C[n1.chain].nodes[hi];
			} else {
				if (pard(n1) < pard(n2))
					n1 = n2, swap(i1, i2);
				if (n1.chain == -1){
					f(ans, n1.val);
					V[i1].stuff.push_back(id);
					i1 = n1.par;
				} else {
					Chain& c = C[n1.chain];
					if(n1.pos){
						f(ans, c.tree.query(n1.pos, sz(c.nodes), id));
					} else {
						f(ans, c.tree.s[1]);
						c.tree.stuff[1].push_back(id);
					}
					i1 = c.par;
				}
			}
		}
		return make_pair(ans, i1);
	}

	pii dfs(int at, int par, vector<vpi>& g, int d) {
		V[at].d = d; V[at].par = par;
		int sum = 1, ch, nod, sz;
		tuple<int,int,int> mx(-1,-1,-1);
		trav(e, g[at]){
			if (e.first == par) continue;
			tie(sz, ch) = dfs(e.first, at, g, d+1);
			V[e.first].val = e.second;
			sum += sz;
			mx = max(mx, make_tuple(sz, e.first, ch));
		}
		tie(sz, nod, ch) = mx;
		if (2*sz < sum) return pii(sum, -1);
		if (ch == -1) { ch = sz(C); C.emplace_back(); }
		V[nod].pos = sz(C[ch].nodes);
		V[nod].chain = ch;
		C[ch].par = at;
		C[ch].nodes.push_back(nod);
		return pii(sum, ch);
	}
};

struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int add_var() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f^1].push_back(j);
		gr[j^1].push_back(f);
	}
	void set_value(int x) { either(x, x); }

	void at_most_one(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = add_var();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		trav(e, gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		++time;
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = time;
			if (values[x>>1] == -1)
				values[x>>1] = !(x&1);
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

// variable number
int dostuff(TwoSat& ts, Tree& t, int id){
	int z = ts.add_var();
	if(id >= t.s.size()){
		return z;
	} else {
		ts.at_most_one(t.stuff[id]);
		int uses = ts.add_var();
		for(int q : t.stuff[id]){
			ts.either(~q, uses);
		}
		int lz = dostuff(ts, t, 2 * id);
		int rz = dostuff(ts, t, 2 * id + 1);
		ts.either(~uses, ~lz);
		ts.either(~uses, ~rz);
		ts.either(~uses, z);
		ts.either(~lz, z);
		ts.either(~rz, z);
		return z;
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;

	vector<vpi> graph(n);
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back({b,0});
		graph[b].push_back({a,0});
	}
	int m;
	cin >> m;
	HLD hld(graph);
	for(int i = 0; i < m; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		hld.query(a, b, i);
		hld.query(c, d, ~i);
	}
	TwoSat ts(m);
	for(Node& v : hld.V){
		ts.at_most_one(v.stuff);
	}
	for(Chain& c : hld.C){
		dostuff(ts, c.tree, 1);
	}
	if(ts.solve()){
		cout << "YES" << '\n';
		for(int i = 0; i < m; i++){
			int r = 2 - ts.values[i];
			cout << r << '\n';
		}
	} else {
		cout << "NO" << '\n';
	}
}