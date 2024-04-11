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
	if(g.empty()) return 0;
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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	ll M;
	cin >> n >> M;
	ll easy = M / 3;
	vector<ll> stuff(n);
	for(ll& x : stuff) cin >> x;
	for(ll x : stuff){
		if(2*x + 1 > M){
			cout << -1 << '\n';
			exit(0);
		}
	}
	vector<ll> big, small;
	for(ll x : stuff){
		if(x <= easy){
			small.push_back(x);
		} else {
			big.push_back(x);
		}
	}
	int L = (int)big.size();
	int R = (int)small.size();
	vector<vector<int> > g(L);
	for(int i = 0; i < L; i++){
		for(int j = 0; j < R; j++){
			if(big[i] % small[j] == 0 && (big[i] * 2 + small[j] <= M)){
				g[i].push_back(j);
			}
		}
	}
	vector<int> btoa(small.size(), -1);
	if(hopcroftKarp(g, btoa) != L){
		cout << -1 << '\n';
		exit(0);
	}
	vector<pair<ll, ll> > ans;
	for(int i = 0; i < R; i++){
		if(btoa[i] == -1){
			ans.push_back({small[i] * 3, small[i] * 2});
		} else {
			int j = btoa[i];
			ans.push_back({big[j] * 2 + small[i], big[j] + small[i]});
		}
	}
	cout << ans.size() << '\n';
	for(auto [x, y] : ans){
		cout << x << ' ' << y << '\n';
	}
}