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

using num = modnum<int(1e9)+7>;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, k, L;
	cin >> n >> k >> L;
	vector<int> x(n), y(n), col(n);
	for(int i = 0; i < n; i++){
		cin >> x[i] >> y[i] >> col[i];
		col[i]--;
	}
	set<int> xv;
	for(int a : x) xv.insert(a);
	int lastx = -1;

	num ans = 0;
	for(int sx : xv){
		num x1p = sx - lastx;
		lastx = sx;
		vector<vector<int> > color_where(k);
		for(int i = 0; i < n; i++){
			if(x[i] < sx) continue;
			color_where[col[i]].push_back(i);
		}
		map<int, vector<pair<int,int> > > inserts;
		for(int c = 0; c < k; c++){
			set<pair<int,int> > stars;
			stars.insert({sx-1, L});
			stars.insert({L, -1});
			sort(color_where[c].begin(), color_where[c].end(), [&](int a, int b){
				return tie(y[a], x[a]) > tie(y[b], x[b]);
			});
			for(int a : color_where[c]){
				int X = x[a];
				int Y = y[a];
				auto f = prev(stars.lower_bound({X, 0}));
				while(true){
					auto g = next(f);
					if(g == stars.end()) break;
					inserts[Y].push_back({g->first-1, f->second-1});
					f = g;
				}
				while(true){
					auto g = stars.lower_bound({X, 0});
					if(g->second >= 0){
						stars.erase(g);
					} else {
						break;
					}
				}
				stars.insert({X, Y});
			}
			auto f = stars.begin();
			while(true){
				auto g = next(f);
				if(g == stars.end()) break;
				inserts[-1].push_back({g->first-1, f->second-1});
				f = g;
			}
		}
		set<pair<int, int> > stars;
		stars.insert({sx-1, L+1});
		stars.insert({L+1, -1});
		int ly = -1;
		num carea = num(L) * num(L - sx);
		for(auto aa : inserts){
			num y1p = aa.first - ly;
			ly = aa.first;
			ans += x1p * y1p * carea;
			for(auto g : aa.second){
				g.first = min(g.first, L-1);
				g.second = min(g.second, L-1);
				if(g.first < sx) continue;
				while(true){
					auto q = prev(stars.lower_bound({g.first, L}));
					if(q->first <= g.first && q->second <= g.second){
						carea += num(q->first - prev(q)->first) * num(q->second - next(q)->second);
						stars.erase(q);
					} else {
						break;
					}
				}
				{
					auto q = stars.lower_bound({g.first, 0});
					if(q->second >= g.second) continue;
				}
				stars.insert(g);
				auto q = stars.find(g);
				carea -= num(q->first - prev(q)->first) * num(q->second - next(q)->second);
			}
		}
	}
	cout << ans << '\n';
}