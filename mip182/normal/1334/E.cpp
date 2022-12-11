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
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=998244353 ;
const ll mod2=2e9+11;
ll fact[100],ifact[100];
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
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    ll f=1;
    for (ll i=0;i<100;i++)
        fact[i]=f,f*=(i+1),f%=mod1,ifact[i]=bin_pow(fact[i],mod1-2);
    ll d;
    cin>>d;
    deque<pll> de;
    for (ll i=2;i*i<=d;i++)
    {
        if (d%i==0)
        {
            de.pb({i,0});
            while (d%i==0)
                d/=i,de.back().se++;
        }
    }
    if (d!=1)
        de.pb({d,1});
    int q;
    cin>>q;
    int m=de.size();
    while (q--)
    {
        ll u,v;
        cin>>u>>v;
        vector <ll> uu(m),vv(m);
        for (int i=0;i<m;i++)
        {
            while (u%de[i].fi==0)
                u/=de[i].fi,uu[i]++;
            while (v%de[i].fi==0)
                v/=de[i].fi,vv[i]++;
        }
        vector <ll> del,umn;
        for (int i=0;i<m;i++) {
            if (uu[i] - vv[i]<0)
                del.pb(vv[i]-uu[i]);
            else
            {
                if (uu[i]!=vv[i])
                    umn.pb(uu[i]-vv[i]);
            }
        }
        ll ans=1;
     //   cout<<umn.size()<<'\n';
        map <int,int> mm;
        ll sum=0;
        for (int i=0;i<del.size();i++)
            sum+=del[i];
        //   cout<<sum<<'\n';
        ans*=fact[sum];
        ans%=mod1;
        for (auto to:del)
            ans*=ifact[to],ans%=mod1;
        mm.clear();
        sum=0;
        for (int i=0;i<umn.size();i++)
            sum+=umn[i];
     //   cout<<sum<<'\n';
        ans*=fact[sum];
        ans%=mod1;
        for (auto to:umn)
            ans*=ifact[to],ans%=mod1;
        cout<<ans<<'\n';
    }



}