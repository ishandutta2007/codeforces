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

LL n,l,r;
LL i,j,k,m,ans;

LL mi(LL x,LL y)
{
    LL ans=1;
    while(y>0)
    {
        if(y&1)ans*=x;
        x*=x;
        y>>=1;
    }
    return ans;
}

LL find(LL x,LL y)
{
    if(x>=25)return 1;
    LL t=x;
    LL u=y;
    while(t>1)
    {
        y=(LL)(sqrt(y)+1);
        t>>=1;
    }
    LL ll=1,rr=y;
    while(rr-ll>1)
    {
        LL mid=(ll+rr)>>1;
        if(mi(mid,x)>u)rr=mid;else ll=mid;
    }
    if(mi(rr,x)>u)rr--;
    return rr;
}

LL gcd(LL x,LL y)
{
    if(x==0)return y;
    if(y==0)return x;
    return gcd(y,x%y);
}

int main()
{
    scanf("%lld %lld %lld",&n,&l,&r);
    if(n==1){printf("%lld",r-l+1);return 0;}
    if(n==2)
    {
        LL len=r-l+1;
        printf("%lld",len*(len-1));
        return 0;
    }
    LL xr=find(n-1,r);
    for(i=2;i<=xr;i++)
    {
        for(j=1;j<i;j++)
        {
            if(gcd(i,j)!=1)continue;
            LL p=mi(i,n-1);
            LL q=mi(j,n-1);
            LL le,ri;
            if(l%q==0)le=l/q;else le=l/q+1;
            ri=r/p;
            if(ri>=le)ans+=(ri-le+1)*2;
        }
    }
    printf("%lld",ans);
    return 0;
}