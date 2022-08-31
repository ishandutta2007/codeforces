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

using num = modnum<998244353>;

int n;
vector<vector<int> > edges, ch;
vector<int> sz, par, depth;
vector<int> st, en;

const int MAXJ = 22;
vector<vector<int> > jump_binary;

int jump(int v, int d){
	assert(depth[v] >= d);
	for(int j = MAXJ-1; j >= 0; j--){
		if(d & (1 << j)){
			v = jump_binary[v][j];
		}
	}
	return v;
}

num global_ans = 0;
vector<num> fix;

vector<num> delta;
int T;

void dfs(int v, int p, int d){
	par[v] = p;
	if(p >= 0) ch[p].push_back(v);
	jump_binary[v][0] = (p == -1) ? v : p;
	for(int j = 1; j < MAXJ; j++){
		jump_binary[v][j] = jump_binary[jump_binary[v][j-1]][j-1];
	}
	depth[v] = d;

	st[v] = T;
	T++;

	sz[v] = 1;
	for(int w : edges[v]){
		if(w == p) continue;
		dfs(w, v, d+1);
		sz[v] += sz[w];
	}
	en[v] = T-1;
}
void dfs_fix(int v, int p, num carry){
	if(fix[v] != 0) carry += (n - sz[v]) * fix[v];
	if(p >= 0 && fix[p] != 0) carry -= sz[v] * fix[p];
	delta[v] += carry;
	for(int w : ch[v]){
		dfs_fix(w, v, carry);
	}
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q;
	cin >> n >> Q;
	edges.resize(n), sz.resize(n), par.resize(n), depth.resize(n), st.resize(n), en.resize(n), ch.resize(n);
	delta.assign(n, 0), fix.assign(n, 0);
	jump_binary.assign(n, vector<int>(MAXJ, 0));
	for(int i = 0; i < n-1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	T = 0;
	dfs(0, -1, 0);
	const int B = 512;
	num invn = num(1) / num(n);

	vector<pair<int,num> > pending_ops;
	for(int q = 1; q <= Q; q++){
		int type, v;
		cin >> type >> v;
		v--;
		if(type == 1){
			int _d;
			cin >> _d;
			num d = _d;
			global_ans += d * sz[v];

			pending_ops.push_back({v, d});
		} else {
			num r = global_ans + delta[v];
			// answer query on v
			for(auto x : pending_ops){
				int v2 = x.first;
				if(v == v2){
					r += (n - sz[v2]) * x.second;
				} else if(st[v2] < st[v] && en[v] <= en[v2]){
					int del = depth[v] - depth[v2];
					assert(del > 0);
					int chi = jump(v, del-1);
					r += (n - int(sz[v2]) - int(sz[chi])) * x.second;
				}
			}
			cout << (int)(r * invn) << '\n';
		}
		if(q % B == 0){
			fix.assign(n, 0);
			for(auto x : pending_ops){
				fix[x.first] += x.second;
			}
			dfs_fix(0, -1, 0);
			pending_ops = {};
		}
	}
}