#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<pair<int,int> > eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges);
	vector<pair<int,int> > ret, s = {{src, -1}};
	// D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x, eid;
		tie(x, eid) = s.back();
		int y, e, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back({x, eid}); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin(), ret.rend()};
}
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	vector<vector<int> > answers;
	int ans = 0;
	for(int z = 0; z <= 20; z++){
		vector<pair<int,int> > q;
		vector<vector<pair<int,int> > > graph(1 << z);
		for(int i = 0; i < n; i++){
			int r = a[i] % (1 << z);
			int s = b[i] % (1 << z);
			q.push_back({r, s});
			graph[r].push_back({s, i});
			graph[s].push_back({r, i});
		}
		vector<pair<int,int> > g = eulerWalk(graph, n, q[0].first);
		if(g.empty()) break;
		vector<int> path;
		for(int i = 1; i < (int)g.size(); i++){
			int r = g[i].second;
			if(g[i-1].first == q[r].first){
				path.push_back(2*r);
				path.push_back(2*r+1);
			} else {
				path.push_back(2*r+1);
				path.push_back(2*r);				
			}
		}
		answers.push_back(path);
		ans = z;
	}
	cout << ans << '\n';
	for(int x : answers.back()){
		cout << x+1 << ' ';
	}
	cout << '\n';
}