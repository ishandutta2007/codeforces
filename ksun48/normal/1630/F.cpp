#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

bool dfs(int a, int L, vector<vi>& g, vi& btoa, vi& A, vi& B) {
	if (A[a] != L) return 0;
	A[a] = -1;
	trav(b, g[a]) if (B[b] == L + 1) {
		B[b] = 0;
		if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(vector<vi>& g, vi& btoa) {
	int res = 0;
	vi A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(all(A), 0);
		fill(all(B), 0);
		/// Find the starting nodes for BFS (i.e. layer 0).
		cur.clear();
		trav(a, btoa) if(a != -1) A[a] = -1;
		rep(a,0,sz(g)) if(A[a] == 0) cur.push_back(a);
		/// Find all layers using bfs.
		for (int lay = 1;; lay++) {
			bool islast = 0;
			next.clear();
			trav(a, cur) trav(b, g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				}
				else if (btoa[b] != a && !B[b]) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}
			if (islast) break;
			if (next.empty()) return res;
			trav(a, next) A[a] = lay;
			cur.swap(next);
		}
		/// Use DFS to scan for augmenting paths.
		rep(a,0,sz(g))
			res += dfs(a, 0, g, btoa, A, B);
	}
}

const int R = int(5e4) + 10;
vector<vector<int> > factors(R);

void init(){
	for(int i = 1; i < R; i++){
		for(int j = i; j < R; j += i){
			factors[j].push_back(i);
		}
	}
}
vector<int> id(R, -1);
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) cin >> x;
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i++){
		id[a[i]] = i;
	}
	vector<pair<int,int> > edges;
	for(int i = 0; i < n; i++){
		for(int fact : factors[a[i]]){
			if(id[fact] == -1) continue;
			edges.push_back({id[fact], i});
		}
	}
	vector<vector<int> > g(2*n);
	for(auto [x, y] : edges){
		if(x != y){
			g[x].push_back(y);
			g[x+n].push_back(y+n);
		}
		g[x].push_back(y+n);
	}
	vector<int> btoa(2*n, -1);
	int val = hopcroftKarp(g, btoa);
	cout << (val - n) << '\n';
	for(int i = 0; i < n; i++){
		id[a[i]] = -1;
	}
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	init();
	int T;
	cin >> T;
	while(T--) solve();
}