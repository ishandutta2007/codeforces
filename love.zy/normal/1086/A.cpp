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

const int maxn=2005;
struct label
{
    int x,y;
    int dis;
}a,b,c;
label da[maxn][maxn], db[maxn][maxn], dc[maxn][maxn];
queue<pii> q;
vector< pii > ans;
bool vis[maxn][maxn];
int dir[4][2]={{0,1}, {1, 0}, {0,-1}, {-1,0}};

void BFS(int x,int y,label s[][maxn])
{
    for(int i=0;i<=1100;i++)
        for(int j=0;j<=1100;j++)
            s[i][j]={-1,-1,(int)1e7};
    s[x][y]={-2,-2,0};
    while(!q.empty())q.pop();
    q.push(mp(x,y));
    while(!q.empty())
    {
        pii t = q.front(); q.pop();
        for(int k=0; k<4;k++)
        {
            int xx=t.fi+dir[k][0];
            int yy=t.se+dir[k][1];
            if(xx < 0 || xx > 1100 || yy<0 || yy>1100 || s[xx][yy].dis < 1e7) continue;
            s[xx][yy] = {t.fi, t.se, s[t.fi][t.se].dis + 1};
            q.push(mp(xx,yy));
        }
    }
}

void mark(label s[][maxn], int x,int y)
{
    while(x >= 0 && y>=0)
    {
        vis[x][y]=true;
        int tmpx = s[x][y].x;
        int tmpy = s[x][y].y;
        x = tmpx; y = tmpy;
    }
}

int main()
{
    scanf("%d%d",&a.x,&a.y);
    scanf("%d%d",&b.x,&b.y);
    scanf("%d%d",&c.x,&c.y);
    BFS(a.x, a.y, da);
    BFS(b.x, b.y, db);
    BFS(c.x, c.y, dc);
    int tx = -1, ty = -1, dd = 1e7;
    for(int i=0;i<=1100;i++)
        for(int j=0;j<=1100;j++)
        {
            int fk = da[i][j].dis + db[i][j].dis + dc[i][j].dis;
            if(fk < dd)
            {
                dd = fk;
                tx=i;ty=j;
            }
        }
    mark(da, tx, ty);
    mark(db, tx, ty);
    mark(dc, tx, ty);
    for(int i=0;i<=1100;i++)
        for(int j=0;j<=1100;j++)
            if(vis[i][j])ans.pb(mp(i,j));
    printf("%d\n",(int)ans.size());
    for(pii t : ans ) printf("%d %d\n",t.fi,t.se);
    return 0;
}