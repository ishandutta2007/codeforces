#include <iostream>
#include <algorithm>
#include <vector>
#define llint long long
#define mod 1000000007
#define inf 1000000000000000

using namespace std;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};

llint n, m, k;
llint l[200005], r[200005];
vector<llint> comp;
vector<edge> G[400005];
llint dist[400005], dp[400005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> r[i] >> l[i];
	
	comp.push_back(0);
	for(int i = 1; i <= n; i++){
		comp.push_back(l[i]);
		comp.push_back(r[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	for(int i = 1; i <= n; i++){
		l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
		r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
	}
	llint S = 0, N = comp.size(), T = N;
	
	for(int i = 1; i < N; i++) G[i-1].push_back(edge(i, comp[i]-comp[i-1]));
	for(int i = 1; i <= n; i++) G[l[i]].push_back(edge(r[i], 0));
	llint mx = 0;
	for(int i = 1; i <= n; i++) mx = max(mx, l[i]);
	for(int i = mx+1; i < N; i++) G[i].push_back(edge(T, 0));
	
	for(int i = 0; i <= T; i++) dist[i] = inf;
	dist[0] = 0;
	
	for(int i = 0; i <= T; i++){
		for(int j = 0; j < G[i].size(); j++){
			dist[G[i][j].to] = min(dist[G[i][j].to], dist[i] + G[i][j].cost);
		}
	}
	
	for(int i = 0; i <= T; i++) dp[i] = 0;
	dp[0] = 1;
	
	for(int i = 0; i <= T; i++){
		for(int j = 0; j < G[i].size(); j++){
			llint u = G[i][j].to;
			if(dist[i] + G[i][j].cost != dist[u]) continue;
			dp[u] += dp[i], dp[u] %= mod;
		}
	}
	cout << dp[T] << endl;
	
	return 0;
}