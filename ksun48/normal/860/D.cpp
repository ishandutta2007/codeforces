#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

struct UF{
	int n;
	vector<int> par;
	UF(int n) : n(n) {
		for(int i = 0; i < n; i++) par.push_back(i);
	}
	int find(int a){
		if(a != par[a]) par[a] = find(par[a]);
		return par[a];
	}
	void join(int a, int b){
		par[find(a)] = find(b);
	}
};

vector<int> edges[200000];
vector<int> ans[200000];

void dfs(int par, int v){
	for(int j = 0; j < edges[v].size(); j++){
		if(edges[v][j] != par) dfs(v, edges[v][j]);
	}
	if(v < 0 || par < 0) return;
	if(ans[v].size() % 2 == 1){
		ans[v].push_back(par);
	} else {
		ans[par].push_back(v);
	}
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);

	UF uf(n);
	for(int i = 0; i < m; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		if(uf.find(a) == uf.find(b)){
			ans[a].push_back(b);
		} else {
			uf.join(a,b);
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
	}
	for(int i = 0; i < n; i++){
		if(uf.find(i) == i){
			dfs(-1, i);
		}
	}
	int num = 0;
	for(int i = 0; i < n; i++){
		int d = ans[i].size();
		num += d/2;
	}
	printf("%d\n", num);
	for(int i = 0; i < n; i++){
		for(int j = 0; j +1 < ans[i].size(); j += 2){
			printf("%d %d %d\n", ans[i][j] + 1, i + 1, ans[i][j+1]+1);
		}
	}
}