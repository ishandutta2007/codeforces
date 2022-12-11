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
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=998244353;
const ll mod2=2e9+11;

ll bin_pow(ll x,ll y)
{
    if (x==0)
        return 1;
    if (x==1)
        return y;
    ll t=bin_pow(x/2,y);
    if (x%2==1)
        return (((t*t)%mod1)*y)%mod1;
    else
        return (t*t)%mod1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    ll n;
    cin>>n;
    ll f=n*n;
    f%=mod1;
    ll q=bin_pow(mod1-2,f);
    vector <vector <int> > a(n);
    vector <ll> k(n);
    map <ll,ll> m;
    ll sum=0;
    rep(i,n)
    {
        cin>>k[i];
        a[i].resize(k[i]);
        rep(j,k[i]) {
            cin >> a[i][j];
            m[a[i][j]]++;
        }
    }
    ll ans=0;
    for (int i=0;i<n;i++)
    {
        ll y=bin_pow(mod1-2,k[i]);
        ll summ=0;
        for (int j=0;j<k[i];j++)
        {
            summ+=m[a[i][j]];
        }
   //     cout<<summ<<" "<<k[i]<<'\n';
        summ*=y;
        summ%=mod1;
        sum+=summ;
        sum%=mod1;
    }
    sum*=q;
    sum%=mod1;
    cout<<sum;



}