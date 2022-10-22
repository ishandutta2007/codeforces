#include <iostream>
#include <string>
#include <vector>
#define llint long long

using namespace std;

llint n, m;
llint G[105][105];
llint dist[105][105];
llint p[1000005];
vector<llint> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	char c;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> c;
			G[i][j] = c-'0';
			dist[i][j] = G[i][j];
			if(G[i][j] == 0) dist[i][j] = 1e9;
			if(i == j) dist[i][j] = 0;
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> p[i];
	ans.push_back(p[1]);
	
	llint v = p[1], pre = 1;
	for(int i = 2; i <= m; i++){
		if(dist[v][p[i]] < i - pre){
			//cout << v << endl;
			//cout << dist[v][p[i]] << " " << i-pre << endl;
			v = p[i-1], pre = i-1;
			ans.push_back(p[i-1]);
		}
	}
	if(ans.back() != p[m]) ans.push_back(p[m]);
	
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}