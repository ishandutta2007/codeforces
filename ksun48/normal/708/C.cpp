#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int> edges[410000];
int ans[410000];
int cen[410000];
int par[410000];
int sz[410000];
int n;
void dfs(int p, int a){
	sz[a] = 1;
	par[a] = p;
	for(int i = 0; i < edges[a].size(); i++){
		if(edges[a][i] != p){
			dfs(a,edges[a][i]);
			sz[a] += sz[edges[a][i]];
		}
	}
}

void check(int p, int a, int rem){// REM
	ans[a] = 0;
	if(n-sz[a]-rem <= (n/2)) ans[a] = 1;
	for(int i = 0; i < edges[a].size(); i++){
		if(edges[a][i] != p){
			check(a,edges[a][i], rem);
		}
	}	
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(-1,0);

	for(int i = 0; i < n; i++){
		if(sz[i]*2 == n){
			for(int j = 0; j < n; j++) printf("1 ");
			printf("\n");
			return 0;
		}
	}
	int c = 0;
	for(int i = 0; i < n; i++){
		cen[i] = 1;
	}
	for(int i = 0; i < n; i++){
		ans[i] = 0;
		if(n-sz[i] > (n/2)){
			cen[i] = 0;
		}
		if(sz[i] > (n/2) ) {
			if(par[i] != -1) cen[par[i]] = 0;
		}
	}
	for(int i = 0; i < n; i++){
		if(cen[i]) c = i;
	}

	ans[c] = 1;
	dfs(-1,c);
	int t = -1;
	for(int i = 0; i < edges[c].size(); i++){
		if(t == -1 || sz[t] < sz[edges[c][i]]){
			t = edges[c][i];
		}
	}
	int r = -1;
	for(int i = 0; i < edges[c].size(); i++){
		if(edges[c][i] == t) continue;
		if(r == -1 || sz[r] < sz[edges[c][i]]){
			r = edges[c][i];
		}
	}
	if(r == -1){
		for(int j = 0; j < n; j++) printf("1 ");
		printf("\n");
		return 0;		
	}
	for(int i = 0; i < edges[c].size(); i++){
		if(edges[c][i] == t) check(c,edges[c][i],sz[r]);
		else check(c,edges[c][i],sz[t]);
	}
	ans[c] = 1;
	for(int i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
}