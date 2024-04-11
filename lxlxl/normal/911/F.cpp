#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;

int n,root;
int d[maxn];
struct edge{int y,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}

int dep[maxn],fa[maxn],dis[maxn],f[maxn],g[maxn];
void build(const int x)
{
	f[x]=0;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
	{
		fa[y]=x; build(y);
		f[x]=max(f[x],f[y]+1);
	}
}
int pre[maxn],suf[maxn],t[maxn],tp;
void build2(const int x)
{
	tp=0;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
		t[++tp]=f[y];
	for(int i=1;i<=tp;i++)
		pre[i]=max(pre[i-1],t[i]);
	suf[tp+1]=0;
	for(int i=tp;i>=1;i--)
		suf[i]=max(suf[i+1],t[i]);
	for(int k=fir[x],y=a[k].y,i=1;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
		g[y]=1+max(g[x],max(pre[i-1],suf[i+1])),i++;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
		build2(y);
}
void dfs(const int x)
{
	dis[x]=x;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
	{
		fa[y]=x,dep[y]=dep[x]+1;
		dfs(y);
		if(dep[dis[y]]>dep[dis[x]]) dis[x]=dis[y];
	}
}
int n1,n2,v1[maxn],v2[maxn];
int ans[maxn][3],an;
ll re;

void search(const int x,int las1,int las2)
{
	if(v1[x]) las1=dep[x];
	if(v2[x]) las2=dep[x];
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=fa[x])
		search(y,las1,las2);
	if(!(v1[x]|v2[x]))
	{
		++an;
		if(dep[n1]-2*las1>dep[n2]-2*las2) 
			ans[an][0]=n1,ans[an][1]=x,ans[an][2]=x,re+=dep[n1]+dep[x]-2*las1;
		else 
			ans[an][0]=n2,ans[an][1]=x,ans[an][2]=x,re+=dep[n2]+dep[x]-2*las2;
	}
}

int main()
{
	scanf("%d",&n);
	if(n==2) 
	{
		printf("1\n1 2 2\n");
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		ins(x,y),ins(y,x);
		d[x]++,d[y]++;
	}
	build(1); build2(1);
	for(int i=1;i<=n;i++) 
		if(f[i]+g[i]>f[root]+g[root]||(f[i]+g[i]==f[root]+g[root]&&d[i]>d[root])) root=i;
	fa[root]=0,dep[root]=1,dfs(root);
	
	n1=0,n2=0;
	for(int k=fir[root],y=a[k].y;k;k=a[k].nex,y=a[k].y)
	{
		if(dep[dis[y]]>dep[n2]) n2=dis[y];
		if(dep[dis[n1]]<dep[dis[n2]]) swap(n1,n2);
	}
	int tmp;
	tmp=n1; while(tmp) v1[tmp]=1,tmp=fa[tmp];
	tmp=n2; while(tmp) v2[tmp]=1,tmp=fa[tmp];
	
	search(root,0,0);
	while(n2!=root)
	{
		++an;
		ans[an][0]=n1,ans[an][1]=n2,ans[an][2]=n2;
		re+=dep[n1]+dep[n2]-2;
		n2=fa[n2];
	}
	while(n1!=root)
	{
		++an;
		ans[an][0]=n1,ans[an][1]=n2,ans[an][2]=n1;
		re+=dep[n1]-1;
		n1=fa[n1];
	}
	printf("%I64d\n",re);
	for(int i=1;i<=an;i++) printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
	
	return 0;
}