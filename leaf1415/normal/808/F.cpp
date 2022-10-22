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
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

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

ll n, k;
ll p[105], c[105], l[105];
bool prime[200005];
Dinic dc(205);

bool check(ll x)
{
	ll S = 2*n+1, T = 2*n+2;
	ll sum = 0;
	
	ll q = -1, mx = -1;
	rep(i, 1, n){
		if(c[i] == 1 && l[i] <= x && mx < p[i]){
			q = i, mx = p[i];
		}
	}
	
	dc.init();
	bool flag = false;
	rep(i, 1, n){
		if(l[i] > x) continue;
		if(c[i] == 1 && i != q) continue;
		
		sum -= p[i];
		if(c[i] % 2) dc.add_edge(S, i, p[i]);
		else dc.add_edge(n+i, T, p[i]);
	}
	rep(i, 1, n) rep(j, 1, n){
		if(l[i] > x || l[j] > x) continue;
		if(c[i] % 2 == 0 || c[j] % 2) continue;
		if(!prime[c[i]+c[j]]) dc.add_edge(i, n+j, inf);
	}
	
	sum += dc.calc(S, T), sum *= -1;
	return sum >= k;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	rep(i, 2, 10005){
		if(prime[i]) continue;
		for(int j = 2*i; j < 200005; j += i) prime[j] = true;
	}
	
	cin >> n >> k;
	rep(i, 1, n) cin >> p[i] >> c[i] >> l[i];
	
	ll ub = n+1, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	if(ub == n+1) ub = -1;
	cout << ub << endl;
	
	return 0;
}