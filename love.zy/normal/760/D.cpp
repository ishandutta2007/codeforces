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
  
const int maxn=100005;

int a[maxn];
LL s[maxn];
int i,j,k,n;
LL ans=0;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    s[0]=0;
    for(i=1;i<=n;i++)
    {
        s[i]=s[i-1]+20;
        if(a[i]<90)s[i]=min(s[i],50ll);
        if(a[i]<90)continue;
        k=lower_bound(a,a+i,a[i]-89)-a;
        s[i]=min(s[i],s[k-1]+50);
        if(a[i]<1440)s[i]=min(s[i],120ll);
        if(a[i]<1440)continue;
        k=lower_bound(a,a+i,a[i]-1439)-a;
        s[i]=min(s[i],s[k-1]+120);
    }
    for(i=1;i<=n;i++)
    {
        printf("%lld\n",max(0ll,s[i]-ans));
        ans=max(ans,s[i]);
    }
    return 0;
}