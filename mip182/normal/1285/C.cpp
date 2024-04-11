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
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

ll bin_pow(ll base,ll deg)
{
    if (deg==0)
        return 1;
    ll t=bin_pow(base,deg/2);
    if (deg&1)
        return (((t*t))*base);
    else
        return (t*t);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    ll x;
    cin>>x;
    ll wasx=x;
    deque <pair <ll,ll> > primes;
    for (ll i=2;i*i<=x;i++)
    {
        if (x%i==0)
        {
            primes.pb({i,0});
            while (x%i==0)
                x/=i,primes.back().se++;
        }
    }
    if (x!=1)
        primes.pb({x,1});
    int n=primes.size();
    ll mx=INFLL;
    pair <ll,ll> ans;
    for (int mask=0;mask<(1<<n);mask++)
    {
        ll sum=1;
        for (int i=0;i<n;i++)
        {
            if ((mask>>i)&1)
            {
                sum*=bin_pow(primes[i].fi,primes[i].se);
            }
        }
        ll b=wasx/sum;
        if (mx>max(b,sum))
        {
           mx= max(b,sum);
           ans={sum,b};
        }
    }
    if (ans.fi>ans.se)
        swap(ans.fi,ans.se);
    cout<<ans.fi<<" "<<ans.se;




}