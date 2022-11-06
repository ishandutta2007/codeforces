#include<bits/stdc++.h>
using namespace std;
#define re register
#define cmin(a,b) ((a)<(b)?(a):(b))
unordered_map<int,int>xp,yp;
struct eg{int to,nx,v;}e[1000100];
int rb[200100],la[400100],cur[400100],q[400100],ta,cnt=1,x[200100],y[200100],d[200100],nm[200100],t[200100],dis[400100],S,T,SS,TT;
inline void addE(re int a,re int b,re int c)
{
	e[++cnt]=(eg){b,la[a],c};la[a]=cnt;
	e[++cnt]=(eg){a,la[b],0};la[b]=cnt;
}
bool bfs(re int s,re int t)
{
	memset(dis,0,(t+1)<<2);
	memcpy(cur,la,(t+1)<<2);
	q[ta=1]=t;dis[t]=1;
	for(re int i=1;i<=ta;i++)
	{
		re int x=q[i];
		for(re int j=la[x];j;j=e[j].nx)
		if(e[j^1].v&&!dis[e[j].to]){
			dis[e[j].to]=dis[x]+1;
			if(e[j].to==s)return 1;
			else q[++ta]=e[j].to;
		}
	}
	return 0;
}
int dfs(re int x,re int t,re int fl)
{
	if(x==t)return fl;
	re int ft=0;
	for(re int&i=cur[x];i;i=e[i].nx)
	if(e[i].v&&dis[e[i].to]==dis[x]-1){
		re int f1=dfs(e[i].to,t,cmin(fl-ft,e[i].v));
		e[i].v-=f1;ft+=f1;e[i^1].v+=f1;
		if(fl==ft)break;
	}
	return ft;
}
int dinic(re int s,re int t)
{
	re int nm=0;
	while(bfs(s,t))nm+=dfs(s,t,1e9);
	return nm;
}
int main()
{
	re int n,m,r,b,x1,x2,x3,bl=0,nmu=0;
	re long long ans=0;
	scanf("%d%d%d%d",&n,&m,&r,&b);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
	}
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&t[i],&x2,&d[i]);
		if(t[i]==1)
		{
			if(xp[x2])d[xp[x2]]=cmin(d[xp[x2]],d[i]),d[i]=-1;
			else xp[x2]=i;
		}
		else
		{
			if(yp[x2])d[yp[x2]]=cmin(d[yp[x2]],d[i]),d[i]=-1;
			else yp[x2]=i;
		}
	}
	S=m+1;T=m+2;SS=m+3;TT=m+4;
	for(re int i=1;i<=n;i++)
	{
		x1=xp[x[i]];x2=yp[y[i]];
		if(!x1)x1=S;if(!x2)x2=T;
		addE(x1,x2,1);
		nm[x1]++;nm[x2]++;
	}
	for(re int i=1;i<=m;i++)if(d[i]!=-1)
	{
		x1=(nm[i]-d[i]+1)/2;x2=(nm[i]+d[i])/2;
		if(x1>x2){puts("-1");return 0;}
		if(x1<=0)
		{
			if(t[i]==1)addE(S,i,x2);
			else addE(i,T,x2);
		}
		else
		{
			if(t[i]==1)addE(S,i,x2-x1),addE(SS,i,x1),addE(S,TT,x1);
			else addE(i,T,x2-x1),addE(SS,T,x1),addE(i,TT,x1);
			nmu+=x1;
		}
	}
	addE(T,S,1e9);
	re int xxa=dinic(SS,TT);
	if(nmu!=xxa){puts("-1");return 0;}
	dis[SS]=dis[TT]=1e9;
	e[cnt].v=e[cnt-1].v=0;
	dinic(S,T);
	if(r>b)swap(r,b),bl=1;
	for(re int i=1;i<=n;i++)
	{
		if(e[i*2].v)ans+=b,rb[i]=bl^1;
		else ans+=r,rb[i]=bl;
	}
	printf("%lld\n",ans);
	for(re int i=1;i<=n;i++)if(!rb[i])putchar('r');else putchar('b');puts("");
}