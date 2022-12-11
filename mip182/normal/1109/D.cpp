//#define _GLIBCXX_DEBUG
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
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 2e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
ll fact[MAXN],ifact[MAXN];
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
ll mult(ll a,ll b)
{
    return (a*b)%mod1;
}
ll add(ll a,ll b)
{
    return (a+b)%mod1;
}
ll C(ll n,ll k)
{
    if (k>n)
        return 0;
    ll ans=fact[n];
    ans=mult(ans,ifact[k]);
    return mult(ans,ifact[n-k]);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll f=1;
    for (ll i=0;i<MAXN;i++)
        fact[i]=f,f*=(i+1),f%=mod1,ifact[i]=bin_pow(fact[i],mod1-2);
    ll ans=0;
    for (int k=1;k<=n-1;k++)
    {
        ll sum=fact[n-2];
        sum=mult(sum,ifact[n-2-(k-1)]);
        sum=mult(sum,C(m-1,k-1));
        sum=mult(sum,bin_pow(m,n-k-1));
        if (n-k-2>=0)
        sum=mult(sum,mult(k+1,bin_pow(n,n-k-2)));
        else
            sum=mult(sum,mult(k+1,bin_pow(bin_pow(n,-(n-k-2)),mod1-2)));
        ans=add(ans,sum);
    }
    cout<<ans;


}