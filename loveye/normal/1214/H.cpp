#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5;
int n,k,A,B,rt;
vector<int> G[N];
int dep[N],fa[N];
void dfs(int u) {
	dep[u]=dep[fa[u]]+1;
	for(auto v:G[u]) if(v!=fa[u])
		fa[v]=u,dfs(v);
}
int dp[N][2];
void nos() {cout<<"No"<<endl; exit(0);}
void dfs2(int u) {
	for(auto v:G[u]) if(v!=fa[u]) {
		fa[v]=u;
		dfs2(v);
		if(dp[v][0]+1>dp[u][0]) dp[u][1]=dp[u][0],dp[u][0]=dp[v][0]+1;
		else if(dp[v][0]+1>dp[u][1]) dp[u][1]=dp[v][0]+1;
	}
	if(u!=rt&&dp[u][1]&&dp[u][0]+dp[u][1]>=k-1) nos();
}
int ans[N];
void dfs3(int u,int fa) {
	ans[u]=ans[fa]%k+1;
	for(auto v:G[u]) if(v!=fa) dfs3(v,u);
}
void dfs4(int u,int fa) {
	ans[u]=ans[fa]==1?k:ans[fa]-1;
	for(auto v:G[u]) if(v!=fa) dfs4(v,u);
}
int main() {
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1,u,v;i<n;++i) {
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1);
	if(k==2) {
		cout<<"Yes"<<endl;
		fr(i,1,n) cout<<(dep[i]&1)+1<<' ';
		return cout<<endl,0;
	}
	A=max_element(dep+1,dep+n+1)-dep;
	fa[A]=0; dfs(A);
	B=max_element(dep+1,dep+n+1)-dep;
	rt=B;
	while(dep[rt]>dep[B]+1>>1) rt=fa[rt];
	fa[rt]=0; dfs2(rt);
	sort(G[rt].begin(),G[rt].end(),[](const int &i,const int &j) {
		return dp[i][0]>dp[j][0];
	});
	if(G[rt].size()>=3&&dp[G[rt][2]][0]+dp[G[rt][1]][0]+2>=k-1) nos();
	cout<<"Yes"<<endl;
	dfs3(rt,0);
	dfs4(G[rt][0],rt);
	fr(i,1,n) cout<<ans[i]<<' '; cout<<endl;
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}