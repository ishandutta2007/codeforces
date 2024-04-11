#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define llint long long
#define inf 1000000000000000000

using namespace std;

struct edge{
	llint to, cap, rev;
	edge(llint a, llint b, llint c){
		to = a, cap = b, rev = c;
	}
};

llint n, m;
llint sx[55], sy[55], tx[55], ty[55];
vector<llint> compX, compY;
llint a[105][105], dif[105][105];
vector<edge> G[255];
int S, T;
llint level[255], iter[255];

void comp(llint s[], llint t[], vector<llint> &vec)
{
	vec.push_back(1);
	vec.push_back(n+1);
	for(int i = 0; i < m; i++) vec.push_back(s[i]);
	for(int i = 0; i < m; i++) vec.push_back(t[i]);
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int i = 0; i < m; i++) s[i] = lower_bound(vec.begin(), vec.end(), s[i]) - vec.begin() + 1;
	for(int i = 0; i < m; i++) t[i] = lower_bound(vec.begin(), vec.end(), t[i]) - vec.begin() + 1;
}

void bfs(llint s)
{
	for(int i = 1; i <= T; i++) level[i] = inf;
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
	for(int i = iter[v]; i < G[v].size(); i++){
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
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> sy[i] >> sx[i] >> ty[i] >> tx[i];
		tx[i]++, ty[i]++;
	}
	comp(sx, tx, compX);
	comp(sy, ty, compY);
	
	int W = compX.size(), H = compY.size();
	for(int i = 0; i < m; i++){
		dif[sx[i]][sy[i]]++;
		dif[sx[i]][ty[i]]--;
		dif[tx[i]][sy[i]]--;
		dif[tx[i]][ty[i]]++;
	}
	for(int x = 1; x <= W; x++){
		for(int y = 1; y <= H; y++){
			a[x][y] = a[x-1][y] + a[x][y-1] - a[x-1][y-1] + dif[x][y];
		}
	}
	
	S = W+H+1, T = W+H+2;
	for(int i = 1; i <= W; i++){
		add_edge(S, i, compX[i]-compX[i-1]);
		add_edge(i, T, 0);
	}
	for(int i = 1; i <= H; i++){
		add_edge(S, i+W, 0);
		add_edge(i+W, T, compY[i]-compY[i-1]);
	}
	for(int x = 1; x <= W; x++){
		for(int y = 1; y <= H; y++){
			if(a[x][y] > 0) add_edge(x, W+y, inf);
		}
	}
	
	llint ans = 0, flow;
	while(1){
		bfs(S);
		if(level[T] >= inf) break;
		for(int i = 1; i <= T; i++) iter[i] = 0;
		while(1){
			flow = dfs(S, inf);
			if(flow <= 0) break;
			ans += flow;
		}
	}
	cout << ans << endl;
	
	return 0;
}