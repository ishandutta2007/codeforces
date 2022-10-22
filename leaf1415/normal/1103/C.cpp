#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
vector<int> G[250005];
int depth[250005], pre[250005];
vector<int> leaf;

void dfs(int v, int dep)
{
	depth[v] = dep;
	bool flag = false;
	for(int i = 0; i < G[v].size(); i++){
		if(depth[G[v][i]]) continue;
		flag = true;
		pre[G[v][i]] = v;
		dfs(G[v][i], dep+1);
	}
	if(!flag) leaf.push_back(v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> k;
	int u, v;
	for(int i = 1; i <= m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 1);
	
	for(int i = 0; i < leaf.size(); i++){
		if(depth[leaf[i]] >= (n+k-1)/k){
			cout << "PATH" << endl;
			cout << depth[leaf[i]] << endl;
			int p = leaf[i];
			while(p != 1) cout << p << " ", p = pre[p];
			cout << 1 << endl;
			return 0;
		}
	}
	
	cout << "CYCLES" << endl;
	for(int i = 0; i < min(k, (int)leaf.size()); i++){
		int v = leaf[i], x, y;
		if(G[v][0] == pre[v]) x = G[v][1], y = G[v][2];
		if(G[v][1] == pre[v]) x = G[v][0], y = G[v][2];
		if(G[v][2] == pre[v]) x = G[v][0], y = G[v][1];
		if(depth[x] < depth[y]) swap(x, y);
		
		vector<int> tmp;
		if((depth[v]-depth[x]+1)%3){
			int p = v;
			while(p != x) tmp.push_back(p), p = pre[p];
			tmp.push_back(x);
		}
		else if((depth[v]-depth[y]+1)%3){
			int p = v;
			while(p != y) tmp.push_back(p), p = pre[p];
			tmp.push_back(y);
		}
		else{
			tmp.push_back(v);
			int p = x;
			while(p != y) tmp.push_back(p), p = pre[p];
			tmp.push_back(y);
		}
		cout << tmp.size() << endl;
		for(int i = 0; i < tmp.size(); i++) cout << tmp[i] << " "; cout << "\n";
	}
	
	return 0;
}