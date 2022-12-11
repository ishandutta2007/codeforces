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
const int MAXN = 400000+100;
const ll INF = 1e9;
const ll mod1=998244353;
const ll mod2=2e9+11;
ll fact[MAXN],ifact[MAXN];
ll mult(ll a,ll b)
{
    return (a*b)%mod1;
}
ll add(ll a,ll b)
{
    a+=b;
    if (a>=mod1)
        return a-mod1;
    return a;
}
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
ll C(ll n,ll k)
{
    if (k>n)
        return 0;
    ll a=fact[n];
    a=mult(a,ifact[k]);
    return mult(a,ifact[n-k]);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    ll f=1;
    for (ll i=0;i<MAXN;i++)
        fact[i]=f,f*=(i+1),f%=mod1,ifact[i]=bin_pow(fact[i],mod1-2);
    int n,k;
    cin>>n>>k;
    if (k==0)
    {
        cout<<fact[n];
        return 0;
    }
    ll ans=0;
    if (k>=n)
    {
        cout<<0;
        return 0;
    }
    ll x=n-k;
    ans=1;
    for (ll i=n;i>=n-x+1;i--)
        ans=mult(ans,i);
    ll sum=0;
    for (int i=0;i<=n;i++)
    {
        ll a=C(x,i);
        a=mult(a,bin_pow(i,n));
        if ((x-i)%2==1)
            a*=-1;
        a+=mod1;
        a%=mod1;
        sum=add(sum,a);
    }
    sum=mult(sum,ifact[x]);
    ans=mult(ans,sum);
    cout<<mult(2,ans);




}