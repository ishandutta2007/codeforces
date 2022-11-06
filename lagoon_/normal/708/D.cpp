#include<bits/stdc++.h>
#define re register
struct eg{int to,nx,v,c;}e[10010];
int q[100100],la[10010],fr[10010],fl[10100],fk[10010],cnt=1;
inline void addE(re int a,re int b,re int c,re int d)
{//printf("**%d %d %d %d\n",a,b,c,d);
	e[++cnt]=(eg){b,la[a],c,d};la[a]=cnt;
	e[++cnt]=(eg){a,la[b],0,-d};la[b]=cnt;
}
int n,m,s,t;
long long ans;
unsigned short hd,ta;
long long d[10010];
bool bo[100100];
bool bfs()
{
	for(re int i=1;i<=n;i++)d[i]=1ll<<60;
	hd=0;ta=1;q[0]=s;fl[s]=1<<30;d[s]=0;
	for(;hd!=ta;hd++)
	{
		re int x=q[hd];//printf("*l*%d\n",x);
		for(re int i=la[x];i;i=e[i].nx)if(e[i].v&&d[e[i].to]>d[x]+e[i].c)
		{//printf("*k*%d %d %d %d\n",i,x,e[i].to,e[i].c);
			fr[e[i].to]=x;d[e[i].to]=d[x]+e[i].c;fl[e[i].to]=std::min(e[i].v,fl[x]);fk[e[i].to]=i;
			if(!bo[e[i].to])bo[e[i].to]=1,q[ta++]=e[i].to;
		}
		bo[x]=0;
	}//printf("**%lld %d\n",d[t],fl[t]);
	if(d[t]>=1ll<<60)return 0;
	ans+=d[t]*fl[t];
	for(re int i=t;i!=s;i=fr[i])e[fk[i]].v-=fl[t],e[fk[i]^1].v+=fl[t];
	return 1;
}
void dinic()
{
	while(bfs());
}
int in[100100];
int main()
{
	re int x,y,z,a;
	re long long num=0;
	scanf("%d%d",&n,&m);s=n+1;t=n+2;n+=2;
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&z,&a);
		if(z>=a)addE(x,y,z-a,1),addE(y,x,a,1),addE(x,y,1<<30,2);
		else ans+=a-z,addE(y,x,a-z,0),addE(y,x,z,1),addE(x,y,1<<30,2);
		in[x]-=a,in[y]+=a;
	}
	for(re int i=2;i<n-2;i++)
	{
		num+=in[i];
		if(in[i]>0)addE(s,i,in[i],0);
		else addE(i,t,-in[i],0);
	}
	addE(n-2,1,1<<30,0);
	addE(1,n-2,1<<30,0);
	if(num<0)addE(s,1,-num,0);
	else addE(n-2,t,num,0);
	dinic();
	printf("%lld\n",ans);
}