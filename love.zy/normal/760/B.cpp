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
  
LL n,m,k;

bool judge(LL x)
{
    LL l=k-1,r=n-k;
    LL s=x*(x-1)/2;
    LL sl=s,sr=s;
    if(l<x-1)sl-=(x-1-l)*(x-l)/2;
    if(l>x-1)sl+=l-x+1;
    if(r<x-1)sr-=(x-1-r)*(x-r)/2;
    if(r>x-1)sr+=r-x+1;
    return sl+sr+x<=m;
}

int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    LL l=0,r=m;
    while(r-l>1)
    {
        LL mid=(l+r)>>1;
        if(judge(mid))l=mid;else r=mid;
    }
    if(judge(l+1))l++;
    printf("%lld",l);
    return 0;
}