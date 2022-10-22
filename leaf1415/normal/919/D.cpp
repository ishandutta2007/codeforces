#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
string s;
vector<int> G[300005];
vector<int> revG[300005];

bool used[300005];
vector<int> topo;
int rtopo[300005];
int dp[300005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	rtopo[v] = (n-1) - topo.size();
	topo.push_back(v);
}

int main(void)
{
	cin >> n >> m;
	cin >> s;
	s = " " + s;
	
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		revG[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
		if(!used[i]) tpsort(i);
	}
	reverse(topo.begin(), topo.end());
	
	for(int i = 0; i < topo.size(); i++){
		for(int j = 0; j < G[topo[i]].size(); j++){
			if(rtopo[G[topo[i]][j]] <= i){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	int ans = 0;
	for(int i = 0; i < 26; i++){
		for(int j = 1; j <= n; j++) dp[j] = 0;
		for(int j = 0; j < topo.size(); j++){
			for(int k = 0; k < G[topo[j]].size(); k++){
				if(s[topo[j]] - 'a' == i) dp[G[topo[j]][k]] = max(dp[G[topo[j]][k]], dp[topo[j]] + 1);
				else dp[G[topo[j]][k]] = max(dp[G[topo[j]][k]], dp[topo[j]]);
			}
		}
		for(int j = 0; j < topo.size(); j++) if(s[topo[j]] - 'a' == i) dp[topo[j]]++;
		
		int tmp = 0;
		for(int j = 1; j <= n; j++) tmp = max(tmp, dp[j]);
		ans = max(ans, tmp);
	}
	
	cout << ans << endl;
	return 0;
}