#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> sp(k);
	for(int i = 0; i < k; i++){
		cin >> sp[i];
		sp[i]--;
	}
	vector<vector<int> > edges(n);
	for(int i = 0; i < m; i++){
		int r, s;
		cin >> r >> s;
		r--; s--;
		edges[r].push_back(s);
		edges[s].push_back(r);
	}
	vector<int> d1(n, -1);
	{
		vector<int> bfs;
		int s = 0;
		bfs.push_back(0);
		d1[0] = 0;
		while(s < (int)bfs.size()){
			int v = bfs[s];
			int d = d1[v];
			s++;
			for(int w : edges[v]){
				if(d1[w] == -1){
					bfs.push_back(w);
					d1[w] = d+1;
				}
			}
		}
	}
	vector<int> d2(n, -1);
	{
		vector<int> bfs;
		int s = 0;
		bfs.push_back(n-1);
		d2[n-1] = 0;
		while(s < (int)bfs.size()){
			int v = bfs[s];
			int d = d2[v];
			s++;
			for(int w : edges[v]){
				if(d2[w] == -1){
					bfs.push_back(w);
					d2[w] = d+1;
				}
			}
		}
	}
	vector<pair<int,int> > dists;
	for(int r : sp){
		dists.push_back({d1[r], d2[r]});
	}
	sort(dists.begin(), dists.end(), [&](pair<int,int> a, pair<int,int> b){
		return a.first + b.second < b.first + a.second;
	});
	int ans = 0;
	int cmax = -1e9;
	for(pair<int,int> x : dists){
		ans = max(ans, cmax + x.second + 1);
		cmax = max(cmax, x.first);
	}
	ans = min(ans, d1[n-1]);
	cout << ans << '\n';
}