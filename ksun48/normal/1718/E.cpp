#include <bits/stdc++.h>
using namespace std;


template <typename T> T mod_inv_in_range(T a, T m) {
	// assert(0 <= a && a < m);
	T x = a, y = m;
	T vx = 1, vy = 0;
	while (x) {
		T k = y / x;
		y %= x;
		vy -= k * vx;
		std::swap(x, y);
		std::swap(vx, vy);
	}
	assert(y == 1);
	return vy < 0 ? m + vy : vy;
}

template <typename T> T mod_inv(T a, T m) {
	a %= m;
	a = a < 0 ? a + m : a;
	return mod_inv_in_range(a, m);
}

template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
	static_assert(MOD_ > 0, "MOD must be positive");

private:
	using ll = long long;

	int v;

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
		res.v = mod_inv_in_range(v, MOD);
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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

template <typename U, typename V> struct pairnum {
	U u;
	V v;

	pairnum() : u(0), v(0) {}
	pairnum(long long val) : u(val), v(val) {}
	pairnum(const U& u_, const V& v_) : u(u_), v(v_) {}

	friend std::ostream& operator << (std::ostream& out, const pairnum& n) { return out << '(' << n.u << ',' << ' ' << n.v << ')'; }
	friend std::istream& operator >> (std::istream& in, pairnum& n) { long long val; in >> val; n = pairnum(val); return in; }

	friend bool operator == (const pairnum& a, const pairnum& b) { return a.u == b.u && a.v == b.v; }
	friend bool operator != (const pairnum& a, const pairnum& b) { return a.u != b.u || a.v != b.v; }

	pairnum inv() const {
		return pairnum(u.inv(), v.inv());
	}
	pairnum neg() const {
		return pairnum(u.neg(), v.neg());
	}
	pairnum operator- () const {
		return pairnum(-u, -v);
	}
	pairnum operator+ () const {
		return pairnum(+u, +v);
	}

	pairnum& operator ++ () {
		++u, ++v;
		return *this;
	}
	pairnum& operator -- () {
		--u, --v;
		return *this;
	}

	pairnum& operator += (const pairnum& o) {
		u += o.u;
		v += o.v;
		return *this;
	}
	pairnum& operator -= (const pairnum& o) {
		u -= o.u;
		v -= o.v;
		return *this;
	}
	pairnum& operator *= (const pairnum& o) {
		u *= o.u;
		v *= o.v;
		return *this;
	}
	pairnum& operator /= (const pairnum& o) {
		u /= o.u;
		v /= o.v;
		return *this;
	}

	friend pairnum operator ++ (pairnum& a, int) { pairnum r = a; ++a; return r; }
	friend pairnum operator -- (pairnum& a, int) { pairnum r = a; --a; return r; }
	friend pairnum operator + (const pairnum& a, const pairnum& b) { return pairnum(a) += b; }
	friend pairnum operator - (const pairnum& a, const pairnum& b) { return pairnum(a) -= b; }
	friend pairnum operator * (const pairnum& a, const pairnum& b) { return pairnum(a) *= b; }
	friend pairnum operator / (const pairnum& a, const pairnum& b) { return pairnum(a) /= b; }
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

struct UF {
    int n;
    vector<int> par;
    UF(int _n) : n(_n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        par[a] = b;
        return (a != b);
    }
};

using ll = int64_t;
const int P = int(1e9) + 7;
// using num = pairnum<modnum<P>, modnum<P>>;
using num = ll;

num B;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

	// B = num(mt() % P, mt() % P);
	B = num(mt()) | 1;

	int N, M;
	cin >> N >> M;
	int TR = (N > M);
	if(TR){
		swap(N, M);
	}
	assert(N <= M);
	vector<vector<vector<int> > > colors(2);
	for(int grid = 0; grid < 2; grid++){
		colors[grid].assign(N, vector<int>(M));
		if(TR){
			for(int j = 0; j < M; j++){
				for(int i = 0; i < N; i++){
					cin >> colors[grid][i][j];
				}
			}
		} else {
			for(int i = 0; i < N; i++){
				for(int j = 0; j < M; j++){
					cin >> colors[grid][i][j];
				}
			}
		};
	}
	vector<vector<vector<pair<int,int> > > > vertex_orders(2);
	vector<vector<ll> > hashes(2);
	for(int grid = 0; grid < 2; grid++){
		vector<vector<vector<pair<int,int> > > > adj(2);
		adj[0].resize(N);
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				if(colors[grid][i][j] > 0){
					adj[0][i].push_back({colors[grid][i][j], j});
				}
			}
			sort(adj[0][i].begin(), adj[0][i].end());
		}
		adj[1].resize(M);
		for(int j = 0; j < M; j++){
			for(int i = 0; i < N; i++){
				if(colors[grid][i][j] > 0){
					adj[1][j].push_back({colors[grid][i][j], i});
				}
			}
			sort(adj[1][j].begin(), adj[1][j].end());
		}
		vertex_orders[grid].resize(N);
		hashes[grid].resize(N);
		for(int st = 0; st < N; st++){
			vector<vector<int> > vis(2);
			vis[0].assign(N, -1);
			vis[1].assign(M, -1);
			int vid = 0;
			vector<pair<int,int> > vertex_order;
			num H = 0;
			y_combinator(
				[&](auto self, int side, int i) -> void {
					if(vis[side][i] >= 0){
						H = H * B + vis[side][i];
						return;
					}
					vis[side][i] = vid;
					vid++;
					vertex_order.push_back({side, i});
					H = H * B + vis[side][i];
					for(auto [c, j] : adj[side][i]){
						H = H * B - c;
						self(side ^ 1, j);
						H = H * B - c;
					}
				}
			)(0, st);
			vertex_orders[grid][st] = vertex_order;
			// ll hash = ll(int(H.u)) * P + ll(int(H.v));
			ll hash = H;
			hashes[grid][st] = hash;
		}
	}
	vector<int> assignmentA(N, -1);
	vector<int> assignmentB(M, -1);
	map<ll, set<int> > b_hashes;
	for(int i = 0; i < N; i++){
		b_hashes[hashes[1][i]].insert(i);
	}
	auto fail = [](){
		cout << -1 << '\n';
		exit(0);
	};
	vector<int> usedA(N, 0);
	vector<int> usedB(M, 0);
	for(int i = 0; i < N; i++){
		if(assignmentA[i] >= 0) continue;
		ll H = hashes[0][i];
		if(b_hashes[H].empty()) fail();
		int r = *b_hashes[H].begin();
		auto ord0 = vertex_orders[0][i];
		auto ord1 = vertex_orders[1][r];
		if(ord0.size() != ord1.size()) fail();
		for(int z = 0; z < (int)ord0.size(); z++){
			auto [side0, v0] = ord0[z];
			auto [side1, v1] = ord1[z];
			if(side0 != side1) fail();
			if(side0 == 0){
				if(assignmentA[v0] >= 0) fail();
				if(usedA[v1]) fail();
				assignmentA[v0] = v1;
				usedA[v1] = 1;
				b_hashes[hashes[1][v1]].erase(v1);
			} else {
				if(assignmentB[v0] >= 0) fail();
				if(usedB[v1]) fail();
				assignmentB[v0] = v1;
				usedB[v1] = 1;
			}
		}
	}
	int j = 0;
	for(int i = 0; i < M; i++){
		if(assignmentB[i] >= 0) continue;
		while(usedB[j]) j++;
		assignmentB[i] = j;
		j++;
	}
	vector<tuple<int, int, int> > ops;
	for(int i = 0; i < N; i++){
		while(assignmentA[i] != i){
			ops.push_back({0, i, assignmentA[i]});
			swap(assignmentA[i], assignmentA[assignmentA[i]]);
		}
	}
	for(int i = 0; i < M; i++){
		while(assignmentB[i] != i){
			ops.push_back({1, i, assignmentB[i]});
			swap(assignmentB[i], assignmentB[assignmentB[i]]);
		}
	}
	cout << ops.size() << '\n';
	for(auto [t, x, y] : ops){
		cout << (1 + (t ^ TR)) << ' ' << (x+1) << ' ' << (y+1) << '\n';
	}
}