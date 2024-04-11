#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define MOD 1000000007 
#define pb push_back
int n,m,tmp1[2],tmp2[2],ans[2],st[N],dp[N][2][2];bool vs[N],tg[N][2];
struct Edge {int v,w1,w2;};vector<Edge> e[N];
void W(int &x,int y) {x=(x+y)%MOD;}
void dfs(int u)
{
	if(vs[u]) return;vs[u]=1;st[++st[0]]=u;
	for(int i=0;i<e[u].size();++i) dfs(e[u][i].v);
}
void ins()
{
	for(int j=0;j<2;++j) for(int k=0;k<2;++k)
		W(tmp2[j^k],1ll*ans[j]*tmp1[k]%MOD);
	for(int j=0;j<2;++j) ans[j]=tmp2[j];tmp1[0]=tmp1[1]=tmp2[0]=tmp2[1]=0;
}
void slv()
{
	for(int i=1,w1,w2,t;i<st[0];++i)
	{
		for(int j=0;j<e[st[i]].size();++j) if(e[st[i]][j].v==st[i+1])
			w1=e[st[i]][j].w1,w2=e[st[i]][j].w2;
		for(int j1=0;j1<2;++j1) for(int j2=0;j2<2;++j2) 
			for(int k=0;k<2;++k)
			{
				t=k^(j1^w1 || j2^w2)^tg[st[i+1]][j2];
				W(dp[st[i+1]][j2][t],dp[st[i]][j1][k]);
			}
	}
}
void slv1()
{
	dp[st[1]][0][tg[st[1]][0]]=dp[st[1]][1][tg[st[1]][1]]=1;slv();
	for(int j=0;j<2;++j) for(int k=0;k<2;++k)
		W(tmp1[k],dp[st[st[0]]][j][k]);ins();
}
void slv2()
{
	int w1,w2,t;
	for(int i=1;i>=0;--i) if(e[st[st[0]]][i].v==st[1]) 
		w1=e[st[st[0]]][i].w1,w2=e[st[st[0]]][i].w2;
	dp[st[1]][0][tg[st[1]][0]]=1;slv();
	for(int j=0;j<2;++j) for(int k=0;k<2;++k)
		t=k^(j^w1 || w2),W(tmp1[t],dp[st[st[0]]][j][k]);
	for(int i=1;i<=st[0];++i) for(int j=0;j<2;++j)
		for(int k=0;k<2;++k) dp[st[i]][j][k]=0;
	dp[st[1]][1][tg[st[1]][1]]=1;slv();
	for(int j=0;j<2;++j) for(int k=0;k<2;++k)
		t=k^(j^w1 || 1^w2),W(tmp1[t],dp[st[st[0]]][j][k]);ins();
}
int main()
{
	scanf("%d %d",&m,&n);ans[0]=1;
	for(int i=1,F[3];i<=m;++i)
	{
		scanf("%d %d",&F[0],&F[1]);if(F[0]==1) tg[abs(F[1])][F[1]>0]=1;
		if(F[0]==2)
		{
			scanf("%d",&F[2]);
			e[abs(F[1])].pb((Edge) {abs(F[2]),F[1]<0,F[2]<0});
			e[abs(F[2])].pb((Edge) {abs(F[1]),F[2]<0,F[1]<0});
		}
	}
	for(int i=1;i<=n;++i) if(!vs[i] && e[i].size()<2)
		st[0]=0,dfs(i),slv1();
	for(int i=1;i<=n;++i) if(!vs[i]) st[0]=0,dfs(i),slv2();
	printf("%d\n",ans[1]);return 0;
}