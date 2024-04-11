#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
#define int long long
const int maxn=2505,M=34005;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,T,a[maxn][maxn],tot,fa[maxn],st[maxn],F,ans,id,vis[maxn],dis[maxn];
vector<pi>e[maxn];
void dfs(int x,int fa,int dis,int y)
{
	if(a[x][y]!=dis)F=1;
	if(F==1)return;
	for(auto i:e[x])
		if(i.fi^fa)
			dfs(i.fi,x,dis+i.se,y);
}
void dfs1(int x,int fa)
{
	vis[x]=1;
	for(auto i:e[x])
		if(i.fi^fa)
			dfs1(i.fi,x);
}
void solve()
{
	n=read();
	int g=1e10,id1,id2;ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i][i]!=0){puts("NO");return;}
			if(a[i][j]!=a[j][i]){puts("NO");return;}
			if(i!=j&&a[i][j]==0){puts("NO");return;}
		}
	int x=1;vis[1]=1;
	for(int i=1;i<=n;i++)dis[i]=a[1][i];
	for(int i=2;i<=n;i++)
	{
		int Min=1e9+5,id=-1;
		for(int j=1;j<=n;j++)
			if(dis[j]<Min&&!vis[j])Min=dis[j],id=j;
		for(int j=1;j<=n;j++)
			if(vis[j]&&a[j][id]==dis[id])
				{e[j].push_back(mp(id,dis[id])),e[id].push_back(mp(j,dis[id]));break;}
		vis[id]=1;
		for(int j=1;j<=n;j++)
			dis[j]=min(dis[j],a[id][j]);
	}
	F=0;
	for(int i=1;i<=n;i++)
		dfs(i,0,0,i);
	if(F){puts("NO");return;}
	memset(vis,0,sizeof vis);
	dfs1(1,0);
	for(int i=1;i<=n;i++)if(!vis[i]){puts("NO");return;}
	puts("YES");
	for(int i=1;i<=n;i++)e[i].clear();
}
signed main()
{
//	freopen("treas.in","r",stdin);
//	freopen("treas.out","w",stdout);
	solve();
 	return 0;
}


/*********************************************************************
    :louhao088
    : 2021-11-15 08:39
*********************************************************************/