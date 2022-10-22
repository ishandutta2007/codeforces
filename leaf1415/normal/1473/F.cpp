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
#define inf 1e9

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;


struct Dinic{
	struct edge{
		llint to, cap, rev;
		edge(llint a, llint b, llint c){
			to = a, cap = b, rev = c;
		}
	};
	
	int n;
	vector<vector<edge> > G;
	vector<llint> level, iter;
	Dinic(){}
	Dinic(int n){
		this->n = n;
		G.resize(n+1);
		level.resize(n+1);
		iter.resize(n+1);
	}
	void init(){
		for(int i = 0; i <= n; i++) G[i].clear();
	}
	void add_edge(int s, int t, llint cap)
	{
		G[s].push_back(edge(t, cap, G[t].size()));
		G[t].push_back(edge(s, 0, G[s].size()-1));
	}
	void bfs(int s)
	{
		for(int i = 0; i <= n; i++) level[i] = inf;
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
	llint dfs(int v, llint f, int t)
	{
		if(v == t) return f;
		
		llint ret;
		for(llint &i = iter[v]; i < G[v].size(); i++){
			if(level[v] >= level[G[v][i].to] || G[v][i].cap <= 0) continue;
			ret = dfs(G[v][i].to, min(f, G[v][i].cap), t);
			if(ret > 0){
				G[v][i].cap -= ret;
				G[G[v][i].to][G[v][i].rev].cap += ret;
				return ret;
			}
		}
		return 0;
	}
	llint calc(int s, int t)
	{
		llint ret = 0, flow;
		while(1){
			bfs(s);
			if(level[t] >= inf) break;
			for(int i = 0; i <= n; i++) iter[i] = 0;
			while(1){
				flow = dfs(s, inf, t);
				if(flow <= 0) break;
				ret += flow;
			}
		}
		return ret;
	}
};

int n;
int a[3005], b[3005];
int pos[3005][105];
Dinic dc(3005);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	rep(i, 1, n) cin >> b[i];
	
	rep(i, 1, n){
		rep(j, 1, 100) pos[i][j] = pos[i-1][j];
		pos[i][a[i-1]] = i-1;
	}
	
	ll S = n+1, T = n+2, ans = 0;
	rep(i, 1, n){
		if(b[i] > 0) dc.add_edge(S, i, b[i]), ans += b[i];
		if(b[i] < 0) dc.add_edge(i, T, -b[i]);
	}
	rep(i, 1, n){
		rep(j, 1, 100){
			if(a[i] % j) continue;
			if(pos[i][j]) dc.add_edge(i, pos[i][j], 1e9);
		}
	}
	cout << ans - dc.calc(S, T) << endl;
	
	return 0;
}