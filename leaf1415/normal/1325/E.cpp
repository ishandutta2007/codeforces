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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint x = (s); x  t; x++)

using namespace std;

llint n;
llint a[100005];
set<llint> S;
llint prime[1000005];
vector<llint> G[1000005];
vector<llint> vec;
llint dist[1000005];
llint ans = 3005;

void bfs(llint s)
{
	for(int i = 0; i < vec.size(); i++) dist[vec[i]] = inf;
	dist[s] = 0;
	
	queue<llint> Q;
	Q.push(s);
	
	llint v;
	while(Q.size()){
		v = Q.front();
		Q.pop();
		if(dist[v] > ans/2+3) return;
		for(int i = 0; i < G[v].size(); i++){
			llint u = G[v][i];
			if(dist[u] < dist[v]) continue;
			else if(dist[u] < inf){
				ans = min(ans, dist[u] + dist[v] + 1);
				return;
			}
			dist[u] = dist[v] + 1;
			Q.push(u);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, <=n) cin >> a[i];
	
	rep(i, 1, <=1000) S.insert(i*i);
	sort(a+1, a+n+1);
	
	rep(i, 1, <=n){
		if(S.count(a[i])){
			cout << 1 << endl;
			return 0;
		}
	}
	rep(i, 1, <=n-1){
		if(a[i] == a[i+1]){
			cout << 2 << endl;
			return 0;
		}
	}
	
	for(int i = 2; i < 1005; i++){
		if(prime[i]) continue;
		for(int j = 2*i; j < 1000005; j+=i) prime[j] = i;
	}
	
	for(int i = 1; i <= n; i++){
		map<llint, llint> mp;
		llint t = a[i];
		while(prime[t]){
			mp[prime[t]]++;
			t /= prime[t];
		}
		if(t > 1) mp[t]++;
		vector<llint> vec;
		for(auto it = mp.begin(); it != mp.end(); it++){
			if(it->second % 2) vec.push_back(it->first);
		}
		if(vec.size() == 1){
			G[1].push_back(vec[0]);
			G[vec[0]].push_back(1);
		}
		if(vec.size() == 2){
			G[vec[0]].push_back(vec[1]);
			G[vec[1]].push_back(vec[0]);
		}
	}
	
	for(int i = 1; i <= 1000000; i++){
		if(G[i].size() == 0) continue;
		vec.push_back(i);
		sort(G[i].begin(), G[i].end());
		for(int j = 1; j < G[i].size(); j++){
			if(G[i][j] == G[i][j-1]){
				cout << 2 << endl;
				return 0;
			}
		}
	}
	for(int i = 1; i <= 1000; i++) bfs(i);
	
	if(ans >= 3000) ans = -1;
	cout << ans << endl;
	
	return 0;
}