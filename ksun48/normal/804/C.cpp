#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

vector<int> edges[310000];
vector<int> p[310000];
int s[310000];
int vis[310000];

int n, m;
int used[310000];

int colors[310000]; // answer
int ans = 1;
void dfs(int a){
	if(vis[a]) return;
	vis[a] = 1;
	vector<int> unused;
	int s = 0;
	for(int i = 0; i < p[a].size(); i++){
		int f = colors[p[a][i]];
		if(f != -1){
			used[f] = 1;
			if(!used[(f+1)%ans]) unused.push_back((f+1)%ans);
		}
	}
	if(unused.size() == 0) unused.push_back(0);
	for(int i = 0; i < p[a].size(); i++){
		int f = colors[p[a][i]];
		if(f == -1){
			while(used[unused[s]]){
				s++;
			}
			colors[p[a][i]] = unused[s];
			used[unused[s]] = 1;
			if(!used[(unused[s]+1)%ans]) unused.push_back((unused[s]+1)%ans);
			s++;
		}
	}
	for(int i = 0; i < p[a].size(); i++){
		int f = colors[p[a][i]];
		used[f] = 0;
	}

	for(int i = 0; i < edges[a].size(); i++){
		dfs(edges[a][i]);
	}
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		colors[i] = -1;
		used[i] = 0;
	}
	for(int i = 0; i < n; i++){
		vis[i] = 0;
		scanf("%d", &s[i]);
		ans = max(ans,s[i]);
		for(int f = 0; f < s[i]; f++){
			int a;
			scanf("%d", &a);
			a--;
			p[i].push_back(a);
		}
	}
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		u--; v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0);
	printf("%d\n", ans);
	for(int i = 0; i < m; i++){
		printf("%d ", max(1,colors[i]+1));
	}
	printf("\n");
}