#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll modinv(ll a, ll m) {
	assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}

template <int MOD_> struct modnum {
	private:
	int v;
	public:
	static const int MOD = MOD_;

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
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
		return *this *= (~o);
	}

	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<int(1e9) + 7>;

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}

vector<num> fact;
vector<num> ifact;

void init(){
	fact = {1};
	for(int i = 1; i < 1100000; i++) fact.push_back(i * fact[i-1]);
	ifact.resize(fact.size());
	ifact.back() = 1 / fact.back();
	for(int i = (int)ifact.size() - 1; i > 0; i--) ifact[i-1] = i * ifact[i];
}

num ncr(int n, int k){
	if(k < 0 || k > n) return 0;
	return fact[n] * ifact[k] * ifact[n-k];
}

vector<int> par, depth;
vector<vector<int> > edges, ch;

void dfs(int v, int p, int d){

	par[v] = p;
	if(p >= 0) ch[p].push_back(v);
	depth[v] = d;

	for(int w : edges[v]){
		if(w == p) continue;
		dfs(w, v, d+1);
	}
}

int bottom(int u, int v){
	if(u == par[v]) return v;
	if(v == par[u]) return u;
	assert(false);
}

struct UF {
    int n;
    vector<int> par;
    UF(int n) : n(n) {
        for(int i = 0; i < n; i++) par.push_back(i);
    }
    int find(int a){
        if(a != par[a]) par[a] = find(par[a]);
        return par[a];
    }
    void join(int a, int b){
        par[find(a)] = find(b);
    }
};
void fail(){
	cout << 0 << '\n';
	exit(0);
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	init();
	int n;
	cin >> n;
	edges.resize(n), par.resize(n), depth.resize(n), ch.resize(n);
	vector<int> in_seen(n, 0), out_seen(n, 0), up_seen(n, 0), down_seen(n, 0);
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0, -1, 0);
	vector<vector<int> > in_edges(n), out_edges(n);
	vector<vector<pair<int,int> > > through(n);
	for(int _a = 0; _a < n; _a++){
		int a = _a;
		int b;
		cin >> b;
		if(b == 0) continue;
		b--;
		if(a == b) fail();
		vector<int> sa;
		{
			vector<int> sb;
			while(depth[a] > depth[b]){
				if(up_seen[a]) fail();
				sa.push_back(a);
				up_seen[a] = true;
				a = par[a];
			}
			while(depth[b] > depth[a]){
				if(down_seen[b]) fail();
				sb.push_back(b);
				down_seen[b] = true;
				b = par[b];
			}
			while(a != b){
				if(up_seen[a]) fail();
				sa.push_back(a);
				up_seen[a] = true;
				a = par[a];
				if(down_seen[b]) fail();
				sb.push_back(b);
				down_seen[b] = true;
				b = par[b];
			}
			sa.push_back(a);
			reverse(sb.begin(), sb.end());
			for(int x : sb) sa.push_back(x);
		}
		in_edges[sa[0]].push_back(sa[1]);
		out_edges[sa[(int)sa.size()-1]].push_back(sa[(int)sa.size()-2]);
		for(int i = 1; i + 1 < (int)sa.size(); i++){
			through[sa[i]].push_back({sa[i-1], sa[i+1]});
		}
	}

	UF uf(n);
	num ans = 1;
	for(int v = 0; v < n; v++){
		int deg = (int)(edges[v].size());

		vector<pair<int,int> > joined = through[v];
		for(pair<int,int>& a : joined){
			a.first = bottom(a.first, v);
			a.second = bottom(a.second, v);
		}
		bool known_start = true;
		if(!in_edges[v].empty() && !out_edges[v].empty()){
			joined.push_back({bottom(in_edges[v].front(), v), bottom(out_edges[v].front(), v)});
		} else if(in_edges[v].empty() && out_edges[v].empty()){
			known_start = false;
		}
		int ncycles = 0;
		for(pair<int,int> x : joined){
			if(uf.find(x.first) == uf.find(x.second)){
				ncycles++;
			} else {
				uf.join(x.first, x.second);
			}
		}
		if(ncycles == 0){
			ans *= fact[deg - int(joined.size()) - int(known_start)];
		} else if(ncycles == 1 && known_start && deg == (int)joined.size()){
			ans *= 1;
		} else {
			ans = 0;
			break;
		}
	}
	cout << (int)ans << '\n';
}