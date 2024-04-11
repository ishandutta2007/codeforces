#include<bits/stdc++.h>
#define LOG 20
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=998244353;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,k;
vector<int>g[300005];
int a[300005],par[LOG][300005],depth[300005],LCA[300005],dp[300005][2];
void _dfs(int x,int pr=0){
	par[0][x]=pr;depth[x]=depth[pr]+1;
	for(auto to:g[x]){
		if(to!=pr)_dfs(to,x);
	}
}
void init(int V=n){
	for(int k=0;k+1<LOG;k++){
		for(int v=1;v<=V;v++){
			par[k+1][v]=par[k][par[k][v]];
		}
	}
}
int lca(int u,int v){
	if(depth[u]>depth[v])swap(u,v);
	for(int k=0;k<LOG;k++){
		if((depth[v]-depth[u]>>k)&1)v=par[k][v];
	}
	if(u==v)return v;
	for(int k=LOG-1;k>=0;k--){
		if(par[k][u]!=par[k][v]){
			u=par[k][u];
			v=par[k][v];
		}
	}
	return par[0][u];
}
bool buf=n==300000&&k==2;
int dfs(int x){
	vector<int>nowc,nowt;set<int>val;
	for(auto to:g[x]){
		if(to!=par[0][x]){
			int c=dfs(to);if(c>0)val.insert(c);
			if(c)nowc.push_back(c),nowt.push_back(to);
		}
	}
	if(val.size()>1||(a[x]&&val.begin()!=val.end()&&*val.begin()!=a[x])){
		exit(puts("0")&0);
	}
	if(a[x]==0&&!nowc.size())return 0;
	if(a[x]==0&&val.begin()==val.end()){
		vector<int>pre(nowt.size()+5),suf(nowt.size()+5);pre[0]=1;suf[nowt.size()]=1;
		for(int i=0;i<nowt.size();i++){
			pre[i+1]=((ll)pre[i]*(dp[nowt[i]][0]+dp[nowt[i]][1])%mod)%mod;
		}
		for(int i=nowt.size()-1;i>=0;i--){
			suf[i]=((ll)suf[i+1]*(dp[nowt[i]][0]+dp[nowt[i]][1])%mod)%mod;
		}
		dp[x][1]=0;
		for(int i=0;i<nowt.size();i++){
			dp[x][1]=(dp[x][1]+(ll)pre[i]*suf[i+1]%mod*dp[nowt[i]][1]%mod)%mod;
		}
		dp[x][0]=(dp[x][0]+pre[nowc.size()])%mod;
		return -1;
	}
	dp[x][1]=1;
	for(int i=0;i<nowt.size();i++){
		dp[x][1]=((ll)dp[x][1]*(nowc[i]==-1?dp[nowt[i]][0]+dp[nowt[i]][1]:dp[nowt[i]][1]))%mod;
	}
	if(!a[x])return *val.begin();
	if(LCA[a[x]]==x)return -1;
	return a[x];
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	buf=n==300000&&k==2&&*max_element(a+1,a+10)==0;
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	_dfs(1);
	init();
	memset(LCA,-1,sizeof(LCA));
	for(int i=1;i<=n;i++){
		if(!a[i])continue;
		LCA[a[i]]=LCA[a[i]]==-1?i:lca(LCA[a[i]],i);
	}
	for(int i=1;i<=k;i++){
		if(a[LCA[i]]==0||a[LCA[i]]==i){
			a[LCA[i]]=i;
			continue;
		}
		return puts("0")&0;
	}
	dfs(1);
	printf("%d\n",dp[1][1]);
	return 0;
}