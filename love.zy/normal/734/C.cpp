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
  
const int maxn=200005;

struct spell
{
    LL x,y;
    bool operator < (const struct spell p)const
    {return y<p.y;}
}a[maxn],b[maxn];

LL x,s,n,l,k;
int i,j,m1,m2;

int main()
{
    scanf("%lld %d %d %lld %lld",&n,&m1,&m2,&x,&s);
    for(i=1;i<=m1;i++)scanf("%lld",&a[i].x);
    for(i=1;i<=m1;i++)scanf("%lld",&a[i].y);
    sort(a+1,a+m1+1);
    for(i=1;i<=m2;i++)scanf("%lld",&b[i].x);
    for(i=1;i<=m2;i++)scanf("%lld",&b[i].y);
    j=1;k=n*x;l=x;
    for(i=m2;i>=1;i--)
    {
        if(b[i].y>s)continue;
        while(j<=m1 && a[j].y<=s-b[i].y){l=min(l,a[j].x);j++;}
        k=min(k,(n-b[i].x)*l);
    }
    while(j<=m1 && a[j].y<=s){l=min(l,a[j].x);j++;}
    k=min(k,n*l);
    printf("%lld",k);
    return 0;
}