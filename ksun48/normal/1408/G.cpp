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

struct UF {
    int n;
    vector<int> par;
    vector<int> vert, edge;
    vector<vector<num> > dp;
    UF(int _n) : n(_n), vert(_n, 1), edge(_n, 0), dp(_n, {0, 1}) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    bool join(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b){
	        edge[b] += 1;
        } else {
        	vector<num> newdp(dp[a].size() + dp[b].size() - 1);
        	for(int j = 1; j < (int)dp[a].size(); j++){
        		for(int k = 1; k < (int)dp[b].size(); k++){
        			newdp[j+k] += dp[a][j] * dp[b][k];
        		}
        	}
        	dp[b] = newdp;
	        par[a] = b;
	        vert[b] += vert[a];
	        edge[b] += edge[a];
        	edge[b] += 1;
        }
        if(vert[b] * (vert[b] - 1) / 2 == edge[b]){
        	dp[b][1] += 1;
        }
        return (a != b);
    }
};

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<vector<int> > a(n, vector<int>(n));
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> a[i][j];
	vector<pair<int,int> > c;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			c.push_back({i, j});
		}
	}
	sort(c.begin(), c.end(), [&](pair<int,int> f, pair<int,int> g){
		return a[f.first][f.second] < a[g.first][g.second];
	});
	UF uf(n);
	for(pair<int,int> g : c){
		uf.join(g.first, g.second);
	}
	vector<num> ans = uf.dp[uf.find(0)];
	for(int i = 1; i <= n; i++){
		cout << ans[i] << ' ';
	}
	cout << '\n';
}