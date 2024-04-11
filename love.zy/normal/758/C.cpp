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

LL n,m,k,x,y;
LL ma,mi,tot;
LL a[105];

int main()
{
    scanf("%lld %lld %lld %lld %lld",&n,&m,&k,&x,&y);
    LL p=k/m;LL la=k-m*p;
    if(n==1)
    {
        if(m*p<k)ma=p+1;else ma=p;
        mi=p;
        k-=m*p;
        if(y<=k)tot=ma;else tot=mi;
        printf("%lld %lld %lld",ma,mi,tot);
        return 0;
    }
    LL o=p/(2*n-2);
    p-=o*(2*n-2);
    for(int i=2;i<=n-1;i++)a[i]=2*o;
    a[1]=a[n]=o;ma=max(a[1],a[2]);
    int j=0,q=1;
    for(int i=1;i<=p;i++)
    {
        j+=q;
        if(j==n)q=-1;
        if(j==1)q=1;
        a[j]++;
        ma=max(ma,a[j]);
    }
    if(la>0)j+=q;
    if(j==1 || j==n)
    {
        mi=min(a[1],a[n]);
        if(x==j && y<=la)tot=a[x]+1;else tot=a[x];
        if(la>0)ma=max(ma,a[j]+1);
    }else
    {
        mi=min(a[1],a[n]);
        if(la>0)ma=max(ma,a[j]+1);
        if(x==j && y<=la)tot=a[x]+1;else tot=a[x];
    }
    printf("%lld %lld %lld",ma,mi,tot);
    return 0;   
}