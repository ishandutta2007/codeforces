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

int a[105],b[105];
int i,j,k,l,m,n;

int main()
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i]+m;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        b[i+n]=b[i]+m;
    }
    for(i=2;i<=2*n;i++)
    {
        a[i-1]=a[i]-a[i-1];
        b[i-1]=b[i]-b[i-1];
    }
    for(i=1;i<=n;i++)
    {
        k=1;
        for(j=i;j<=i+n-1;j++)
            if(a[j-i+1]!=b[j])
            {k=0;break;}
        if(k>0)break;
    }
    if(k>0)printf("YES");else printf("NO");
    return 0;
}