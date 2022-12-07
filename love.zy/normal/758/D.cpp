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
  
LL ans;
char s[65];
LL a[100];
LL jz,now;
int i,j,k,l;
LL dp[100];
LL jl[100];
LL n;

int main()
{
    scanf("%lld\n",&n);
    gets(s+1);l=strlen(s+1);
    for(i=l;i>=1;i--)
    {
        if(s[i]=='0')
        {
            dp[i]=dp[i+1]+1;
            jl[i]=i+1;
            continue;
        }
        now=s[i]-48;
        dp[i]=500;
        for(j=i+1;j<=l+1 && now<n;j++)
        {
            if(dp[j]+1<dp[i])
            {
                dp[i]=dp[j]+1;
                jl[i]=j;
            }
            now=now*10+s[j]-48;
        }
    }
    k=1;a[1]=1;j=1;
    while(j!=l+1)
    {
        a[++k]=jl[j];
        j=jl[j];
    }
    ans=0;jz=1;
    for(i=k-1;i>=1;i--)
    {
        now=0;
        for(j=a[i];j<=a[i+1]-1;j++)now=now*10+s[j]-48;
        ans+=now*jz;
        jz*=n;
    }
    printf("%lld",ans);
    return 0;
}