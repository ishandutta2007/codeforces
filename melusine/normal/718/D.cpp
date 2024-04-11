#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
struct bbian
{
	int u,v,nex;
}a[800004];
int head[100005],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
__uint128_t ha[100005];
__uint128_t tha[100005];
map<__uint128_t,int>ma;
void dfs(int x,int f)
{
	ha[x]=1121131433448687LL;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs(a[i].v,x);
		ha[x]=(ha[x]+ha[a[i].v]);
	}
	ha[x]=ha[x]*ha[x]*ha[x]+ha[x]+123456789;
}
void calc(int x,int f)
{
	ha[x]=1121131433448687LL;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		ha[x]=(ha[x]+ha[a[i].v]);
	}
	ha[x]=ha[x]*ha[x]*ha[x]+ha[x]+123456789;
}
void dfs2(int x,int f)
{
	if(f!=0)
	{
		calc(f,x);
		calc(x,0);
	}
	tha[x]=ha[x];
	for(int i=head[x];i;i=a[i].nex)
	{
		if(a[i].v==f)continue;
		dfs2(a[i].v,x);
	}
	if(f!=0)
	{
		calc(x,f);
		calc(f,0);
	}
}
int rd[200005];
int main()
{
	int n,x,y;
	n=read();
	for(int i=1;i<=n-1;i++)
	{
		x=read();
		y=read();
		addb(x,y);
		addb(y,x);
		rd[x]++;
		rd[y]++;
	}
	dfs(1,0);
	dfs2(1,0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(rd[i]==4)continue;
		//printf("%llu\n",tha[i]);
		if(ma.count(tha[i]))continue; 
		ma[tha[i]]=1;
		ans++;
	}
	printf("%d\n",ans); 
	return 0;
}