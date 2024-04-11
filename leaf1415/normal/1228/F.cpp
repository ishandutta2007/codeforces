#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long
#define mod 1000000007

using namespace std;

llint n, N;
vector<llint> G[1<<17];
llint dist[1<<17], parent[1<<17];
llint height[1<<17], child[1<<17];
bool used[1<<17];

void dfs(llint v, llint p, llint d)
{
	dist[v] = d, parent[v] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v, d+1);
	}
}

vector<llint> vec;
llint dfs2(llint v, llint p, llint d)
{
	dist[v] = d, parent[v] = p;
	llint cnt = 0, h = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		cnt++;
		h = max(h, dfs2(G[v][i], v, d+1)+1);
	}
	child[v] = cnt;
	if(child[v] == 1 || child[v] == 3) vec.push_back(v);
	return height[v] = h;
}

void check(llint r)
{
	//cout << "check " << r << endl;
	vec.clear();
	llint h = dfs2(r, -1, 0);
	
	//for(int i = 1; i <= N; i++) cout << height[i] << " "; cout << endl;
	
	if(h != n-1) return;
	if(vec.size() != 1) return;
	
	//cout << vec[0] << endl;
	
	llint v = vec[0];
	if(child[v] == 1){
		if(height[v] == 1) used[v] = true;
	}
	else{
		llint cnt = 0;
		for(int i = 0; i < G[v].size(); i++){
			if(G[v][i] == parent[v]) continue;
			if(height[G[v][i]] == height[v]-2) cnt++;
		}
		///cout << "cnt = " << cnt << endl;
		if(cnt == 2) used[v] = true;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint u, v; N = (1<<n)-1;
	for(int i = 0; i < N-2; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	for(int i = 1; i <= N; i++){
		if(G[i].size() >= 5){
			cout << 0 << endl;
			return 0;
		}
	}
	
	dfs(1, -1, 0);
	llint root = -1, mx = -1;
	for(int i = 1; i <= N; i++){
		if(mx < dist[i]){
			mx = dist[i];
			root = i;
		}
	}
	
	dfs(root, -1, 0);
	llint tail = -1, diam = -1;
	for(int i = 1; i <= N; i++){
		if(diam < dist[i]){
			diam = dist[i];
			tail = i;
		}
	}
	//cout << root << " " << tail << " " << diam<< endl;
	
	v = tail;
	for(int i = 0; i < diam/2; i++) v = parent[v];
	if(diam % 2 == 0) check(v);
	else{
		for(int i = 0; i < G[v].size(); i++) check(G[v][i]);
		v = parent[v];
		for(int i = 0; i < G[v].size(); i++) check(G[v][i]);
	}
	
	vector<llint> ans;
	for(int i = 1; i <= N; i++){
		if(used[i]) ans.push_back(i);
	}
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++) cout << ans[i] << " "; cout << endl;
	
	return 0;
}