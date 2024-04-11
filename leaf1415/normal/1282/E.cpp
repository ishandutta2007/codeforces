#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#include <string>
#include <map>
#include <queue>
#define llint long long

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n;
llint c[100005];
llint a[100005][3];
map<P, vector<llint> > mp;
vector<llint> G[100005];
bool used[100005];

void dfs(int v, int p)
{
	cout << v << " ";
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p || used[G[v][i]]) continue;
		dfs(G[v][i], v);
	}
}

void bfs()
{
	queue<llint> Q;
	for(int i = 1; i <= n-2; i++){
		llint cnt = 0;
		for(int j = 0; j < 3; j++){
			P p = P(a[i][j], a[i][(j+1)%3]);
			if(p.first > p.second) swap(p.first, p.second);
			if(mp[p].size() == 1) cnt++;
		}
		c[i] = cnt;
		if(cnt >= 2) Q.push(i), used[i] = true;
	}
	
	llint v;
	while(Q.size()){
		v = Q.front();
		Q.pop();
		cout << v << " ";
		for(int i = 0; i < G[v].size(); i++){
			int u = G[v][i];
			c[u]++;
			if(used[u]) continue;
			if(c[u] >= 2){
				Q.push(u);
				used[u] = true;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n;
		for(int i = 1; i <= n-2; i++){
			for(int j = 0; j < 3; j++) cin >> a[i][j];
		}
		if(n == 3){
			cout << "1 2 3" << endl;
			cout << "1" << endl;
			continue;
		}
		
		mp.clear();
		for(int i = 1; i <= n-2; i++){
			for(int j = 0; j < 3; j++){
				P p = P(a[i][j], a[i][(j+1)%3]);
				if(p.first > p.second) swap(p.first, p.second);
				mp[p].push_back(i);
			}
		}
		for(int i = 1; i <= n; i++) G[i].clear(), used[i] = false;
		for(auto it = mp.begin(); it != mp.end(); it++){
			if(it->second.size() == 1){
				P p = it->first;
				G[p.first].push_back(p.second);
				G[p.second].push_back(p.first);
			}
		}
		dfs(1, -1);
		cout << endl;
		
		for(int i = 1; i <= n; i++) G[i].clear(), used[i] = false;
		for(auto it = mp.begin(); it != mp.end(); it++){
			if(it->second.size() >= 2){
				vector<llint> &vec = it->second;
				G[vec[0]].push_back(vec[1]);
				G[vec[1]].push_back(vec[0]);
			}
		}
		bfs();
		cout << endl;
	}
	
	flush(cout);
	
	return 0;
}