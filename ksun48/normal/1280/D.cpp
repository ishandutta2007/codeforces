#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<vector<int> > edges;
vector<int> votes;

void chk_max(pair<int, ll>& a, pair<int, ll> b){
	if(b > a) a = b;
}

vector<pair<int, ll> > dfs(int v, int p){
	vector<pair<int, ll> > f = {{0, votes[v]}};
	for(int w : edges[v]){
		if(w == p) continue;
		vector<pair<int, ll> > x = dfs(w, v);
		vector<pair<int, ll> > newf(f.size() + x.size(), {0, -1e16});
		for(int i = 0; i < (int)f.size(); i++){
			for(int j = 0; j < (int)x.size(); j++){
				pair<int, ll> r = f[i], s = x[j];
				{
					chk_max(newf[i + j], {r.first + s.first, r.second + s.second});
				}
				{
					chk_max(newf[i + j + 1], {r.first + s.first + (s.second > 0), r.second});
				}
			}
		}
		f = newf;
	}
	return f;
}
void solve(){
	int n, m;
	cin >> n >> m;
	votes.assign(n, 0);
	edges.assign(n, {});
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		votes[i] -= x;
	}
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		votes[i] += x;
	}
	for(int i = 0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<pair<int,ll> > res = dfs(0, -1);
	int ans = res[m-1].first;
	if(res[m-1].second > 0) ans++;
	cout << ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--) solve();
}
// maximum # of villages, how many at top