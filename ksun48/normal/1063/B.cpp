#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
	cin.sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	int r, c;
	cin >> r >> c;
	int x, y;
	cin >> x >> y;
	vector<string> grid(n+2);
	grid[0].resize(m+2, '*');
	grid[n+1].resize(m+2, '*');
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		grid[i+1] = '*' + s + '*';
	}
	int ans = 0;

	vector<vector<int> > vis(n+2, vector<int>(m+2, 0));
	vector<vector<pair<int,int> > > dist;
	dist.resize(1);
	dist[0].push_back({r,c});
	int cdist = 0;
	while(cdist < dist.size()){
		int s = 0;
		while(s < dist[cdist].size()){
			pair<int,int> a = dist[cdist][s];
			s++;
			if(vis[a.first][a.second]) continue;
			if(grid[a.first][a.second] == '*') continue;
			vis[a.first][a.second] = 1;
			int dy = a.second - c;
			assert((dy - cdist) % 2 == 0);
			int nl = 0;
			int nr = 0;
			if(dy < 0){
				nl = -dy;
			} else {
				nr = dy;
			}
			int v = (cdist - nl - nr) / 2;
			assert(v >= 0);
			nl += v;
			nr += v;
			if(nl <= x && nr <= y){
				ans++;
			}
			dist[cdist].push_back({a.first-1, a.second});
			dist[cdist].push_back({a.first+1, a.second});
			if(cdist + 1 == dist.size()){
				vector<pair<int,int> > emp;
				dist.push_back(emp);
			}
			dist[cdist+1].push_back({a.first, a.second-1});
			dist[cdist+1].push_back({a.first, a.second+1});
		}
		cdist++;
	}
	cout << ans << endl;
}