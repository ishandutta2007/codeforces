#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

int n;
vector<int> G[200005];
int size[200005], dist[200005];
bool used[200005];
int d[200005];
int res;

int sizedfs(int v, int pre, int dis)
{
	int ret = 1;
	dist[v] = dis;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		ret += sizedfs(G[v][i], v, dis+1);
	}
	return size[v] = ret;
}

int centdfs(int v, int pre, int sz)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		if(size[G[v][i]] > sz/2) return centdfs(G[v][i], v, sz);
	}
	return v;
}

void solve(int v, int sz)
{
	if(sz == 1){
		cout << "! " << v << endl;
		return;
	}
	sizedfs(v, -1, 0);
	int cent = centdfs(v, -1, sz);
	
	//cout << cent << endl;
	
	cout << "d " << cent << endl;
	cin >> d[cent];
	if(d[cent] == 0){
		cout << "! " << cent << endl;
		return;
	}
	if(d[v] != d[cent] + dist[cent]){
		used[cent] = true;
		solve(v, sz - size[cent]);
		return;
	}
	
	cout << "s " << cent << endl;
	cin >> res;
	used[cent] = true;
	d[res] = d[cent]-1;
	solve(res, size[res]);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout << "d 1" << endl;
	cin >> d[1];
	if(d[1] == 0){
		cout << "! 1" << endl;
		return 0;
	}
	solve(1, n);
	
	return 0;
}