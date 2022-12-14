#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>

#define ll long long
#define inf 1e9
#define eps 1e-10
#define md
#define N 510
using namespace std;
struct yts { int x,t,ne;} e[2*N];
int dep[N],v[N];
int ans,root,num;
void put(int x,int y)
{
	num++; e[num].x=x; e[num].t=y;
	e[num].ne=v[x]; v[x]=num;
}
void clear()
{
	num=0;
	memset(v,0,sizeof(v));
}

int dfs(int x,int fa)
{
	if (dep[x]>ans) { ans=dep[x]; root=x;}
	for (int i=v[x];i;i=e[i].ne)
	{
		int y=e[i].t;
		if (y!=fa)
		{
			dep[y]=dep[x]+1;
			dfs(y,x);
		}
	}
}

int main()
{
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	int tt;
	scanf("%d",&tt);
	int sum=0;
	while (tt--)
	{
		clear();
		int n,x,y;
		scanf("%d",&n);
		for (int i=1;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			put(x,y); put(y,x);
		}
		ans=0; root=1; dep[root]=0; dfs(1,0);
		ans=0; dep[root]=0; dfs(root,0);
		sum+=ans;
	}
	printf("%d\n",sum);
	return 0;
}