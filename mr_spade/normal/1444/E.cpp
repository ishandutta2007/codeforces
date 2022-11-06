#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n;
int p[N];
vector<int> e[N];
int dp[N][N],tmp[N][N];
int bk[N],tbk[N],vis[N];
inline bool cmp(int (*a)[N],int t,int x,int y)
{
	if(x==0)
		return 1;
	else if(y==0)
		return 0;
	register int i;
	for(i=t;i>=0;i--)
		if(a[x][i]!=a[y][i])
			return a[x][i]<a[y][i];
	return 0;
}
inline int get(int (*a)[N],int *bk,int t,int x,int father)
{
	int d=0;
	for(int y:e[x])
		if(y!=father&&!bk[y]&&cmp(a,t,d,y))
			d=y;
	return d;
}
inline bool check(int t,int x,int father)
{
	int d,flag;
	register int i;
	for(int y:e[x])
		if(y!=father)
			memcpy(tmp[y],dp[y],sizeof(dp[y])),tbk[y]=bk[y];
	for(i=t;i>=0;i--)
	{
		flag=0;
		for(int y:e[x])
			if(y!=father&&tmp[y][i])
				flag++;
		if(flag>1)
			return 0;
		else if(flag==1)
			continue;
		else
		{
			d=get(tmp,tbk,i-1,x,father);
			memset(tmp[d],0,sizeof(tmp[d]));tbk[d]=i;
		}
	}
	for(int y:e[x])
		if(y!=father&&!tbk[y])
			return 0;
	return 1;
}
void dfs(int x,int father)
{
	int d,flag;
	register int i;
	p[x]=father;
	for(int y:e[x])
		if(y!=father)
			dfs(y,x);
	for(i=n-1;i>=0;i--)
	{
		flag=0;
		for(int y:e[x])
			if(y!=father&&dp[y][i])
			{
				flag=1;
				break;
			}
		if(flag)
			dp[x][i]=1;
		else if(!check(i-1,x,father))
			d=get(dp,bk,i-1,x,father),memset(dp[d],0,sizeof(dp[d])),bk[d]=i,dp[x][i]=1;
	}
}
int dfs2(int x,int father)
{
	int res=father?x:0,d;
	for(int y:e[x])
		if(y!=father&&!vis[y]&&bk[d=dfs2(y,x)]>bk[res])
			res=d;
	return res;
}
signed main()
{
	int x,y,r=1;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);bk[0]=-1;
	while(x=dfs2(r,0))
	{
		printf("? %d %d\n",x,p[x]);fflush(stdout);
		scanf("%d",&y);
		if(y==x)
			r=x,vis[p[x]]=1;
		else
			vis[x]=1;
	}
	printf("! %d\n",r);fflush(stdout);
	return 0;
}