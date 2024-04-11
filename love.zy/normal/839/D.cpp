
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))

const int maxn=1000005;
const LL mod=1e9+7;
int mu[maxn],sum[maxn],re[maxn];
int n,m;
LL ans=0;

LL mi(int y)
{
    LL ret=1,x=2;
    while(y>0)
    {
        if(y&1)ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[x]++;m=max(m,x);
    }
    for(int mask=m;mask>=2;mask--)
    {
        int tot=0;
        for(int i=1;i*mask<=m;i++)tot+=sum[i*mask];
        LL temp=1ll*mi(tot-1)*tot%mod;
        for(int i=2;i*mask<=m;i++)temp=(temp-re[i*mask]+mod)%mod;
        re[mask]=temp;
        ans=(ans+1ll*temp*mask%mod)%mod;
    }
    printf("%lld\n",ans);
    return 0;
}