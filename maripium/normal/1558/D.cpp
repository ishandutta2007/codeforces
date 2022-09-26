#include <bits/stdc++.h>

using namespace std;

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
		v -= MOD-o.v;
		v = (v < 0) ? v + MOD : v;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		v = (v < 0) ? v + MOD : v;
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
 
using num = modnum<998244353>;
 
mt19937 rng(58);

struct node {
	node *l, *r;
	int y;
	int lo, hi;
	int len;

	node(int _lo = 0, int _hi = 0) {
		l = r = nullptr;
		y = rng();
		lo = _lo;
		hi = _hi;
		len = hi - lo + 1;
	}

};

node* recalc(node *v) {
	if (!v) return v;
	v->len = v->hi - v->lo + 1;
	if (v->l) v->len += v->l->len;
	if (v->r) v->len += v->r->len;
	return v;
}

set<int> st;

node* merge(node *l, node *r) {
	if (!l) return r;
	if (!r) return l;
	if (l->y < r->y) {
		l->r = merge(l->r, r);
		return recalc(l);
	} else {
		r->l = merge(l, r->l);
		return recalc(r);
	}
}

pair<node*, node*> split(node* v, int id) {
	if (id == 0) return {nullptr, v};
	if (v->l) {
		if (v->l->len >= id) {
			auto [l, r] = split(v->l, id);
			v->l = r;
			return {l, recalc(v)};
		}
		id -= v->l->len;
	} 
	if (id <= v->hi - v->lo + 1) {
		int mi = v->lo + id - 1;
		node *l = new node(v->lo, mi);
		node *r = nullptr;
		if (mi < v->hi) {
			r = new node(mi + 1, v->hi);
		}
		return {merge(v->l, l), merge(r, v->r)};
	}
	id -= (v->hi - v->lo + 1);
	auto [l, r] = split(v->r, id);
	v->r = l;
	return {recalc(v), r};
}

int getFirst(node *v) {
	assert(v);
	if (v->l) return getFirst(v->l);
	return v->lo;
}

vector<num> fact(1, 1);

num choose(int X, int Y) {
	while (fact.size() <= X) {
		fact.push_back(fact.back() * fact.size());
	}
	return fact[X] / fact[Y] / fact[X - Y];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		set<int> st;
		int prv = 0;
		node* root = nullptr;
		for (int i = 1; i <= M; ++i) {
			int x, y; cin >> x >> y;
			if (x > prv + 1) {
				root = merge(root, new node(prv + 1, x - 1));
			}
			prv = x;
			auto [l, r] = split(root, y - 1);
			st.insert(getFirst(r));
			root = merge(merge(l, new node(x, x)), r);
		}
		int X = 2 * N - 1 - int(st.size());
		int Y = N;
		cout << choose(X, Y) << '\n';
	}
}