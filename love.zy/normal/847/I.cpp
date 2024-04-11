
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

LL sum[255][255],tt[255][255];
int vis[255][255];
queue< pii > qq;
int n,m,p,q;
char s[255][255];
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

bool check(int x,int y,int lb)
{
    if(x<1 || y<1 || x>n || y>m || s[x][y]=='*' || vis[x][y]==lb)return false;
    return true;
}

void BFS(int x,int y,int lb)
{
    while(!qq.empty())qq.pop();
    int now=(s[x][y]-64)*p;
    tt[x][y]=now;
    qq.push(mp(x,y));
    //printf("%d %d::::\n",x,y);
    vis[x][y]=lb;
    while(!qq.empty())
    {
        pii t=qq.front();qq.pop();
        //printf("%d %d\n",t.fi,t.se);
        sum[t.fi][t.se]+=tt[t.fi][t.se];
        if(tt[t.fi][t.se]<=1)continue;
        for(int i=0;i<4;i++)
        {
            int u=t.fi+d[i][0];
            int v=t.se+d[i][1];
            if(check(u,v,lb))
            {
                tt[u][v]=tt[t.fi][t.se]>>1;
                qq.push(mp(u,v));
                vis[u][v]=lb;
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&p,&q);
    for(int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='.' || s[i][j]=='*')continue;
            int lb=i*n+j;
            BFS(i,j,lb);
        }
    int cnt=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(sum[i][j]>q)cnt++;
    printf("%d\n",cnt);
    return 0;
}