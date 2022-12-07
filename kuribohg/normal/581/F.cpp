#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=5010;
const int INF=1000000000;
int n,f[MAXN][MAXN][2],dp[MAXN][MAXN][2],size[MAXN],d[MAXN],root;
int head[MAXN],to[MAXN<<1],next[MAXN<<1],cnt=1;
inline void adde(int f,int t)
{
	cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
	cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
	for(int i=head[x];i;i=next[i])
		if(to[i]!=fa)
		{
			DFS(to[i],x);
			if(!size[x])
			{
				for(int k=0;k<=size[to[i]];k++)
				{
					f[x][k][0]=min(f[x][k][0],f[to[i]][k][0]);
					f[x][k][0]=min(f[x][k][0],f[to[i]][k][1]+1);
					f[x][k][1]=min(f[x][k][1],f[to[i]][k][0]+1);
					f[x][k][1]=min(f[x][k][1],f[to[i]][k][1]);
				}
			}
			for(int k=0;k<=size[x]+size[to[i]];k++) dp[x][k][0]=dp[x][k][1]=INF;
			if(size[x])
			{
				for(int p=0;p<=size[x];p++)
					for(int k=0;k<=size[to[i]];k++)
					{
						dp[x][p+k][0]=min(dp[x][p+k][0],f[x][p][0]+f[to[i]][k][0]);
						dp[x][p+k][0]=min(dp[x][p+k][0],f[x][p][0]+f[to[i]][k][1]+1);
						dp[x][p+k][1]=min(dp[x][p+k][1],f[x][p][1]+f[to[i]][k][0]+1);
						dp[x][p+k][1]=min(dp[x][p+k][1],f[x][p][1]+f[to[i]][k][1]);
					}
				for(int k=0;k<=size[x]+size[to[i]];k++) f[x][k][0]=dp[x][k][0],f[x][k][1]=dp[x][k][1];
			}
			size[x]+=size[to[i]];
		}
	if(size[x]==0)
	{
		size[x]=1;
		f[x][1][0]=0;
		f[x][0][1]=0;
		f[x][1][1]=INF;
		f[x][0][0]=INF;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y),d[x]++,d[y]++;
	if(n==2) {puts("1");return 0;}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			f[i][j][0]=f[i][j][1]=INF;
	for(int i=1;i<=n;i++)
		if(d[i]!=1) {root=i;break;}
	DFS(root,-1);
	printf("%d\n",min(f[root][size[root]/2][0],f[root][size[root]/2][1]));
	return 0;
}