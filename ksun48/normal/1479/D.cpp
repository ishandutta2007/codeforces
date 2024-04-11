#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class T>
struct RMQ {
	vector<vector<T>> jmp;
	RMQ(const vector<T>& V) : jmp(1, V) {
		for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
			jmp.emplace_back(sz(V) - pw * 2 + 1);
			rep(j,0,sz(jmp[k]))
				jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
		}
	}
	T query(int a, int b) {
		assert(a < b); // or return inf if a == b
		int dep = 31 - __builtin_clz(b - a);
		return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
	}
};

struct LCA {
	int T = 0;
	vi time, path, ret;
	RMQ<int> rmq;

	LCA(vector<vi>& C) : time(sz(C)), rmq((dfs(C,0,-1), ret)) {}
	void dfs(vector<vi>& C, int v, int par) {
		time[v] = T++;
		trav(y, C[v]) if (y != par) {
			path.push_back(v), ret.push_back(time[v]);
			dfs(C, y, v);
		}
	}

	int lca(int a, int b) {
		if (a == b) return a;
		tie(a, b) = minmax(time[a], time[b]);
		return path[rmq.query(a, b)];
	}
	//dist(a,b){return depth[a] + depth[b] - 2*depth[lca(a,b)];}
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

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

	static int minv(int a, int m) {
		a %= m;
		assert(a);
		return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);
	}

public:

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }

	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum inv() const {
		modnum res;
		res.v = minv(v, MOD);
		return res;
	}
	friend modnum inv(const modnum& m) { return m.inv(); }
	modnum neg() const {
		modnum res;
		res.v = v ? MOD-v : 0;
		return res;
	}
	friend modnum neg(const modnum& m) { return m.neg(); }

	modnum operator- () const {
		return neg();
	}
	modnum operator+ () const {
		return modnum(*this);
	}

	modnum& operator ++ () {
		v ++;
		if (v == MOD) v = 0;
		return *this;
	}
	modnum& operator -- () {
		if (v == 0) v = MOD;
		v --;
		return *this;
	}
	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= o.inv();
	}

	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<int(1e9)+7>;

num B;

struct node {
	node *l, *r;
	pair<num, num> h;
};

pair<num, num> combine(pair<num, num> a, pair<num, num> b){
	return {a.first + a.second * b.first, a.second * b.second};
}
node* build(int lx, int rx){
	node* v = new node();
	if(lx == rx){
		v->l = v->r = nullptr;
		v->h = {0, B};
	} else{
		v->l = build(lx, (lx + rx) / 2);
		v->r = build((lx + rx) / 2 + 1, rx);
		v->h = combine(v->l->h, v->r->h);
	}
	return v;
}
node* upd(node* cur, int x, int val, int lx, int rx){
	if(x < lx || x > rx) return cur;
	node* v = new node();
	if(lx == rx){
		v->l = v->r = nullptr;
		v->h = {val ^ int(cur->h.first), B};
	} else {
		v->l = upd(cur->l, x, val, lx, (lx+rx)/2);
		v->r = upd(cur->r, x, val, (lx+rx)/2 + 1, rx);
		v->h = combine(v->l->h, v->r->h);
	}
	return v;
}
int compare (node* c1, node* c2, int qlx, int qrx, int lx, int rx){
	if(qrx < lx || rx < qlx){
		return -1;
	}
	if(qlx <= lx && rx <= qrx){
		if(c1->h == c2->h) return -1;
		if(lx == rx){
			return lx;
		}
	}
	int f = compare(c1->l, c2->l, qlx, qrx, lx, (lx+rx)/2);
	if(f >= 0) return f;
	f = compare(c1->r, c2->r, qlx, qrx, (lx+rx)/2 + 1, rx);
	return f;
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	B = rng();
	int n, q;
	cin >> n >> q;
	vector<vector<int> > edges(n);
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	vector<node*> s(n);
	s[0] = build(0, n);
	y_combinator(
		[&](auto self, int v, int p) -> void {
			s[v] = upd(s[v], a[v], 1, 0, n);
			for(int w : edges[v]){
				if(w == p) continue;
				s[w] = s[v];
				self(w, v);
			}
		}
	)(0, -1);
	LCA lca(edges);
	for(int i = 0; i < q; i++){
		int u, v, l, r;
		cin >> u >> v >> l >> r;
		u--; v--;
		int sp = lca.lca(u, v);
		node* z = upd(s[u], a[sp], 1, 0, n);
		cout << compare(s[v], z, l, r, 0, n) << '\n';
	}
}