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

struct node
{
    int pos,rng,fre,w;
    bool operator < (const struct node p)const
    {return pos<p.pos;}
}a[100005],b[100005];
int mi,ma;
vector<int> g[10005];
int f[10005];
LL ans;
int i,j,k,m,n,l,r;

struct tree
{
    int sum;
    int ls,rs,ll,rr;
}tr[500005];

void mt(int x,int y)
{
    tr[k].ll=x;tr[k].rr=y;
    tr[k].sum=0;
    if(x==y)return;
    int mid=(x+y)>>1;
    int t=k;
    k++;tr[t].ls=k;mt(x,mid);
    k++;tr[t].rs=k;mt(mid+1,y);
}

bool cmp1(node x,node y)
{return x.rng>y.rng;}

bool cmp(int x,int y)
{
    return b[x].pos<y;
}

void add(int po,int x)
{
    if(tr[x].ll==po && tr[x].rr==po)
    {
        tr[x].sum=1;
        return;
    }
    int mid=(tr[x].ll+tr[x].rr)>>1;
    if(po<=mid)add(po,tr[x].ls);else add(po,tr[x].rs);
    tr[x].sum=tr[tr[x].ls].sum+tr[tr[x].rs].sum;
}

int findsum(int x,int y,int no)
{
    if(x==tr[no].ll && y==tr[no].rr)return tr[no].sum;
    int mid=(tr[no].ll+tr[no].rr)>>1;
    if(y<=mid)return findsum(x,y,tr[no].ls);
    if(x>=mid+1)return findsum(x,y,tr[no].rs);
    return findsum(x,mid,tr[no].ls)+findsum(mid+1,y,tr[no].rs);
}

int f1(int y,int num)
{
    if(b[g[j][y-1]].pos<num)return y+1;
    int x=1;
    while(y-x>1)
    {
        int mid=(x+y)>>1;
        if(b[g[j][mid-1]].pos>=num)y=mid;else x=mid;
    }
    if(b[g[j][x-1]].pos<num)x++;
    return x;
}

int f2(int y,int num)
{
    if(b[g[j][0]].pos>num)return 0;
    int x=1;
    while(y-x>1)
    {
        int mid=(x+y)>>1;
        if(b[g[j][mid-1]].pos<=num)x=mid;else y=mid;
    }
    if(b[g[j][y-1]].pos>num)y--;
    return y;
}

int main()
{
    scanf("%d%d",&n,&m);mi=10005;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&a[i].pos,&a[i].rng,&a[i].fre);
        mi=min(mi,a[i].fre);
        ma=max(ma,a[i].fre);
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)g[a[i].fre].push_back(i),a[i].w=g[a[i].fre].size(),b[i]=a[i];
    for(i=mi;i<=ma;i++)
    {
        if(g[i].size()==0)continue;
        k++;f[i]=k;mt(1,g[i].size());
    }
    sort(a+1,a+n+1,cmp1);
    for(i=1;i<=n;i++)
    {
        int fi=max(mi,a[i].fre-m);
        int fa=min(ma,a[i].fre+m);
        for(j=fi;j<=fa;j++)
        {
            if(g[j].size()==0)continue;
            l=f1(g[j].size(),a[i].pos-a[i].rng);
            if(l>g[j].size())continue;
            r=f2(g[j].size(),a[i].pos+a[i].rng);
            if(r<1 || l>r)continue;
            LL u=findsum(l,r,f[j]);
            if(u<=0)continue;
            //if(n>100 && i>200)printf("%d %d %d %d       i:%d %d %d %d %d %lld %lld\n",a[i].pos-a[i].rng,a[i].pos+a[i].rng,b[g[j][l-1]].pos,b[g[j][r-1]].pos,i,l,r,a[i].fre,j,u,ans);
            ans+=u;
            /*printf("%lld %lld %d %d %d\n",u,ans,a[i].pos,a[i].rng,a[i].fre);
            if(a[i].pos==4147)
            {
                printf("-----------------------------\n");
                printf("j:%d l:%d r:%d\n",j,l,r);
                printf("l-----%d %d %d\n",b[g[j][l-1]].pos,b[g[j][l-1]].rng,b[g[j][l-1]].fre);
                printf("r-----%d %d %d\n",b[g[j][r-1]].pos,b[g[j][r-1]].rng,b[g[j][r-1]].fre);
                for(k=0;k<g[j].size();k++)printf("%d %d %d\n",b[g[j][k]].pos,b[g[j][k]].rng,b[g[j][k]].fre);
                printf("-----------------------------\n");
            }*/
        }
        add(a[i].w,f[a[i].fre]);
    }
    printf("%lld",ans);
    return 0;
}