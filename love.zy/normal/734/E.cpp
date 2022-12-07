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
  
const int maxn=200005;

vector<int> g1[maxn],g2[maxn];

int belong[maxn],color[maxn],c[maxn];
int i,j,k,l,m,n;
int edg[maxn][2];

void dfs(int x)
{
    belong[x]=m;
    for(unsigned int i=0;i<g1[x].size();i++)
    {
        int v=g1[x][i];
        if(belong[v]>0)continue;
        if(color[v]!=color[x])continue;
        dfs(v);
    }
}

void ss(int now,int sum)
{
    color[now]=1;
    if(sum>n){n=sum;k=now;}
    for(unsigned int i=0;i<g2[now].size();i++)
    {
        int v=g2[now][i];
        if(color[v]==0)ss(v,sum+1);
    }
}

int main()
{
    scan(n);
    for(i=1;i<=n;i++)scan(color[i]);
    for(i=1;i<n;i++)
    {
        scan2(j,k);
        g1[j].push_back(k);
        g1[k].push_back(j);
        edg[i][0]=j;edg[i][1]=k;
    }
    m=0;
    for(i=1;i<=n;i++)
    {
        if(belong[i]==0)
        {
            m++;
            dfs(i);
        }
    }
    for(i=1;i<n;i++)
    {
        if(belong[edg[i][0]]==belong[edg[i][1]])continue;
        int u=belong[edg[i][0]];
        int v=belong[edg[i][1]];
        g2[u].push_back(v);
        g2[v].push_back(u);
        c[u]=c[edg[i][0]];
        c[v]=c[edg[i][1]];
    }
    n=0;
    memset(color,0,sizeof(color));n=1;
    ss(1,1);
    memset(color,0,sizeof(color));
    ss(k,1);
    printf("%d",n/2);
    return 0;
}