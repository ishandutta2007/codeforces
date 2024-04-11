#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n;
LL z[210000];
int par[210000];
LL dp[210000];
int f[210000];
int ans[210000];
int p[20][210000];
vector<LL> c[210000];
vector<LL> dist[210000];

void dfs(LL a){
	for(LL i = 0; i < (int)c[a].size(); i++){
		dp[c[a][i]] = dp[a] + dist[a][i];
		dfs(c[a][i]);
	}
}
void dfs2(LL a){
	for(LL i = 0; i < (int)c[a].size(); i++){
		dfs2(c[a][i]);
		ans[a] += ans[c[a][i]] + 1 - f[c[a][i]];
	}

}
int main(){
	scanf("%d", &n);
	for(LL i = 0; i < n; i++) scanf("%d", &z[i]);
	par[0] = 0;
	for(LL i = 1; i < n; i++){
		f[i] = 0;
		ans[i] = 0;
		scanf("%I64d", &par[i]);
		LL w;
		scanf("%I64d", &w);
		par[i]--;
		c[par[i]].push_back(i);
		dist[par[i]].push_back(w);
	}
	dp[0] = 0;

	for(LL i = 0; i < n; i++){
		p[0][i] = par[i];
	}
	p[0][0] = 0;
	for(LL d = 1; d < 20; d++){
		for(LL i = 0; i < n; i++){
			p[d][i] = p[d-1][p[d-1][i]];
		}
	}
	dfs(0);

	for(LL i = 0; i < n; i++){
		LL cur = i;
		for(LL d = 19; d >= 0; d--){
			if(dp[i] - dp[p[d][cur]] <= z[i]){
				cur = p[d][cur];
			}
		}
		f[cur]++;
		//cout << cur << " " << i << endl;
		//f[i]--;
	}
	dfs2(0);
	for(LL i = 0; i < n; i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
}