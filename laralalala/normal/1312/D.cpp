#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
#define mod (ll)(998244353)
#define MAXN 200005

ll fac[MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;
    cin >> n >> m;
    ll c1=1;
    for(ll i=n;i<=m;i++)
        c1=(c1*i)%mod;
    for(ll i=1;i<=m-n+1;i++)
        c1=(c1*qp(i,mod-2))%mod;

    fac[0]=1;
    for(ll i=1;i<=n-2;i++)
        fac[i]=(fac[i-1]*i)%mod;
    ll c2=0;
    for(ll i=1;i<=n-2;i++)
    {
        ll c21=(fac[n-2]*qp(fac[i],mod-2))%mod;
        c21=(c21*qp(fac[n-2-i],mod-2))%mod;
        c2=(c2+(c21*i))%mod;
    }
    ll res=(c1*c2)%mod;
    db(res)

    return 0;
}