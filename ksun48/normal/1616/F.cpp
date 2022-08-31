#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MOD = 3;

int inv(int x){
	return x;
}

int solveLinear(vector<vi>& A, vi& b, vi& x) {
	int n = sz(A), m = sz(x), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		int v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = A[r][c]) != 0)
				br = r, bc = c, bv = v;
		if (bv == 0) {
			rep(j,i,n) if (b[j] != 0) return -1;
			break;
		}
		swap(A[i], A[br]);
		swap(b[i], b[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = inv(A[i][i]);
		rep(j,i+1,n) {
			int fac = (A[j][i] * bv) % MOD;
			b[j] -= fac * b[i];
			b[j] %= MOD;
			rep(k,i+1,m){
				A[j][k] -= fac*A[i][k];
				A[j][k] %= MOD;
			}
		}
		rank++;
	}

	x.assign(m, 0);
	for (int i = rank; i--;) {
		b[i] *= inv(A[i][i]);
		b[i] %= MOD;
		x[col[i]] = b[i];
		rep(j,0,i){
			b[j] -= A[j][i] * b[i];
			b[j] %= MOD;
		}
	}
	return rank; // (multiple solutions if rank < m)
}

int solveLinear_help(vector<vi>& A) {
	int n = sz(A);
	if(!n) return 0;
	int m = sz(A[0]), rank = 0, br, bc;
	if (n) assert(sz(A[0]) == m);
	vi col(m); iota(all(col), 0);

	rep(i,0,n) {
		int v, bv = 0;
		rep(r,i,n) rep(c,i,m)
			if ((v = A[r][c]) != 0)
				br = r, bc = c, bv = v;
		if (bv == 0) {
			break;
		}
		swap(A[i], A[br]);
		swap(col[i], col[bc]);
		rep(j,0,n) swap(A[j][i], A[j][bc]);
		bv = inv(A[i][i]);
		rep(j,i+1,n) {
			int fac = (A[j][i] * bv) % MOD;
			if(fac){
				rep(k,0,m){
					A[j][k] -= fac*A[i][k];
					A[j][k] %= MOD;
				}
			}
		}
		rank++;
	}
	for(vector<int>& x : A){
		vector<int> nx(m);
		for(int i = 0; i < m; i++){
			nx[col[i]] = x[i];
		}
		x = nx;
	}
	return rank; // (multiple solutions if rank < m)
}

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > A;
	vector<tuple<int, int, int> > e(m);
	map<pair<int,int>, int> id;
	for(int i = 0; i < m; i++){
		auto& [u, v, w] = e[i];
		cin >> u >> v >> w;
		u--; v--;
		id[{u, v}] = id[{v, u}] = i;
	}
	for(int a = 0; a < n; a++){
		for(int b = a+1; b < n; b++){
			for(int c = b+1; c < n; c++){
				if(id.count({a, b}) && id.count({b, c}) && id.count({a, c})){
					int r = id[{a, b}];
					int s = id[{b, c}];
					int t = id[{a, c}];
					vector<int> co(m, 0);
					co[r] = co[s] = co[t] = 1;
					A.push_back(co);
				}
			}
		}
	}
	solveLinear_help(A);
	vector<vector<int> > nA;
	vector<int> nB;
	for(vector<int> x : A){
		for(int& y : x){
			y %= MOD;
			if(y < 0) y += MOD;
		}
		if(x == vector<int>(m, 0)) continue;
		nA.push_back(x);
		nB.push_back(0);
	}
	for(int i = 0; i < m; i++){
		auto& [u, v, w] = e[i];
		if(w != -1){
			vector<int> co(m, 0);
			co[id[{u, v}]]++;
			nA.push_back(co);
			nB.push_back(w-1);
		}
	}
	vector<int> x(m, 0);
	if(solveLinear(nA, nB, x) >= 0){
		for(int& y : x){
			y %= MOD;
			if(y < 0) y += MOD;
			cout << (y+1) << ' ';
		}
		cout << '\n';
	} else {
		cout << -1 << '\n';
	}
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}