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
 
int a[100005],b[100005];
int i,j,l,m,n,r,ans;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        l+=a[i];
        r+=b[i];
    }
    ans=abs(l-r),m=0;
    for(i=1;i<=n;i++)
    {
        j=abs((l-a[i]+b[i])-(r-b[i]+a[i]));
        if(j>ans){ans=j;m=i;}
    }
    printf("%d",m);
    return 0;
}