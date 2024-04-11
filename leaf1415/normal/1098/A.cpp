#include <iostream>
#include <vector>
#define llint long long

using namespace std;

int n;
vector<int> G[100005];
llint a[100005], s[100005];

bool dfs(int v, llint sum)
{
	if(s[v] == -1){
		if(G[v].size() == 0){
			a[v] = 0;
			return true;
		}
		llint mn = 1e18;
		for(int i = 0; i < G[v].size(); i++){
			mn = min(mn, s[G[v][i]]);
		}
		s[v] = mn;
	}
	a[v] = s[v] - sum;
	sum = s[v];
	if(a[v] < 0) return false;
	
	for(int i = 0; i < G[v].size(); i++){
		if(!dfs(G[v][i], sum)) return false;
	}
	return true;
}

int main(void)
{
	cin >> n;
	llint v;
	for(int i = 2; i <= n; i++){
		cin >> v;
		G[v].push_back(i);
	}
	for(int i = 1; i <= n; i++) cin >> s[i];
	
	if(!dfs(1, 0)){
		cout << -1 << endl;
		return 0;
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++){
		ans += a[i];
	}
	cout << ans << endl;
	
	return 0;
}