#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(3e6+5)

ll fac[MAXN];
ll ifac[MAXN];
ll ans[MAXN];
ll invs3;
ll fs[3];

ll qp(ll b,ll e)
{
    ll ans=1;
    while(e)
    {
        if(e&1)
            ans=(ans*b)%mod;
        b=(b*b)%mod;
        e>>=1;
    }
    return ans;
}

ll comb(ll n,ll m)
{
    ll den=(ifac[m]*ifac[n-m])%mod;
    return (fac[n]*den)%mod;
}

void solve(int k,int n)
{
    ll sum=comb(3*n+1,k+1);
//    cout << 3*n+1 << ' ' << k+1 << '\n';
//    db(sum)
    ll a2=fs[2];
    ll a1=fs[1];
    ll s3=(sum-a2-a1-a1+4*mod)%mod;
    fs[1]=(s3*invs3)%mod;
    fs[2]=(fs[1]+a1)%mod;
    fs[0]=(fs[2]+a2)%mod;
//    db("")
//    db(k)
//    for(int i=0;i<3;i++)
//        cout << v[i] << ' ' << ans[i] << '\n';
//    db("")
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fac[0]=1;
    for(int i=1;i<MAXN;i++)
        fac[i]=(fac[i-1]*i)%mod;
    ifac[MAXN-1]=qp(fac[MAXN-1],mod-2);
    for(int i=1;i<MAXN;i++)
        ifac[MAXN-i-1]=(ifac[MAXN-i]*(MAXN-i))%mod;
    invs3=qp(3,mod-2);

    int n,q;
    cin >> n >> q;
    ans[0]=n+1;
    fs[0]=n+1;
    fs[1]=n;
    fs[2]=n;
    for(int i=1;i<=3*n;i++)
    {
        solve(i,n);
        ans[i]=fs[0];
    }

    while(q--)
    {
        int x;
        cin >> x;
        db(ans[x])
    }

    return 0;
}