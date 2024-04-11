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
#define lowbit(x) (x&(-x))
  
struct edge
{
    int from,to,flag;
    edge(int from=0,int to=0,int flag=0):from(from),to(to),flag(flag){}
}edg[50005];
bool used[50005];
int du[205];
int stac[50005];
vector<int> odd;
vector<int> g[205];
queue<int> q;
bool vis[205];

int i,j,k,l,m,n,m1,T,sta;

int other(int e,int u)
{
    if(edg[e].from==u)return edg[e].to;else return edg[e].from;
}

void dfs(int x)
{
	stac[++sta]=x;
	for(unsigned int i=0;i<g[x].size();i++)
	{
		if(used[g[x][i]])continue;
		used[g[x][i]]=true;
		dfs(other(g[x][i],x));
		break;
	}
}

void Fleury(int x)
{
	sta=1;stac[sta]=x;
	while(sta>=1)
	{
		x=stac[sta];
        vis[x]=true;
		bool f=false;
		for(unsigned int i=0;i<g[x].size();i++)
		{
			if(!used[g[x][i]]){f=true;break;}
		}
		if(!f)q.push(stac[sta--]);
		else 
		{
			sta--;
			dfs(stac[sta+1]);
		}
	}
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        odd.clear();
        while(!q.empty())q.pop();
        memset(du,0,sizeof(du));
        memset(edg,0,sizeof(edg));
        memset(used,0,sizeof(used));
        memset(vis,0,sizeof(vis));
        for(i=0;i<=n;i++)g[i].clear();
        for(i=1;i<=m;i++)
        {
            scan2(j,k);
            du[j]++;du[k]++;
            edg[i]=edge(j,k,0);
            g[j].push_back(i);
            g[k].push_back(i);
        }
        for(i=1;i<=n;i++)
            if(du[i]%2!=0)odd.push_back(i);
        printf("%d\n",n-odd.size());
        m1=m;
        unsigned int t=0;
        while(t<odd.size())
        {
            edg[++m1]=edge(odd[t],odd[t+1],0);
            g[odd[t]].push_back(m1);
            g[odd[t+1]].push_back(m1);
            t+=2;
        }
        for(i=1;i<=n;i++)if(!vis[i])Fleury(i);
        while(!q.empty())
        {
            int x=q.front();q.pop();
            if(q.empty())break;
            int y=q.front();
            for(i=0;i<g[x].size();i++)
            {
                k=g[x][i];
                if(other(k,x)==y && edg[k].flag==0)
                {
                    if(edg[k].from==x)edg[k].flag=1;else edg[k].flag=-1;
                    break;
                }
            }
        }
        for(i=1;i<=m;i++)
            if(edg[i].flag>0)printf("%d %d\n",edg[i].from,edg[i].to);else printf("%d %d\n",edg[i].to,edg[i].from);
    }
    return 0;
}