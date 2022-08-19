#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m, t;
	cin >> n >> m >> t;
	vector<string> s(n);
	for(int i = 0; i < n; i++) cin >> s[i];
	vector<vector<int> > d(n, vector<int>(m, 1e9));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(j+1 < m && s[i][j] == s[i][j+1]){
				d[i][j] = d[i][j+1] = 0;
			}
			if(i+1 < n && s[i+1][j] == s[i][j]){
				d[i][j] = d[i+1][j] = 0;
			}
		}
	}
	vector<pair<int,int> > bfs;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(d[i][j] == 0) bfs.push_back({i, j});
		}
	}
	int st = 0;
	while(st < (int)bfs.size()){
		pair<int,int> v = bfs[st];
		int x = v.first;
		int y = v.second;
		st++;
		vector<int> dx = {1, 0, -1, 0};
		vector<int> dy = {0, 1, 0, -1};
		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			int nd = d[x][y] + 1;
			if(nd >= d[nx][ny]) continue;
			d[nx][ny] = nd;
			bfs.push_back({nx, ny});
		}
	}
	for(int _ = 0; _ < t; _++){
		int x, y;
		long long p;
		cin >> x >> y >> p;
		x--; y--;
		if(bfs.empty()){
			cout << s[x][y] << '\n';
		} else {
			long long nflips = max(0ll, p - d[x][y]);
			char res = s[x][y];
			if(nflips & 1) res ^= '0' ^ '1';
			cout << res << '\n';
		}
	}
}