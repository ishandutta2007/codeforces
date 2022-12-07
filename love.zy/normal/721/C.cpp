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
  
const int maxn=5005;

struct edge
{
    int to,time;
    edge(int to=0,int time=0):to(to),time(time){}
}edg[maxn];

int dp[maxn][maxn];
int num[maxn];
int last[maxn][maxn];
vector<int> g[maxn];
int i,j,k,l,m,n,T;
queue<int> q;

int main()
{
    scan3(n,m,T);
    memset(dp,0x3f3f3f3f,sizeof(dp));
    memset(num,0,sizeof(num));
    for(i=1;i<=m;i++)
    {
        scan3(j,k,l);
        edg[i]=edge(k,l);
        g[j].push_back(i);
        num[k]++;
    }
    dp[1][1]=0;
    while(!q.empty())q.pop();
    for(i=1;i<=n;i++)if(num[i]==0)q.push(i);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        for(i=0;i<g[x].size();i++)
        {
            int side=g[x][i];
            int v=edg[side].to;
            num[v]--;
            if(num[v]==0)q.push(v);
            for(j=1;j<=n-1;j++)
            {
                if(dp[x][j]>=T)continue;
                if(dp[x][j]+edg[side].time<dp[v][j+1])
                {
                    dp[v][j+1]=dp[x][j]+edg[side].time;
                    last[v][j+1]=x;
                }
            }
        }
    }
    m=0;memset(num,0,sizeof(num));
    for(i=n;i>=1;i--)
        if(dp[n][i]<=T){j=i;break;}
    printf("%d\n",j);
    i=n;m=j;
    while(j>0)
    {
        num[j]=i;
        i=last[i][j];
        j--;
    }
    printf("%d",num[1]);
    for(i=2;i<=m;i++)printf(" %d",num[i]);
    return 0;
}