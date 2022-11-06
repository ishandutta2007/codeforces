#include<bits/stdc++.h>
#define re register
char ss[10000200];
int fa[10000100],nx[10000100][2],la[10000100],po[810],pp[10000100],q[10000100],ta,cnt=1,S,T,N;
std::bitset<755>bc[760];
int ans;
struct eg{int to,nx,c;}e[5000100];
int cct=1,ll[3100],cur[3100],d[3100];
bool bo[3100];
inline void addE(re int a,re int b,re int c)
{
	e[++cct]=(eg){b,ll[a],c};ll[a]=cct;
	e[++cct]=(eg){a,ll[b],0};ll[b]=cct;
}
void dff(re int a)
{
	bo[a]=1;re int mm=0;
	for(re int i=ll[a];i;i=e[i].nx)if(!bo[e[i].to]&&e[i].c&&e[i].to<=N-2)
	{
		dff(e[i].to);mm++;
	}
	//if(!(a&1))printf("**%d %d\n",a,mm);
}
bool spfa()
{
	q[0]=T;ta=1;
	for(re int i=1;i<=N;i++)d[i]=0,cur[i]=ll[i];d[T]=1;
	for(re int hd=0;hd!=ta;hd++)
	{
		re int x=q[hd];
		for(re int i=ll[x];i;i=e[i].nx)if(e[i^1].c&&!d[e[i].to])
		{
			d[e[i].to]=d[x]+1;
			if(e[i].to==S)return 1;q[ta++]=e[i].to;
		}
	}
	return 0;
}
int dfs(re int a,re int fl)
{
	if(a==T)return fl;
	re int fa=fl;
	for(re int&i=cur[a];i;i=e[i].nx)if(e[i].c&&d[e[i].to]==d[a]-1)
	{
		re int t=dfs(e[i].to,std::min(fa,e[i].c));
		fa-=t;e[i].c-=t;e[i^1].c+=t;
		if(!fa)return fl;
	}
	return fl-fa;
}
void flow()
{
	while(spfa())
	{
		for(re int d;d=dfs(S,1<<30);ans+=d);
	}
}
int main()
{
	re int n,q1,len;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%s",ss+1);
		len=strlen(ss+1);
		re int j1=1;
		for(re int j=1;j<=len;j++)
		{
			if(!nx[j1][ss[j]-'a'])nx[j1][ss[j]-'a']=++cnt,fa[cnt]=j1;
			j1=nx[j1][ss[j]-'a'];
		}
		po[i]=j1;pp[j1]=i;
	}
	q[ta=1]=1;
	for(re int i=1;i<=ta;i++)
	{
		re int x=q[i];
		for(re int j=0;j<2;j++)if(nx[x][j])
		{
			re int y=nx[x][j];
			q[++ta]=y;
			if(x!=1)la[y]=nx[la[x]][j];
			else la[y]=1;
			if(!pp[y])pp[y]=pp[la[y]];
		}else if(x!=1)nx[x][j]=nx[la[x]][j];
		else nx[x][j]=1;
	}
	for(re int i=1;i<=n;i++)
	{
		bc[i][pp[la[po[i]]]]=1;
		for(re int j=fa[po[i]];j!=1;j=fa[j])bc[i][pp[j]]=1;
	}
	for(re int i=1;i<=n;i++)for(re int j=1;j<=n;j++)if(bc[j][i])bc[j]|=bc[i];
	S=n*2+1;N=T=n*2+2;
	for(re int i=1;i<=n;i++)addE(S,i*2-1,1);
	for(re int i=1;i<=n;i++)addE(i*2,T,1);
	for(re int i=1;i<=n;i++)
	{
		for(re int j=1;j<=n;j++)if(bc[i][j])addE(i*2-1,j*2,1);
	}
	flow();re int mm=0;
	for(re int i=1;i<=n;i++)if(e[i*2].c)
	{
		if(!bo[i*2-1])dff(i*2-1);
	}
	printf("%d\n",n-ans);
	for(re int i=1;i<=n;i++)if(bo[i*2-1]&&(!bo[i*2]))printf("%d ",i);puts("");
}