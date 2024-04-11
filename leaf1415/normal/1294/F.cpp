#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>
#include <map>
#define inf 1e18

using namespace std;
typedef pair<int, int> P;

int n;
vector<int> G[200005];
int lmax[200005], rmax[200005];
map<P, int> mp;

int dfs(int v, int p)
{
	int ret = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		ret = max(ret, dfs(G[v][i], v));
	}
	ret++;
	return mp[P(p, v)] = ret;
}

void dfs2(int v, int p)
{
	int mx = 0;
	for(int i = 0; i < G[v].size(); i++){
		mx = max(mx, mp[P(v, G[v][i])]);
		lmax[i+1] = mx;
	}
	mx = 0;
	for(int i = (int)G[v].size()-1; i >= 0; i--){
		mx = max(mx, mp[P(v, G[v][i])]);
		rmax[i+1] = mx;
	}
	lmax[0] = rmax[(int)G[v].size()+1] = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		mp[P(G[v][i], v)] = max(lmax[i], rmax[i+2])+1;
	}
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs2(G[v][i], v);
	}
}

void dfs3(int v, int p, int d, vector<P> &vec)
{
	int cnt = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		cnt++;
		dfs3(G[v][i], v, d+1, vec);
	}
	if(cnt == 0){
		vec.push_back(P(d, v));
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, -1);
	dfs2(1, -1);
	
	/*for(auto it = mp.begin(); it != mp.end(); it++){
		cout << it->first.first << " " << it->first.second << " " << it->second << endl;
	}*/
	
	bool flag = false; int ans = 0, ans_v;
	for(int i = 1; i <= n; i++){
		if(G[i].size() <= 2) continue;
		flag = true;
		vector<int> vec;
		for(int j = 0; j < G[i].size(); j++){
			vec.push_back(mp[P(i, G[i][j])]);
		}
		sort(vec.rbegin(), vec.rend());
		int sum = 0;
		for(int j = 0; j < 3; j++) sum += vec[j];
		if(ans < sum){
			ans = sum;
			ans_v = i;
		}
	}
	if(!flag){
		cout << n-1 << endl;
		vector<int> ans;
		for(int i = 1; i <= n; i++){
			if(G[i].size() == 1) ans.push_back(i);
		}
		for(int i = 1; i <= n; i++){
			if(G[i].size() == 2){
				ans.push_back(i);
				break;
			}
		}
		for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
		return 0;
	}
	
	cout << ans << endl;
	
	vector<P> avec;
	for(int i = 0; i < G[ans_v].size(); i++){
		int u = G[ans_v][i];
		vector<P> vec;
		dfs3(u, ans_v, 0, vec);
		sort(vec.rbegin(), vec.rend());
		avec.push_back(vec.front());
	}
	sort(avec.rbegin(), avec.rend());
	for(int i = 0; i < 3; i++) cout << avec[i].second << " "; cout << endl;
	
	return 0;
}