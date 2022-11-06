#include<bits/stdc++.h>
using namespace std;
#define re register
struct eg{int to,nx,c,w;}e[200100];
int cnt=1,q[70010],la[5100],cur[5100],tot,S,T;
int d[5100];
unsigned short hd,ta;
inline void addE(re int a,re int b,re int c,re int d)
{
	e[++cnt]=(eg){b,la[a],c,d};la[a]=cnt;
	e[++cnt]=(eg){a,la[b],0,-d};la[b]=cnt;
}
int ans;
bool bo[5100],in[5100];
bool spfa()
{
	q[0]=S;ta=1;
	for(re int i=1;i<=tot;i++)d[i]=1<<30,cur[i]=la[i];
	d[S]=0;
	for(hd=0;hd!=ta;hd++)
	{
		re int x=q[hd];
		for(re int i=la[x];i;i=e[i].nx)if(e[i].c&&d[e[i].to]>d[x]+e[i].w)
		{
			d[e[i].to]=d[x]+e[i].w;
			if(!in[e[i].to])q[ta++]=e[i].to,in[e[i].to]=1;
		}
		in[x]=0;
	}
	return d[T]<(1<<30);
}
int dfs(re int a,re int fl)
{
	if(a==T)return fl;
	re int fa=fl;
	bo[a]=1;
	for(re int&i=cur[a];i;i=e[i].nx)if(!bo[e[i].to]&&e[i].c&&d[e[i].to]==d[a]+e[i].w)
	{
		re int t=dfs(e[i].to,min(fa,e[i].c));
		fa-=t;e[i].c-=t;e[i^1].c+=t;ans+=(long long)t*e[i].w;
		if(!fa)return fl;
	}
	return fl-fa;
}
void flow()
{
	while(spfa())
	{
		memset(bo,0,sizeof(bo));
		dfs(S,1<<30);
	}
}
int lik[110][110];
int main()
{
	re int n,m,x,y;
	scanf("%d%d",&n,&m);
	S=2*n*n+1,T=2*n*n+2;
	for(re int i=0;i<n;i++)
	{
		for(re int j=1;j<=n;j++)
		{
			if(i)addE(i*n-n+j,i*n+j,1<<30,1);
			addE(i*n+j,T,1,0);
		}
	}
	tot=n*n;
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);addE(S,y,1,0);
		lik[x][y]=-1;lik[y][x]=-2;
	}
	for(re int i=1;i<=n;i++)
	{
		for(re int j=i+1;j<=n;j++)
		if(!lik[i][j]){
			addE(S,++tot,1,0);
			addE(tot,i,1,0);
			addE(tot,j,1,0);
			lik[i][j]=cnt;lik[j][i]=cnt-2;
		}
	}
	tot=T;
	flow();
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n;j++)
		if(lik[i][j]<0)printf("%d",lik[i][j]+2);
		else
		{
			printf("%d",e[lik[i][j]].c);
		}puts("");
	}
}