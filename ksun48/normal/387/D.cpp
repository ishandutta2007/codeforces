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

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<pair<int,int> > e(m);
	for(pair<int,int>& x : e){
		cin >> x.first >> x.second;
		x.first--; x.second--;
	}
	int ans = 1e8;
	for(int v = 0; v < n; v++){
		vector<vector<int> > g(n);
		vector<int> btoa(n, -1);
		int good = 0;
		int bad = 0;
		for(pair<int,int> x : e){
			if(x.first == v || x.second == v){
				good++;
			} else {
				bad++;
				g[x.first].push_back(x.second);
			}
		}
		int match = hopcroftKarp(g, btoa);
		int cost = (2*n-1) - good + (bad - match) + (n-1 - match);
		ans = min(cost, ans);
	}
	cout << ans << '\n';
}