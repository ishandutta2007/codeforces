#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
const int N=3030;
VI es[N];
#define F(x) for(VI::iterator it=es[x].begin();it!=es[x].end();it++)
int n;
int sz[N][2];
int fa[N];
void dfs1(int x,int fa=-1){
	::fa[x]=fa;
	sz[x][0]=1;
	F(x)if(*it!=fa){
		dfs1(*it,x);
		sz[x][0]+=sz[*it][0];
	}
	sz[x][1]=n-sz[x][0];
}

LL dp[N][N][2];
LL f(int x,int y,bool up){
	LL &ans=dp[x][y][(int)up];
	if(ans!=-1)return ans;
	ans=0;
	// xdown
	F(x)if(*it!=fa[x])ans=max(ans,f(*it,y,up));
	if(up){
		if(fa[fa[y]]!=-1)ans=max(ans,f(x,fa[y],true));
		F(fa[y])if(*it!=fa[fa[y]]&&*it!=y)ans=max(ans,f(x,*it,false));
	}
	else{
		F(y)if(*it!=fa[y])ans=max(ans,f(x,*it,false));
	}
	ans+=(LL)sz[x][0]*sz[y][(int)up];
	return ans;
}
int main(){
	memset(dp,-1,sizeof(dp));
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		es[u].push_back(v);
		es[v].push_back(u);
	}
	dfs1(1);
	LL ans=0;
	for(int i=1;i<=n;i++)if(fa[i]!=-1){
		ans=max(ans,f(i,i,true));
	}
	cout<<ans<<endl;
	return 0;
}