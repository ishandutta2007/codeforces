#include<bits/stdc++.h>
#define re register
struct eg{int to,nx,c,w;}e[200100];
int cnt=1,q[70010],la[15100],cur[15100],N,S,T,n,m;
long long d[15100];
unsigned short hd,ta;
inline void addE(re int a,re int b,re int c,re int d)
{
	e[++cnt]=(eg){b,la[a],c,d};la[a]=cnt;
	e[++cnt]=(eg){a,la[b],0,-d};la[b]=cnt;
}
long long ann,ans;
bool bo[15100],in[15100];
bool spfa()
{
	q[0]=S;ta=1;
	for(re int i=1;i<=N;i++)d[i]=1ll<<60,cur[i]=la[i];d[S]=0;
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
	return d[T]<(1ll<<60);
}
int dfs(re int a,re int fl)
{
	if(a==T)return fl;
	re int fa=fl;
	bo[a]=1;
	for(re int&i=cur[a];i;i=e[i].nx)if(!bo[e[i].to]&&e[i].c&&d[e[i].to]==d[a]+e[i].w)
	{
		re int t=dfs(e[i].to,std::min(fa,e[i].c));
		fa-=t;e[i].c-=t;e[i^1].c+=t;ans+=(long long)t*e[i].w;
		if(!fa)return fl;
	}
	return fl-fa;
}
long long qq[100100],qq1[100100],tta;
void flow()
{
	while(spfa())
	{
		memset(bo,0,sizeof(bo));
		ann+=dfs(S,1<<30);
		if(ann!=0)
		qq[++tta]=ann,qq1[tta]=ans;
	}
}
int main()
{
	re int n,m,x,y,w,q;
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		addE(x,y,1,w);
	}
	S=1;N=T=n;
	flow();
	scanf("%d",&q);
	for(;q--;)
	{
		scanf("%d",&x);
		re double as=1e9;
		for(re int i=1;i<=tta;i++)as=std::min(as,(double)(x+qq1[i])/qq[i]);
		printf("%.10lf\n",as);
	}
}