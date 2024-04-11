#include<bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int n,q;
vector <int> son[maxn];
int fa[maxn];

int siz[maxn],g[maxn];
void dfs(int u){
	siz[u] = 1;
	int mxv = 0;
	for(vector <int> :: iterator it = son[u].begin(); it != son[u].end(); ++it){
		dfs(*it), siz[u] += siz[*it];
		if(siz[mxv] < siz[*it]) mxv = *it;
	}
	if(siz[mxv] <= siz[u] / 2) g[u] = u;
	else {
		int x = g[mxv];
		while(siz[u] - siz[x] > siz[u] / 2) x = fa[x];
		g[u] = x;
	}
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 2; i <= n; ++i){
		int x; scanf("%d", &x);
		son[x].push_back(i);
		fa[i] = x;
	}
	dfs(1);
	while(q--){
		int k; scanf("%d", &k); printf("%d\n", g[k]);
	}
	return 0;
}
//CF685B