//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
map<int,int>all[200005];
int n,m;
vector<int>g[200005];
int son[200005];
int p[20][200005];
vector<pair<int,int> >qry[200005];
int ans[200005];
int get_par(int x,int y){
	int tmp=x;
	for(int i=19;i>=0;i--)if(y&(1<<i))tmp=p[i][tmp];
	return tmp;
}
void dfs(int x,int depth=0){
	int best=-inf;
	for(auto to:g[x]){
		dfs(to,depth+1);
		if((int)all[to].size()>best){
			best=all[to].size();
			son[x]=to;
		}
	}
	if(x==0)return; 
	if(best!=-inf)all[x].swap(all[son[x]]);
	for(auto to:g[x])if(to!=son[x]){
		for(auto p:all[to]){
			all[x][p.first]+=p.second;
		}
	}
	all[x][depth]++;
	for(auto q:qry[x]){
		if(all[x].count(depth+q.first))ans[q.second]=all[x][depth+q.first];
		else ans[q.second]=1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[0][i]);
		g[p[0][i]].push_back(i);
	}
	for(int i=1;i<20;i++)for(int j=1;j<=n;j++)p[i][j]=p[i-1][p[i-1][j]];
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int v,p;
		scanf("%d%d",&v,&p);
		v=get_par(v,p);
		if(v)qry[v].push_back(make_pair(p,i));
		else ans[i]=1;
	}
	dfs(0);
	for(int i=1;i<=m;i++)printf("%d ",ans[i]-1);
	#ifndef ONLINE_JUDGE
	printf("show maps\n");
	for(int i=1;i<=n;i++){
		printf("%d:",i);
		for(auto p:all[i]){
			printf("<%d,%d>",p.first,p.second);
		}
		printf("\n");
	}
	#endif
	return 0;
}