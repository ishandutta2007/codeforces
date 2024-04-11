#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
const int M=20;
int n,f[M+5][N+5],dep[N+5],q,v,s,t,p2[M+5],maxlen;
void init()
{
	p2[0]=1;
	for(int i=1;i<=M;i++) p2[i]=p2[i-1]*2;
	memset(f,0,sizeof(f));
	f[0][2]=f[0][3]=f[0][4]=1;
	dep[0]=-1;
	dep[1]=0;
	dep[2]=dep[3]=dep[4]=1;
	n=4;
	s=2,t=4;
	maxlen=2;
	return;
}
void add(int x)
{
	f[0][n+1]=f[0][n+2]=x;
	dep[n+1]=dep[n+2]=dep[x]+1;
	for(int i=1;p2[i]<=dep[n+1];i++) f[i][n+1]=f[i-1][f[i-1][n+1]];
	for(int i=1;p2[i]<=dep[n+2];i++) f[i][n+2]=f[i-1][f[i-1][n+2]];
	return;
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	int len=dep[u]-dep[v];
	for(int i=M;i>=0;i--) if(len>=p2[i]) len-=p2[i],u=f[i][u];
	if(u==v) return u;
	for(int i=M;i>=0;i--) if(f[i][u]!=f[i][v]) u=f[i][u],v=f[i][v];
	return f[0][u];
}
int len(int u,int v)
{
	int tlen=dep[u]+dep[v];
	tlen-=2*dep[LCA(u,v)];
	return tlen;
}
int main()
{
	scanf("%d",&q);
	init();
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&v);
		add(v);
		if(len(s,n+1)>maxlen) t=n+1;
		else if(len(t,n+1)>maxlen) s=n+1;
		maxlen=len(s,t);
		printf("%d\n",maxlen);
		n=n+2;
	}
	return 0;
}