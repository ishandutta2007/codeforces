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

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

using num = modnum<998244353>;

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

using ll = int64_t;
void solve(){
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for(int& x : a){
		cin >> x;
	}
	vector<vector<int> > edges(n);
	vector<vector<int> > back_edges(n);
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		back_edges[v].push_back(u);
	}
	int sink = 0;
	while(!edges[sink].empty()) sink++;
	vector<int> ord;
	vector<int> vis(n, 0);
	y_combinator([&](auto self, int v) -> void {
		if(vis[v]) return;
		vis[v] = 1;
		for(int w : back_edges[v]){
			self(w);
		}
		ord.push_back(v);
	})(sink);
	vector<num> tcnt(n, 0);
	for(int i = 0; i < n; i++) tcnt[i] = a[i];
	for(int v : ord){
		for(int w : edges[v]){
			tcnt[w] += tcnt[v];
		}
	}
	int Z = n+1;
	int INF = 2 * Z + 2;
	vector<vector<int> > dp(n, vector<int>(Z+1, 0));
	for(int i = 0; i < n; i++){
		dp[i][0] += min(a[i], INF);
	}
	for(int v : ord){
		for(int w : edges[v]){
			for(int j = 0; j < n; j++){
				dp[w][min(j+1, Z)] += dp[v][j];
				dp[w][min(j+1, Z)] = min(dp[w][min(j+1, Z)], INF);
			}
		}
	}
	ll state = 0;
	int last_seen = 0;
	int used = 0;
	for(int t = 0; t <= Z; t++){
		state += dp[sink][t];
		if(state){
			last_seen = (t + 1);
			state--;
			used++;
		}
	}
	if(state == 0){
		cout << last_seen << '\n';
	} else {
		cout << (num(Z+1) + tcnt[sink] - used) << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}