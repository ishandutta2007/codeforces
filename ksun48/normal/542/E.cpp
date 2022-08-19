#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int color[1001];
int cc[1001];
int vis[1001];
vector<int> edges[1001];
int n, m;
int works = 1;
int ncc = 0;
void dfs(int i){
	if(vis[i] == 1) return;
	vis[i] = 1;
	cc[i] = ncc;
	if(color[i] == -1){
		color[i] = 0;
	}
	for(int j = 0; j < edges[i].size(); j++){
		if(color[i] == color[edges[i][j]]){
			works = 0;
		} else if(color[edges[i][j]] == -1){
			cc[edges[i][j]] = ncc;
			color[edges[i][j]] = 1 - color[i];
			dfs(edges[i][j]);
		}
	}
}
int maxd[1000];
int dist[1000];
int used[1000];
set<pair<int,int> > something;
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for(int i = 0; i <= 1000; i++){
		color[i] = -1;
		vis[i] = 0;
		maxd[i] = 0;
	}
	for(int i = 0; i < n; i++){
		dfs(i);
		ncc++;
		if(works == 0){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		//cout << i << " " << cc[i] << endl;
	}
	for(int i = 0; i < n; i++){
		//cout << "i " << i << endl;
		something.clear();
		for(int j = 0; j < n; j++){
			dist[j] = 10000;
			used[j] = 0;
		}
		dist[i] = 0;
		something.insert(make_pair(0,i));
		while(1){
			int cur = -1;
			while(1){
				if(something.empty()){
					cur = -1;
					break;
				}
				int r = (*something.begin()).second;
				something.erase(something.begin());
				if(used[r] == 0){
					cur = r;
					break;
				}
			}
			if(cur == -1) break;
			//cout << cur << endl;
			used[cur] = 1;
			for(int j = 0; j < edges[cur].size(); j++){
				if(dist[cur]+1 < dist[edges[cur][j]]){
					dist[edges[cur][j]] = dist[cur]+1;
					something.insert(make_pair(dist[cur]+1, edges[cur][j]));
				}
			}
		}
		for(int j = 0; j < n; j++){
			if(dist[j] < 10000){
				//cout << j << " " << dist[j] << endl;
				maxd[cc[i]] = max(maxd[cc[i]], dist[j]);
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += maxd[i];
	}
	cout << ans << endl;


}