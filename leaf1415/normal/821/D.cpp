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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
typedef pair<pair<int, int>, int> T;

struct edge{
	ll to, cost;
	edge(){}
	edge(ll a, ll b){
		to = a, cost = b;
	}
};

int h, w, k;
ll x[10005], y[10005];
map<P, ll> mp;
vector<edge> G[30005];
ll dist[30005];
ll dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};

void bfs01(vector<edge> G[], int S, llint dist[])
{
	deque<int> deq;
	deq.push_back(S);
	
	for(int i = 0; i <= k+w+h; i++) dist[i] = inf;
	dist[S] = 0;
	
	while(deq.size()){
		int v = deq.front();
		deq.pop_front();
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i].to, c = G[v][i].cost;
			if(dist[u] > dist[v] + c){
				dist[u] = dist[v] + c;
				if(c == 0) deq.push_front(u);
				else deq.push_back(u);
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> k;
	rep(i, 1, k){
		cin >> y[i] >> x[i];
		mp[P(x[i], y[i])] = i;
	}
	
	rep(i, 1, k){
		rep(j, 0, 3){
			ll nx = x[i]+dx[j], ny = y[i]+dy[j];
			if(mp.count(P(nx, ny))){
				G[i].push_back(edge(mp[P(nx, ny)], 0));
			}
		}
	}
	
	bool flag = true;
	if(mp.count(P(w, h)) == 0){
		flag = false, x[k+1] = w, y[k+1] = h, mp[P(x[k+1], y[k+1])] = k+1, k++;
	}
	
	rep(i, 1, k){
		G[i].push_back(edge(k+x[i], 1));
		G[i].push_back(edge(k+w+y[i], 1));
		rep(j, -1, 1){
			if(x[i]+j >= 1 && x[i]+j <= w) G[i].push_back(edge(k+x[i]+j, 1));
			if(y[i]+j >= 1 && y[i]+j <= h) G[i].push_back(edge(k+w+y[i]+j, 1));
			if(i == k && !flag && j != 0) continue;
			if(x[i]+j >= 1 && x[i]+j <= w) G[k+x[i]+j].push_back(edge(i, 0));
			if(y[i]+j >= 1 && y[i]+j <= h) G[k+w+y[i]+j].push_back(edge(i, 0));
		}
	}
	
	bfs01(G, mp[P(1, 1)], dist);
	
	//rep(i, 1, k+w+h) cout << dist[i] << " "; cout<< endl;
	
	ll ans = dist[k];
	if(ans > inf/2) ans = -1;
	cout << ans << endl;
	
	return 0;
}