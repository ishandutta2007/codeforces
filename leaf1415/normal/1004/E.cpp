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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

struct edge{
	llint to, cost;
	edge(){}
	edge(llint a, llint b){
		to = a, cost = b;
	}
};


llint dtmp[100005];
llint distdfs(vector<edge> G[], int v, int p, llint d)
{
	dtmp[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i].to, c = G[v][i].cost; //
		if(u == p) continue;
		distdfs(G, u, v, d+c);
	}
}

llint getDiameter(vector<edge> G[], llint n, llint &u, llint &v)
{
	distdfs(G, 1, -1, 0);
	llint max_val = -1, max_v;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	u = max_v;
	
	distdfs(G, u, -1, 0);
	max_val = -1;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	v = max_v;
	
	return max_val;
}


llint n, k;
vector<edge> G[100005];
vector<llint> vec;
set<llint> S;
bool used[100005];

bool dfs(int v, int p, llint d, int g)
{
	if(v == g){
		vec.push_back(d);
		S.insert(v);
		return true;
	}
		
	for(auto u : G[v]){
		if(u.to == p) continue;
		if(dfs(u.to, v, d+u.cost, g)){
			vec.push_back(d);
			S.insert(v);
			return true;
		}
	}
	return false;
}

llint dfs2(int v, int p, llint d){
	llint ret = d;
	for(auto u : G[v]){
		if(u.to == p || S.count(u.to)) continue;
		chmax(ret, dfs2(u.to, v, d+u.cost));
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	llint u, v, d;
	rep(i, 1, n-1){
		cin >> u >> v >> d;
		G[u].push_back(edge(v, d));
		G[v].push_back(edge(u, d));
	}
	getDiameter(G, n, u, v);
	
	dfs(u, -1, 0, v);
	reverse(all(vec));
	k = min(k, (llint)vec.size());
	
	//cout << u << " " << v << endl;
	//for(auto d : vec) cout << d << " "; cout << endl;
	
	llint ans = inf;
	for(int i = 0; i + k - 1 < vec.size(); i++){
		chmin(ans, max(vec[i], vec.back() - vec[i+k-1]));
	}
	for(auto v : S) chmax(ans, dfs2(v, -1, 0));
	cout << ans << endl;
	
	return 0;
}