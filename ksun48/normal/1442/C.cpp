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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	using ll = long long;
	int n, m;
	cin >> n >> m;
	vector<vector<vector<int> > > edges(2, vector<vector<int> > (n));
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[0][u].push_back(v);
		edges[1][v].push_back(u);
	}
	const ll MAXR = 1e16;
	{
		ll ans = MAXR;
		int R = 20;
		vector<ll> dist(n, MAXR);
		dist[0] = 0;
		for(int r = 0; r < R; r++){
			vector<bool> vis(n, false);
			priority_queue<pair<ll, int> > cur;
			for(int i = 0; i < n; i++) cur.push({-dist[i], i});
			while(!cur.empty()){
				pair<ll, int> z = cur.top();
				cur.pop();
				int v = z.second;
				if(vis[v]) continue;
				vis[v] = true;
				for(int w : edges[r&1][v]){
					if(dist[w] > dist[v] + 1){
						dist[w] = dist[v] + 1;
						cur.push({-dist[w], w});
					}
				}
			}
			ans = min(ans, dist[n-1] + (1ll << r) - 1);
		}
		if(ans < MAXR){
			cout << ans << '\n';
			return 0;
		}
	}
	{
		vector<vector<int> > e2(2*n);
		for(int v = 0; v < n; v++){
			for(int w : edges[0][v]){
				e2[v].push_back(w);
				e2[w+n].push_back(v+n);
			}
		}
		ll SW = 1e8;

		vector<ll> dist(2*n, MAXR);
		dist[0] = 0;
		vector<bool> vis(2*n, false);
		priority_queue<pair<ll, int> > cur;
		for(int i = 0; i < 2*n; i++) cur.push({-dist[i], i});
		while(!cur.empty()){
			pair<ll, int> z = cur.top();
			cur.pop();
			int v = z.second;
			if(vis[v]) continue;
			vis[v] = true;
			for(int w : e2[v]){
				if(dist[w] > dist[v] + 1){
					dist[w] = dist[v] + 1;
					cur.push({-dist[w], w});
				}
			}
			{
				int w = (v + n) % (2*n);
				if(dist[w] > dist[v] + SW){
					dist[w] = dist[v] + SW;
					cur.push({-dist[w], w});
				}
			}
		}
		ll ans = min(dist[n-1], dist[n+n-1]);
		assert(ans < MAXR);
		ll nsw = ans / SW;
		ll ne = ans % SW;
		num z = pow(num(2), nsw) + ne - 1;
		cout << z << '\n';
	}
}