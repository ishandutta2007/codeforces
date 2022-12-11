#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
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
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define MANX MAXN


const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
#define int long long
ll bin_pow(ll base,ll deg)
{
    if (deg==0)
        return 1;
    ll t=bin_pow(base,deg/2);
    if (deg&1)
        return t*t%mod1*base%mod1;
    else
        return t*t%mod1;
}
__int128 bin_powtrue(__int128 base,ll deg)
{
    if (deg==0)
        return 1;
    ll t=bin_powtrue(base,deg/2);
    if (deg&1)
        return t*t*base;
    else
        return t*t;
}
ll mult(ll a,ll b)
{
    return (a*b)%mod1;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int t;
    cin>>t;
    while (t--)
    {
        ll n,p;
        cin>>n>>p;
        vector <ll> k(n);
        rep(i,n)
            cin>>k[i];
        if (p==1)
        {
            if (n%2==1)
                cout<<1;
            else
                cout<<0;
            cout<<'\n';
            continue;
        }
        ll cntt=0;
        ll hh=1;
        while (hh*p<=1000000)
            cntt++,hh*=p;
        sort(all(k));
        ll ans=0;
        vector <pll> b;
        int i=0;
        while (i<n)
        {
            int j=i;
            int cnt=0;
            while (j<n&&k[i]==k[j])
                j++,cnt++;
            b.pb({k[i],cnt});
            i=j;
        }
        int cur=b.size();
        cur--;
        vector <ll> pref((int)b.size()+1);
        for (i=1;i<=b.size();i++)
            pref[i]=pref[i-1]+b[i-1].se;
        while (cur>=0)
        {
            if (b[cur].se%2==0)
            {
                cur--;
                continue;
            }
            b[cur].se=1;
            ll now=b[cur].fi;
            int was=cur-1;
            __int128 nado=1;
            bool ok=false;
            while (was>=0)
            {
                if (now-b[was].fi>cntt)
                {
                    ok=true;
                    break;
                }
                else
                    nado*=bin_powtrue(p,now-b[was].fi),now=b[was].fi;
                if (nado>=pref[was+1])
                {
                    ok=true;
                    break;
                }
                if (nado<=b[was].se)
                {
                    b[was].se-=nado;
                    nado=0;
                    break;
                }
                else
                {
                    nado-=b[was].se;
                    was--;
                }
            }
            if (ok||was==-1)
                break;
            cur=was;
        }
        if (cur==-1)
        {
            cout<<0<<'\n';
        }
        else
        {
            ans=mult(b[cur].se,bin_pow(p,b[cur].fi));
            //  cout<<ans<<'\n';
            for (i=cur-1;i>=0;i--)
            {
                ans-=mult(b[i].se,bin_pow(p,b[i].fi));
                ans+=mod1;
                ans%=mod1;
            }
            cout<<ans<<'\n';
        }


    }



    //n=1 ?
    //recursion - matrix exponential
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
}