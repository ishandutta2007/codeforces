#include <iostream>
#include <vector>
#define llint long long

using namespace std;

struct edge{
	int to, type;
	edge(){}
	edge(int a, int b){
		to = a, type = b;
	}
};


int n;
vector<edge> G[200005];
int size[200005];
bool used[200005];

int sizedfs(int v, int pre)
{
	int ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == pre) continue;
		if(used[G[v][i].to]) continue;
		ret += sizedfs(G[v][i].to, v);
	}
	return size[v] = ret;
}

int centdfs(int v, int pre, int sz)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == pre) continue;
		if(used[G[v][i].to]) continue;
		if(size[G[v][i].to] > sz/2) return centdfs(G[v][i].to, v, sz);
	}
	return v;
}

llint ans;
llint cnt[200005][2][2];
llint sum[2][2];

void cntdfs(int v, int p, int s, int t, int x, int ch)
{
	cnt[x][s][t]++;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i].to == p) continue;
		if(used[G[v][i].to]) continue;
		int nch = ch;
		if(t != G[v][i].type) nch++;
		if(nch >= 2) continue;
		cntdfs(G[v][i].to, v, s, G[v][i].type, x, nch);
	}
}

void solve(int v, int sz)
{
	sizedfs(v, -1);
	v = centdfs(v, -1, sz);
	
	/*   */
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i].to;
		if(used[u]) continue;
		cnt[u][0][0] = cnt[u][0][1] = cnt[u][1][0] = cnt[u][1][1] = 0;
		cntdfs(G[v][i].to, v, G[v][i].type, G[v][i].type, G[v][i].to, 0);
	}
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			sum[i][j] = 0;
			for(int k = 0; k < G[v].size(); k++){
				if(!used[G[v][k].to]) sum[i][j] += cnt[G[v][k].to][i][j];
			}
		}
	}
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i].to;
		if(used[u]) continue;
		ans += cnt[u][0][0] * (sum[0][0]-cnt[u][0][0] + sum[0][1]-cnt[u][0][1] + sum[1][1]-cnt[u][1][1]);
		ans += cnt[u][1][0] * (sum[1][1]-cnt[u][1][1]);
		ans += cnt[u][1][1] * (sum[1][1]-cnt[u][1][1]);
	}
	ans += 2*sum[0][0] + sum[0][1] + sum[1][0] + 2*sum[1][1];
	
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i].to]) continue;
		solve(G[v][i].to, size[G[v][i].to]);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v, t;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v >> t;
		G[u].push_back(edge(v, t));
		G[v].push_back(edge(u, t));
	}
	
	solve(1, n);
	cout << ans << endl;
	
	return 0;
}