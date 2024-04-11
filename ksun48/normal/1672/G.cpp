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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(string& x : s) cin >> x;
	vector<int> row(n, 0), col(m, 0);
	vector<int> rq(n, 0), cq(m, 0);
	UF uf(n + m);
	int nq = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c = s[i][j];
			if(c == '?'){
				nq++;
				uf.join(i, j+n);
				rq[i] = 1;
				cq[j] = 1;
			} else {
				row[i] ^= (c - '0');
				col[j] ^= (c - '0');
			}
		}
	}
	num ans = 0;
	if(n % 2 == 0 && m % 2 == 0){
		ans += pow(num(2), nq);
	} else if(n % 2 == 0){
		for(int x = 0; x < 2; x++){
			bool bad = false;
			int rows = 0;
			for(int i = 0; i < n; i++){
				if(row[i] != x && !rq[i]) bad = true;
				if(rq[i]) rows++;
			}
			if(!bad) ans += pow(num(2), nq - rows);
		}
	} else if(m % 2 == 0){
		for(int x = 0; x < 2; x++){
			bool bad = false;
			int cols = 0;
			for(int i = 0; i < m; i++){
				if(col[i] != x && !cq[i]) bad = true;
				if(cq[i]) cols++;
			}
			if(!bad) ans += pow(num(2), nq - cols);
		}
	} else {
		for(int x = 0; x < 2; x++){
			bool bad = false;
			int rows = 0;
			int cols = 0;
			for(int i = 0; i < n; i++){
				if(row[i] != x && !rq[i]) bad = true;
				if(rq[i]) rows++;
			}
			for(int i = 0; i < m; i++){
				if(col[i] != x && !cq[i]) bad = true;
				if(cq[i]) cols++;
			}
			vector<vector<int> > ccs(n+m);
			for(int i = 0; i < n+m; i++){
				ccs[uf.find(i)].push_back(i);
			}
			int nccs = 0;
			for(vector<int> r : ccs){
				if(r.size() > 1) nccs++;
				int tot = 0;
				for(int a : r){
					if(a < n){
						tot ^= x ^ row[a];
					} else {
						tot ^= x ^ col[a-n];
					}
				}
				if(tot) bad = true;
			}
			if(!bad) ans += pow(num(2), nq - rows - cols + nccs);
		}
	}
	cout << ans << '\n';
}