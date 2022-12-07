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
  
struct point
{
    LL x,y;
    point(LL x=0,LL y=0):x(x),y(y){}
    bool operator < (const struct point p)const
    {return x<p.x || (x==p.x && y<p.y);}
    point operator - (const struct point p)const
    {
        struct point ret;
        ret.x=x-p.x;
        ret.y=y-p.y;
        return ret;
    }
    bool operator == (const struct point p)const
    {return x==p.x && y==p.y;}
}a[50005],u[50005],d[50005];

int i,j,k,m,n;
LL ma,s;
struct point ans1,ans2,ans3;

LL area(point x,point y,point z)
{
    return abs(x.x*y.y+y.x*z.y+z.x*x.y-x.y*y.x-y.y*z.x-z.y*x.x)/2;
}

LL cha(point x,point y)
{
    return x.x*y.y-x.y*y.x;
}

int main()
{
    scanf("%d%lld",&n,&s);
    for(i=1;i<=n;i++)scanf("%lld%lld",&a[i].x,&a[i].y),a[i].x*=2,a[i].y*=2;
    sort(a+1,a+n+1);
    int ld=2;
    d[1]=a[1];d[2]=a[2];
    for(i=3;i<=n;i++)
    {
        while(ld>1 && cha(a[i]-d[ld],d[ld]-d[ld-1])>0)ld--;
        d[++ld]=a[i];
    }
    int ud=2;
    u[1]=a[1];u[2]=a[2];
    for(i=3;i<=n;i++)
    {
        while(ud>1 && cha(a[i]-u[ud],u[ud]-u[ud-1])<0)ud--;
        u[++ud]=a[i];
    }
    m=ld;
    for(i=ud;i>=1;i--)if(!(u[i]==d[m]))d[++m]=u[i];
    if(d[m]==d[1])m--;
    for(i=1;i<=m-2;i++)
    {
        k=0;
        for(j=i+1;j<=m-1;j++)
        {
            if(k<=j)k=j+1;
            LL ar=area(d[i],d[j],d[k]);
            if(ar>ma)
            {
                ma=ar;
                ans1=d[i];ans2=d[j];ans3=d[k];
            }
            while(k+1<=m)
            {
                LL t=area(d[i],d[j],d[k+1]);
                if(t<ar)break;
                if(t>ma)
                {
                    ma=t;
                    ans1=d[i];ans2=d[j];ans3=d[k+1];
                }
                ar=t;
                k++;
            }
        }
    }
    LL tx=ans1.x+ans2.x+ans3.x;
    LL ty=ans1.y+ans2.y+ans3.y;
    printf("%lld %lld\n",(tx-2*ans1.x)/2,(ty-2*ans1.y)/2);
    printf("%lld %lld\n",(tx-2*ans2.x)/2,(ty-2*ans2.y)/2);
    printf("%lld %lld\n",(tx-2*ans3.x)/2,(ty-2*ans3.y)/2); 
    return 0;
}