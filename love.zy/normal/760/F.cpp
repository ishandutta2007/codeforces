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

const LL mod=1e9+7;

LL sum[5005];
bool b[27];
LL c[5005];
char s[5005],s1[5005];
LL dp[5005][27];
int i,j,k,l,m,n;
LL ans;

LL mi(LL x,LL y)
{
    LL aa=1;
    while(y>0)
    {
        if(y&1)aa=(aa*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return aa;
}

int main()
{
    scanf("%d\n",&n);
    if(n-1<=1)c[0]=c[1]=1;
    else
    {
        l=n-1;c[0]=1;c[1]=l;
        for(i=2;i<=l;i++)
        {
            c[i]=c[i-1];
            c[i]*=(LL)(l-i+1);
            c[i]%=mod;
            c[i]*=mi((LL)i,mod-2);
            c[i]%=mod;
        }
    }
    gets(s1+1);m=1;
    s[1]=s1[1];
    for(i=2;i<=n;i++)
        if(s1[i]!=s1[i-1])s[++m]=s1[i];
    memset(b,0,sizeof(b));
    for(i=1;i<=m;i++)
    {
        int t=s[i]-96;
        if(!b[t]){sum[1]++;dp[1][t]=1;b[t]=true;}
        for(k=2;k<=m;k++)
        {
            LL t1=(sum[k-1]-dp[k-1][t]+mod)%mod;
            LL t2=dp[k][t];
            dp[k][t]=t1;
            sum[k]=(sum[k]+mod+t1-t2)%mod;
        }
    }
    for(i=1;i<=m;i++)
    {
        ans+=(sum[i]*c[i-1])%mod;
        ans%=mod;
    }
    printf("%lld",ans);
    return 0;
}