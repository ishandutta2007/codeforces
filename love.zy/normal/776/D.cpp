
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

const int maxn=100005;
int f[2*maxn];
vector<int> g[maxn];
int a[maxn];
int n,m;

int find(int now)
{
    if(f[now]==now)return now;
    else return f[now]=find(f[now]);
}

void hb(int p,int q)
{
    int l=find(p),r=find(q);
    f[l]=f[r];
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        int x,k;
        scanf("%d",&k);
        while(k--)
        {
            scanf("%d",&x);
            g[x].pb(i);
        }
    }
    for(int i=1;i<=2*m;i++)f[i]=i;
    for(int i=1;i<=n;i++)
    {
        int x=g[i][0],y=g[i][1];
        if(a[i]==0)
        {
            hb(x,y+m);
            hb(y,x+m);
        }else
        {
            hb(x,y);
            hb(x+m,y+m);
        }
    }
    for(int i=1;i<=m;i++)
    {
        int x=find(i),y=find(i+m);
        if(x==y){printf("NO");return 0;}
    }
    printf("YES");
    return 0;
}