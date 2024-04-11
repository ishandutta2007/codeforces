#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

int n;
vector<int> G[100005];
int dist[100005];
int parent[100005];
vector<int> vec[100005];

void dfs(int v, int p, int d)
{
	dist[v] = d;
	parent[v] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v, d+1);
	}
}

bool check(int r)
{
	dfs(r, -1, 0);
	for(int i = 0; i <= n; i++) vec[i].clear();
	for(int i = 1; i <= n; i++){
		vec[dist[i]].push_back((int)G[i].size());
	}
	for(int i = 0; i <= n; i++){
		if(vec[i].size() == 0) continue;
		sort(vec[i].begin(), vec[i].end());
		if(vec[i].front() != vec[i].back()) return false;
	}
	return true;
}

int dfs2(int v, int p)
{
	if(G[v].size() == 1){
		if(check(v)) return v;
		else return -1;
	}
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(G[G[v][i]].size() > 2) continue;
		int res = dfs2(G[v][i], v);
		if(res != -1) return res;
	}
	return -1;
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
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	
	dfs(1, -1, 0);
	int root, mx = 0;
	for(int i = 1; i <= n; i++){
		if(mx < dist[i]){
			mx = dist[i];
			root = i;
		}
	}
	dfs(root, -1, 0);
	int p; mx = 0;
		for(int i = 1; i <= n; i++){
		if(mx < dist[i]){
			mx = dist[i];
			p = i;
		}
	}
	int d = dist[p];
	int c = p;
	if(d % 2 == 0){
		while(dist[p] > d/2) p = parent[p];
	}
	
	if(check(root)){
		cout << root << endl;
		return 0;
	}
	if(check(p)){
		cout << p << endl;
		return 0;
	}
	
	if(d % 2 == 0){
		if(check(c)){
			cout << c << endl;
			return 0;
		}
		
		dfs(p, -1, 0);
		for(int i = 1; i <= n; i++){
			if(G[i].size() == 1 && dist[i] < d/2){
				if(check(i)) cout << i << endl;
				else cout << -1 << endl;
				return 0;
			}
		}
		cout << dfs2(p, -1) << endl;
	}
	cout << -1 << endl;
	
	return 0;
}