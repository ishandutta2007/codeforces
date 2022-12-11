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
const int MAXN = 1e5+100;
const ll INF = 1e9;
const ll mod1=998244353;
const ll mod2=2e9+11;

ll bin_pow(ll base,ll deg)
{
    if (deg==0)
        return 1;
    ll t=bin_pow(base,deg/2);
    if (deg&1)
        return (((t*t)%mod1)*base%mod1)%mod1;
    else
        return (t*t)%mod1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    ll n,m,k;
    cin>>n>>m>>k;
    if (m==1)
    {
        if (k!=0)
            cout<<0;
        else
            cout<<1;
        return 0;
    }
    ll fact[MAXN];
    ll f=1;
    for (ll i=0;i<MAXN;i++)
    {
        fact[i]=f;
        f*=(i+1);
        f%=mod1;
    }
    //  k+1 
    ll ans=1;
    ans*=m;

    ans%=mod1;
    ans*=bin_pow(m-1,k);
    ans%=mod1;
    ans*=fact[n-1];
    ans%=mod1;
    ans*=bin_pow(fact[k],mod1-2);
    ans%=mod1;
    ans*=bin_pow(fact[n-1-k],mod1-2);
    ans%=mod1;
    cout<<ans;


}