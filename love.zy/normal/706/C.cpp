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

LL dp[maxn][2];
LL a[maxn];
string st[maxn];
string ss[maxn];
int i,j,k,l,m,n;

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<=n;i++)
    {
        cin>>st[i];
        l=st[i].length();
        ss[i]="";
        for(j=l-1;j>=0;j--)ss[i]+=st[i][j];
    }
    dp[0][0]=dp[0][1]=0;
    dp[1][0]=0;dp[1][1]=a[1];
    for(i=2;i<=n;i++)
    {
        dp[i][0]=dp[i][1]=1e18;
        if(st[i]>=st[i-1])dp[i][0]=min(dp[i][0],dp[i-1][0]);
        if(st[i]>=ss[i-1])dp[i][0]=min(dp[i][0],dp[i-1][1]);
        if(ss[i]>=st[i-1])dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
        if(ss[i]>=ss[i-1])dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
    }
    if(dp[n][0]==1e18 && dp[n][1]==1e18)printf("-1");else printf("%lld",min(dp[n][0],dp[n][1]));
    return 0;
}