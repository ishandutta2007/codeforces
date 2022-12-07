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

LL dis[35];
LL d[4][2]={{0,-1},{1,0},{0,1},{-1,0}};
vector<int> g[35];
int du[35];
bool used[35][4];
int i,j,k,l,m,n;
LL dx[35],dy[35];

void DFS(int x,int f,int u)
{
        for(unsigned int i=0;i<g[x].size();i++)
        {
            if(g[x][i]==f)continue;
            int v=g[x][i];
            for(int j=0;j<=3;j++)
            {
                if(used[x][j])continue;
                dx[v]=dx[x]+d[j][0]*dis[u];
                dy[v]=dy[x]+d[j][1]*dis[u];
                used[x][j]=true;
                used[v][(j+2)%4]=true;
                break;
            }
            DFS(v,x,u-1);
        }
}

int main()
{
    dis[0]=1;
    for(i=1;i<=30;i++)dis[i]=dis[i-1]*2;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        du[x]++;du[y]++;
        if(du[x]>4 || du[y]>4){printf("NO");return 0;}
        g[x].push_back(y);g[y].push_back(x);
    }
    dx[1]=dy[1]=0;DFS(1,0,n);
    printf("YES\n");
    for(i=1;i<=n;i++)printf("%lld %lld\n",dx[i],dy[i]);
    return 0;
}