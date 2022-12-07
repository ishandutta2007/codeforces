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
  
LL a,b,c;
int i,j;
LL x,y,z;
LL ans=5000000000000000000;

int main()
{
    scanf("%lld %lld %lld",&a,&b,&c);
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
        {
            x=a;y=b;z=c;
            if(i==2)x++;
            if(i==3){x++;y++;}
            if(j==2){z++;}
            if(j==3){y++;z++;}
            LL t=0;
            t=max(t,x);
            t=max(t,y);
            t=max(t,z);
            ans=min(ans,3*t-x-y-z);
        }
    printf("%lld",ans);
    return 0;
}