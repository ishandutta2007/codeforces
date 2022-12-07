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
 
LL tot[200005];
LL a[100005];
LL n,i,m;
LL ans;

int main()
{
    scanf("%lld%lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        tot[a[i]]++;
    }
    for(i=1;i<=n;i++)
    {
        if(m==0)ans+=tot[a[i]]-1;
        else ans+=tot[a[i]^m];
    }
    printf("%lld",ans/2);
    return 0;
}