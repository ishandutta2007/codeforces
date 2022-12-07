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
}a[200005];

LL ans[200005];
LL check[200005][30];
LL c[30];
LL sum,tot;
LL i,j,k,l,n,m;

int main()//x&y+x|y==x+y     x&y+x^y==x|y
{
    scanf("%lld",&n);
    for(i=1;i<=n;i++)scanf("%lld",&a[i].x);
    for(i=1;i<=n;i++)scanf("%lld",&a[i].y);
    for(i=1;i<=n;i++)ans[i]=a[i].x+a[i].y,sum+=ans[i];
    if(sum%(n*2)!=0){printf("-1");return 0;}
    sum/=2*n;
    for(i=1;i<=n;i++)
    {
        ans[i]-=sum;
        if(ans[i]%n!=0){printf("-1");return 0;}
        ans[i]/=n;
    }
    memset(check,0,sizeof(check));
    for(i=1;i<=n;i++)
    {
        LL t=ans[i];
        j=0;tot=1;
        while(t>0)
        {
            if(t%2==0)check[i][j]=0;else check[i][j]=tot;
            j++;tot*=2;t>>=1;
        }
    }
    for(i=0;i<30;i++)
        for(j=1;j<=n;j++)c[i]+=check[j][i];
    for(i=1;i<=n;i++)
    {
        sum=0;tot=0;
        for(j=0;j<30;j++)
        {
            if(ans[i]&((1LL)<<j)){sum+=c[j];tot+=((1LL)<<j)*n;continue;}
            tot+=c[j];
        }
        if(sum!=a[i].x || tot!=a[i].y){printf("-1");return 0;}
    }
    for(i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%lld",ans[i]);
    }
    return 0;
}