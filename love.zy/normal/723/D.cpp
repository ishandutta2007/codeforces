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
  
char s[55][55];
int a[55][55];
struct squ
{
    int num;
    int square;
    bool operator < (const struct squ p)const
    {return square<p.square;}
}sq[2600];

struct point
{
    int x,y;
    point(int x=0,int y=0):x(x),y(y){}
};

int i,j,k,l,n,m,t;

int d[4][2]={0,1,1,0,0,-1,-1,0};

bool law(int x,int y)
{
    if(x<1 || x>n)return false;
    if(y<1 || y>m)return false;
    return a[x][y]==0;
}

int bfs(int x,int y)
{
    int tot=0;
    point t=point(x,y);
    a[x][y]=k;
    queue<point> q;
    while(!q.empty())q.pop();
    q.push(t);
    while(!q.empty())
    {
        point u=q.front();
        tot++;q.pop();
        for(int i=0;i<=3;i++)
            if(law(u.x+d[i][0],u.y+d[i][1]))
            {
                point v=point(u.x+d[i][0],u.y+d[i][1]);
                q.push(v);
                a[v.x][v.y]=k;
            }
    }
    return tot;
}

int main()
{
    scanf("%d %d %d\n",&n,&m,&t);
    for(i=1;i<=n;i++)
    {
        gets(s[i]+1);
        for(j=1;j<=m;j++)
            if(s[i][j]=='*')a[i][j]=-1;
    }
    k=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j]==0)
            {
                k++;
                sq[k].num=k;
                sq[k].square=bfs(i,j);
            }
    for(i=1;i<=n;i++)
    {
        j=a[i][1];
        if(j>0)sq[j].square=100000;
        j=a[i][m];
        if(j>0)sq[j].square=100000;
    }
    for(i=1;i<=m;i++)
    {
        j=a[1][i];
        if(j>0)sq[j].square=100000;
        j=a[n][i];
        if(j>0)sq[j].square=100000;
    }
    sort(sq+1,sq+1+k);
    k=1;
    while(sq[k].square>0 && sq[k].square<3000)k++;
    k--;
    k-=t;l=0;
    for(int p=1;p<=k;p++)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(a[i][j]==sq[p].num)
                {
                    l++;
                    a[i][j]=-1;
                }
    }
    printf("%d\n",l);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)if(a[i][j]>=0)printf(".");else printf("*");
        printf("\n");
    }
    return 0;
}