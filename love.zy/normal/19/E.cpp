#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lc o << 1
#define rc o << 1 | 1
#define lowbit(x) (x&(-x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
#define other(x,y) ((edg[x].p==y)?(edg[x].q):(edg[x].p))

const int maxn=10005;

struct edge
{
	int p,q;
	bool isTree,mark;
	edge(int p=0,int q=0,bool isTree=false,bool mark=false):p(p),q(q),isTree(isTree),mark(mark){}
}edg[maxn];

vector<int> g[maxn];
bool vis[maxn];
int a[maxn],odd[maxn],even[maxn],fa[maxn];
int tot,ans;

void dfs(int x,int y,int fat)
{
	vis[x]=true;
	a[x]=y;
	for(unsigned int i=0;i<g[x].size();i++)
	{
		int v=other(g[x][i],x);
		if(v==fat)continue;
		if(vis[v])
		{
			if(a[x]<=a[v])continue;
			int temp=a[x]-a[v];
			if(temp%2==0)
			{
				odd[x]++;
				odd[v]--;
				edg[g[x][i]].mark=true;
			}else
			{
				even[x]++;
				even[v]--;
			}
		}else
		{
			edg[g[x][i]].isTree=true;
			dfs(v,y+1,x);
			odd[x]+=odd[v];
			even[x]+=even[v];
			fa[v]=g[x][i];
		}
	}
}

int main()
{
	int n,m,i,j,k;
	scan2(n,m);
	for(i=1;i<=n;i++)g[i].clear();
	for(i=1;i<=m;i++)
	{
		scan2(j,k);
		edg[i]=edge(j,k,false,false);
		g[j].push_back(i);
		g[k].push_back(i);
	}
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	memset(odd,0,sizeof(odd));
	memset(even,0,sizeof(even));
	tot=0;
	for(i=1;i<=n;i++)if(!vis[i])dfs(i,1,-1);
	for(i=1;i<=m;i++)if(edg[i].mark)tot++;
	if(tot==0)
	{
		printf("%d\n",m);
		for(i=1;i<=m;i++)
		{
			if(i>1)printf(" ");
			printf("%d",i);
		}
		return 0;
	}
	if(tot==1)
	{
		priority_queue<int,vector<int>,greater<int> > q;
		while(!q.empty())q.pop();ans=0;
		for(i=1;i<=n;i++)if(odd[i]==1 && even[i]==0){q.push(fa[i]);ans++;}
		for(i=1;i<=m;i++)if(edg[i].mark && (!edg[i].isTree)){q.push(i);ans++;}
		printf("%d\n",ans);
		while(ans--)
		{
			printf("%d",q.top());q.pop();
			if(ans>0)printf(" ");
		}
		return 0;
	}
	priority_queue<int,vector<int>,greater<int> > q;
	while(!q.empty())q.pop();ans=0;
	for(i=1;i<=n;i++)
		if(odd[i]==tot && even[i]==0){ans++;q.push(fa[i]);}
	printf("%d\n",ans);
	while(ans--)
	{
		printf("%d",q.top());q.pop();
		if(ans>0)printf(" ");
	}
    return 0;
}