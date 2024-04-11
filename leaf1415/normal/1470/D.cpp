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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll T;
ll n, m;
vector<ll> G[300005];
vector<ll> ans;
bool used[300005];

void dfs(int v)
{
	used[v] = true;
	for(auto u : G[v]){
		if(!used[u]) dfs(u);
	}
}

void bfs(int s)
{
	queue<ll> Q;
	ans.push_back(s), used[s] = true;
	for(auto v : G[s]) used[v] = true, Q.push(v);
	
	while(Q.size()){
		ll v = Q.front(); Q.pop();
		for(auto u : G[v]){
			if(used[u]) continue;
			ans.push_back(u), used[u] = true;
			
			for(auto w : G[u]){
				if(used[w]) continue;
				used[w] = true, Q.push(w);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n >> m;
		rep(i, 1, n) G[i].clear();
		
		ll u, v;
		rep(i, 1, m){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		rep(i, 1, n) used[i] = false;
		dfs(1);
		rep(i, 1, n){
			if(!used[i]){
				cout << "NO" << "\n";
				goto end;
			}
		}
		
		ans.clear();
		rep(i, 1, n) used[i] = false;
		bfs(1);
		
		cout << "YES" << "\n";
		cout << ans.size() << "\n";
		for(auto x : ans) cout << x << " "; cout << "\n";
		end:;
	}
	flush(cout);
	
	return 0;
}