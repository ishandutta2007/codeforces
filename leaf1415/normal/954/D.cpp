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

ll n, m, s, t;
ll distS[1005], distT[1005];
vector<ll> G[1005];
bool used[1005][1005];

void bfs(vector<llint> G[], int S, llint dist[])
{
	queue<int> Q;
	Q.push(S);
	
	for(int i = 1; i <= n; i++) dist[i] = inf;
	dist[S] = 0;
	
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			if(dist[G[v][i]] < inf/2) continue;
			Q.push(G[v][i]);
			dist[G[v][i]] = dist[v] + 1;
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> s >> t;
	llint u, v;
	rep(i, 1, m){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
		used[u][v] = used[v][u] = true;
	}
	bfs(G, s, distS);
	bfs(G, t, distT);
	ll d = distS[t];
	
	ll ans = 0;
	rep(i, 1, n){
		rep(j, 1, n){
			if(i >= j) continue;
			if(used[i][j]) continue;
			if(distS[i]+distT[j]+1 >= d && distS[j]+distT[i]+1 >= d) ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}