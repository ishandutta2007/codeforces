#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for(string& a : s) cin >> a;
	pair<int,int> no = {-1e8, -1e8};
	vector<vector<pair<int,int> > > vis(n, vector<pair<int,int> >(m, no));
	vector<pair<int,int> > bfs;
	pair<int,int> st = no;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s[i][j] == 'S'){
				s[i][j] = '.';
				st = {i, j};
			}
		}
	}
	bfs.push_back(st);
	vis[st.first][st.second] = {0, 0};
	int z = 0;

	vector<int> dx = {1, 0, -1, 0};
	vector<int> dy = {0, 1, 0, -1};
	while(z < (int)bfs.size()){
		pair<int,int> loc = bfs[z];
		pair<int,int> wh = vis[loc.first][loc.second];
		z++;
		for(int g = 0; g < 4; g++){
			pair<int,int> nloc = loc;
			pair<int,int> nwh = wh;
			nloc.first += dx[g];
			nloc.second += dy[g];
			if(nloc.first < 0){
				nloc.first += n;
				nwh.first -= 1;
			} else if(nloc.second < 0){
				nloc.second += m;
				nwh.second -= 1;
			} else if(nloc.first >= n){
				nloc.first -= n;
				nwh.first += 1;
			} else if(nloc.second >= m){
				nloc.second -= m;
				nwh.second += 1;
			}
			if(s[nloc.first][nloc.second] == '#') continue;
			if(vis[nloc.first][nloc.second] == nwh) continue;
			if(vis[nloc.first][nloc.second] == no){
				vis[nloc.first][nloc.second] = nwh;
				bfs.push_back(nloc);
			} else {
				cout << "YES" << '\n';
				return 0;
			}
		}
	}
	cout << "NO" << '\n';
}