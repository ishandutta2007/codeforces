#include <bits/stdc++.h>
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
#define vpii vector <pair <int, int> >
#define vpll vector <pair <long long, long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define vb vector <bool>
#define vvb vector <vb>
#define mp make_pair
#define vvll vector <vll>
#define vsi vector <si>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define MANX MAXN
#define itn int
#define dbg(x); {cout<<#x<<"="<<x<<", ";}
#define in(x); { for (auto &to : x) cin>>to;}
#define out(x); { for (auto &to : x) cout<<to<<" ";cout<<'\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 2e9+11;

void solve()
{
    vector <int> a(6);
    rep(i,6)
    cin>>a[i];
    int n;
    cin>>n;
    vector <int> b(n);
    vector <int> used(n);
    int cnt=0;
    rep(i,n)
    cin>>b[i];
    vector <pii> c(6*n);
    rep(i,n)
    {
        rep(j,6)
            c[6*i+j]={b[i]-a[j],i};
    }
    sort(all(c));
    ll ans=INFLL;
    int i=0,j=0;
    while (i<c.size())
    {
        while (cnt!=n&&j<c.size())
        {
            used[c[j].se]++;
            if (used[c[j].se]==1)
                cnt++;
            j++;
        }
        if (cnt==n)
        {
            ans=min(ans,1ll*(c[j-1].fi-c[i].fi));
        }
        used[c[i].se]--;
        if (used[c[i].se]==0)
            cnt--;
        i++;
    }
    cout<<ans<<'\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
//    cin>>_t;
    while (_t--)
        solve();
    //n=1 ?
    //recursion - matrix exponential
    //linear algebra - just a joke
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
    //compression
}