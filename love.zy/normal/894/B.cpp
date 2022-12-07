#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod=1e9+7;

ll mi(ll x,ll y)
{
    ll ret=1;
    while(y>0)
    {
        if(y&1)ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}

ll n,m,k;

int main()
{
    scanf("%lld%lld%lld",&n,&m,&k);
    if(k<0 && (n&1)!=(m&1))printf("0\n");
    else printf("%lld\n",mi(mi(2ll,n-1),m-1));
    return 0;
}