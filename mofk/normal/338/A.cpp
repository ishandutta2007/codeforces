#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
#include<iostream>
#include<cstring>
#define f(i,n) for(i=1;i<=n;i++)
#define ff(i,a,b) for(i=a;i<=b;i++)
#define F(i,n) for (i=n;i>=1;i--)
#define FF(i,a,b) for(i=a;i>=b;i--)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
const ll mod=(ll)1e9+9;
ll pwr(ll d)
{
    ll ans=1,mult=2,c=d;
    while(c)
    {
        if(c&1) ans=(ans*mult)%mod;
        c>>=1;
        mult=(mult*mult)%mod;
    }
    return ans;
}
int main(void)
{
    ll n,m,k,ans;
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    ll c=n-m;
    if(n<=c*k) printf("%I64d",m);
    else
    {
        ans=(c*(k-1)+n%k)%mod;
        ll d=n/k-c;
        ans=(ans+2*k*(pwr(d)-1+mod))%mod;
        printf("%I64d",ans);
    }
}