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

int a[1024],x,n,k,b[1024];

int main()
{
    scanf("%d%d%d",&n,&k,&x);
    for(int i=1;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        a[p]++;
    }
    while(k--)
    {
        int tot=0;
        for(int i=0;i<=1023;i++)
        {
            if(tot&1)
            {
                b[i^x]+=a[i]/2;
                b[i]+=a[i]-a[i]/2;
            }else
            {
                b[i^x]+=(a[i]+1)/2;
                b[i]+=a[i]-(a[i]+1)/2;
            }
            tot+=a[i];
        }
        for(int i=0;i<=1023;i++)a[i]=b[i],b[i]=0;
    }
    for(int i=1023;i>=0;i--)if(a[i]>0){printf("%d ",i);break;}
    for(int i=0;i<=1023;i++)if(a[i]>0){printf("%d",i);break;}
    return 0;
}