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

int i,t;
LL n,m,maxx;

LL gcd(LL a,LL b)
{
    if(b==0)return a;else return gcd(b,a%b);
}

void tgcd(LL a,LL b,LL& d,LL& x,LL& y)//
{
	if(!b){d=a;x=1;y=0;}
	else{tgcd(b,a%b,d,y,x);y-=x*(a/b);}
}

LL doit(LL a,LL b)
{
    LL c=b-a;
    LL d,x,y;
    tgcd(2*n,-2*m,d,x,y);
    if(c%d)return maxx+1;
    LL tmp=2*m/d;
    x*=c/d;
    if(tmp<0)tmp=-tmp;
    x=(x%tmp+tmp)%tmp;
    LL ans=2*x*n+a;
    if(ans<0 || ans>maxx)return maxx+1;
    return ans;
}

LL work(LL a,LL b)
{
    LL ans=maxx+1;
    ans=min(ans,doit(-a,-b));
    ans=min(ans,doit(-a,b));
    ans=min(ans,doit(a,-b));
    ans=min(ans,doit(a,b));
    if(ans==maxx+1)return -1;else return ans;
}

int main()
{
    scanf("%lld %lld %d",&n,&m,&t);
    maxx=n*m/gcd(n,m);
    for(i=1;i<=t;i++)
    {
        LL x,y;
        scanf("%lld %lld",&x,&y);
        printf("%lld\n",work(x,y));
    }
    return 0;
}