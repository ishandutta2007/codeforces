#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 3005
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
ll ans;
struct zgz
{
	int next,to;
}edge[N<<1];
int head[N],cnt=1;
void add(int from,int to)
{
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt++;
}
ll dp[N][N];// i-j 0 - dis-1 
int fa[N][N];// root is i j's father
int root;
int sub[N][N];// root is i j's subtree size
ll DP(int x,int y)
{
	if(x==y) return 0;
	if(dp[x][y]!=-1) return dp[x][y];
	ll ret=0;

	int fx=fa[y][x],fy=fa[x][y];
	ret=sub[y][x]*sub[x][y]+max(DP(fa[y][x],y),DP(x,fa[x][y]));

	dp[x][y]=ret;
	return ret;
}

void dfs(int x)
{
	sub[root][x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
	    int to=edge[i].to;
		if(to!=fa[root][x])
		{
			fa[root][to]=x;
			dfs(to);
			sub[root][x]+=sub[root][to];
		}
	}
}
int main()
{
	memset(dp,-1,sizeof(dp));
	n=read();
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();
		add(x,y),add(y,x);
	}
	for(int i=1;i<=n;i++)
	{
		root=i;
		dfs(root);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	ans=max(ans,DP(i,j));
	cout<<ans<<endl;
}