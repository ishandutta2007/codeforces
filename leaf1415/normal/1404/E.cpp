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
#define inf 1e9
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint h, w;
char c[205][205];


struct edge{
	llint to, cap, rev;
	edge(llint a, llint b, llint c){
		to = a, cap = b, rev = c;
	}
};

vector<edge> G[500005];
int S, T;
llint level[500005], iter[500005];

void bfs(llint s)
{
	for(int i = 0; i <= T; i++) level[i] = inf;
	level[s] = 0;
	
	queue<int> Q;
	Q.push(s);
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i].to;
			if(G[v][i].cap <= 0 || level[u] < inf) continue;
			level[u] = level[v] + 1;
			Q.push(u);
		}
	}
}

llint dfs(int v, llint f)
{
	if(v == T) return f;
	
	llint ret;
	for(llint &i = iter[v]; i < G[v].size(); i++){
		if(level[v] >= level[G[v][i].to] || G[v][i].cap <= 0) continue;
		ret = dfs(G[v][i].to, min(f, G[v][i].cap));
		if(ret > 0){
			G[v][i].cap -= ret;
			G[G[v][i].to][G[v][i].rev].cap += ret;
			return ret;
		}
	}
	return 0;
}

void add_edge(int s, int t, llint cap)
{
	G[s].push_back(edge(t, cap, G[t].size()));
	G[t].push_back(edge(s, 0, G[s].size()-1));
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			cin >> c[x][y];
		}
	}
	
	S = h*w, T = h*w+1;
	for(int y = 0; y < h; y++){
		for(int x = 0; x < w; x++){
			if(c[x][y] == '.') continue;
			if(x == 0 || c[x-1][y] == '.') add_edge(S, y*w+x, 1);
			else add_edge(y*w+(x-1), y*w+x, 1);
			
			if(y == 0 || c[x][y-1] == '.') add_edge(y*w+x, T, 1);
			else add_edge(y*w+x, (y-1)*w+x, 1);
		}
	}
	
	llint ans = 0, flow;
	while(1){
		bfs(S);
		if(level[T] >= inf) break;
		for(int i = 0; i <= T; i++) iter[i] = 0;
		while(1){
			flow = dfs(S, inf);
			if(flow <= 0) break;
			ans += flow;
		}
	}
	cout << ans << endl;
	
	return 0;
}