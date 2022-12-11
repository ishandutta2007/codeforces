#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 2e5+100;
const ll INF = 1e9;
const ll mod1=998244353;
const ll mod2=2e9+11;
ll bin_pow(ll base,ll deg)
{
    if (deg==0)
        return 1;
    ll t=bin_pow(base,deg/2);
    if (deg&1)
        return (((t*t)%mod1)*base)%mod1;
    else
        return (t*t)%mod1;
}
ll fact[MAXN];
ll C(ll n,ll k)
{
    if (k>n)
        return 0;
    ll f=fact[n];
    f*=bin_pow(fact[k],mod1-2);
    f%=mod1;
    f*=bin_pow(fact[n-k],mod1-2);
    f%=mod1;
    return f;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    ll n,m;
    cin>>n>>m;
    if (n==2)
    {
        cout<<0;
        return 0;
    }
    ll f=1;
    for (ll i=0;i<MAXN;i++)
        fact[i]=f,f*=(i+1),f%=mod1;
    ll ans=0;
    ll anss=0;
    cout<<(((C(m,n-1)*bin_pow(2,n-3))%mod1)*(n-2))%mod1<<'\n';
 /*   for (int mask=0;mask<bin_pow(m,n);mask++)
    {
        vector <int> a;
        int x=mask;
        set <int> s;
        for (int i=0;i<n;i++)
            a.pb(x%m+1),s.insert(x%m+1),x/=m;
        if (s.size()!=n-1)
            continue;
        int i=0;
        while (i<n-1&&a[i]<a[i+1])
            i++;
        while (i<n-1&&a[i]>a[i+1])
            i++;
        if (i==n-1)
            ans++;
    }
    cout<<ans<<'\n'; */


}