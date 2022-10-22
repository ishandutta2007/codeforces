#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, m;
vector<llint> G[100005];
llint ans[100005];
llint cnt[100005];
llint base[5];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= m; i++){
		 cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
	
	llint id = 2;
	base[1] = 1, ans[1] = 1;
	for(int i = 2; i <= n; i++){
		bool flag = false;
		for(int j = 1; j < id; j++){
			if(G[i] == G[base[j]]){
				ans[i] = j;
				flag = true;
				break;
			}
		}
		if(flag) continue;
		if(id == 4){
			cout << -1 << endl;
			return 0;
		}
		ans[i] = id;
		base[id++] = i;
	}
	
	if(id != 4){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) cnt[ans[i]]++;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			if(ans[G[i][j]] == ans[i]){
				cout << -1 << endl;
				return 0;
			}
		}
		if((int)G[i].size() != n - cnt[ans[i]]){
			cout << -1 << endl;
			return 0;
		}
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}