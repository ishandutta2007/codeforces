#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m, k;
vector<llint> G[100005];
llint dep[100005], par[100005];

llint ans, ans_u, ans_v;
void dfs(int v, int p, int d)
{
	//cout << v << " " << d << endl;
	par[v] = p, dep[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(dep[G[v][i]] < inf/2){
			if(dep[G[v][i]] >= dep[v]) continue;
			llint len = dep[v]-dep[G[v][i]]+1;
			if(ans > len){
				ans = len;
				ans_u = G[v][i], ans_v = v;
			}
		}
		else dfs(G[v][i], v, d+1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	llint u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	ans = inf;
	for(int i = 1; i <= n; i++) dep[i] = inf;
	
	dfs(1, 0, 0);
	
	if(ans > inf/2){
		vector<llint> ovec, evec;
		for(int i = 1; i <= n; i++){
			if(dep[i]%2) ovec.push_back(i);
			else evec.push_back(i);
		}
		cout << 1 << endl;
		if(ovec.size() > evec.size()){
			for(int i = 0; i < (k+1)/2; i++) cout << ovec[i] << " ";
		}
		else{
			for(int i = 0; i < (k+1)/2; i++) cout << evec[i] << " ";
		}
		cout << endl;
		return 0;
	}
	
	//cout << ans << " " << ans_u << " " << ans_v << endl;
	
	vector<llint> vec;
	v = ans_v;
	while(1){
		vec.push_back(v);
		if(v == ans_u) break;
		v = par[v];
	}
	
	//for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";cout << endl;
	
	if(vec.size() <= k){
		cout << 2 << endl;
		cout << vec.size() << endl;
		for(int i = 0; i < vec.size(); i++) cout << vec[i] << " ";
		cout << endl;
	}
	else{
		cout << 1 << endl;
		for(int i = 0; i < (k+1)/2; i++) cout << vec[i*2] << " ";
		cout << endl;
	}

	return 0;
}