#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007
#define min(x,y) ((x)<(y)?(x):(y))
ll n,m,t,ans;
int main()
{
    scanf("%lld %lld",&n,&m);
    for(ll i=1,t,t1,t2;i<=min(n,m);i=t+1)
    {
        t=min(n/(n/i),m);t1=i+t;t2=t-i+1;if(t1&1) t2>>=1;else t1>>=1;
        ans=(ans+(t1%MOD)*(t2%MOD)%MOD*((n/i)%MOD)%MOD)%MOD;
    }
    printf("%lld\n",((n%MOD)*(m%MOD)%MOD-ans+MOD)%MOD);
}