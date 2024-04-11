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

struct answer
{
    int num,water;
}dp[2][10005];
int a[105],b[105];
int i,j,k,l,m,n,c;

int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&b[i]);
    memset(dp,0x3f3f3f3f,sizeof(dp));
    c=0;m=0;k=0;
    for(i=0;i<=0;i++)dp[c][i].num=dp[c][i].water=0;
    for(i=1;i<=n;i++)
    {
        m+=b[i];
        k+=a[i];
        c^=1;
        for(j=1;j<=m;j++)dp[c][j].num=dp[c][j].water=0x3f3f3f3f;
        for(j=0;j<=m;j++)
        {
            if(j<b[i]){dp[c][j]=dp[c^1][j];continue;}
            if(dp[c^1][j-b[i]].num+1<dp[c][j].num)
            {
                dp[c][j].num=dp[c^1][j-b[i]].num+1;
                dp[c][j].water=dp[c^1][j-b[i]].water+a[i];
            }
            if(dp[c^1][j-b[i]].num+1==dp[c][j].num && dp[c^1][j-b[i]].water+a[i]>dp[c][j].water)
            {
                dp[c][j].num=dp[c^1][j-b[i]].num+1;
                dp[c][j].water=dp[c^1][j-b[i]].water+a[i];
            }
            if(dp[c^1][j].num<dp[c][j].num || (dp[c][j].num==dp[c^1][j].num && dp[c][j].water<dp[c^1][j].water))
                dp[c][j]=dp[c^1][j];
            if(dp[c][j].num>100)dp[c][j]=dp[c^1][j];
        }
    }
    int temp=k;
    l=101;i=k;k=0;
    for(;i<=m;i++)
    {
        if(dp[c][i].num<l || (dp[c][i].num==l && dp[c][i].water>k))
        {l=dp[c][i].num;k=dp[c][i].water;}
    }
    printf("%d %d",l,temp-k);
    return 0;
}