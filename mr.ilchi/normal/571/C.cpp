#include <bits/stdc++.h>
using namespace std;

bool vis[1<<20],value[1<<20];
int n,m,root=-1;
int mark[1<<20];
vector<int> adj[1<<20],var[1<<20];
vector< pair<int,int> > pos[1<<20];

void add_edge (int a, int b, int v){
	adj[a].push_back(b);
	var[a].push_back(v);
	if (a != b){
		adj[b].push_back(a);
		var[b].push_back(-v);
	}
}

void dfs (int v, int p){
	mark[v] = 1;
	bool multi_edge = false;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (!mark[temp])
			dfs(temp, v);
		else if (temp!=p || multi_edge)
			root = temp;
		multi_edge |= p == temp;
	}
	mark[v] = 2;
}

bool get_val (int x){
	return x > 0 ? true : false;
}

void go (int v, int p){
	vis[v] = true;
	bool multi_edge = false;
	for (int i=0; i<(int)adj[v].size(); i++){
		int temp = adj[v][i];
		if (!vis[temp]){
			value[abs(var[v][i])] = !get_val(var[v][i]);
			go(temp, v);
		}else if (temp == root){
			if (v == root)
				value[abs(var[v][i])] = get_val(var[v][i]);
			else if (temp!=p || multi_edge)
				value[abs(var[v][i])] = !get_val(var[v][i]);
			multi_edge = true;
		}
	}
}
	
int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i=0; i<n; i++){
		int len; cin >> len;
		for (int j=0; j<len; j++){
			int x; cin >> x;
			pos[abs(x)].push_back(pair<int,int>(i,x));
		}
	}
	for (int i=1; i<=m; i++) if (!pos[i].empty()){
		if (pos[i].size() == 1)
			add_edge(pos[i][0].first, pos[i][0].first, pos[i][0].second);
		else if (pos[i][0].second == pos[i][1].second){
			add_edge(pos[i][0].first, pos[i][0].first, pos[i][0].second);
			add_edge(pos[i][1].first, pos[i][1].first, pos[i][1].second);
		}else
			add_edge(pos[i][0].first, pos[i][1].first, pos[i][0].second);
	}
	for (int i=0; i<n; i++) if (mark[i] == 0){
		root = -1;
		dfs(i,-1);
		if (root == -1){
			cout << "NO" << endl;
			return 0;
		}
		go(root,-1);
	}
	cout << "YES" << endl;
	for (int i=1; i<=m; i++)
		cout << value[i];
	cout << endl;
	return 0;
}