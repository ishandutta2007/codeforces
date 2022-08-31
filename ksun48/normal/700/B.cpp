#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, k;
int uni[200000];
vector<int> edges[200000];
LL ans = 0;
int dfs(int v, int par){
	int sz = uni[v];
	for(int i = 0; i < edges[v].size(); i++){
		if(edges[v][i] != par){
			int c = dfs(edges[v][i], v);
			sz += c;
			ans += min(c,2*k-c);
		}
	}
	return sz;
}
int main(){
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++) uni[i] = 0;
	for(int i = 0; i < 2*k; i++){
		int a;
		scanf("%d", &a);
		a--;
		uni[a] = 1;
	}
	for(int i = 1; i < n; i++){
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(0,-1);
	cout << ans << endl;
}