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
#define dbg(x); {cout << #x << "=" << x << ", ";}
#define in(x); { for (auto &to : x) cin >> to;}
#define out(x); { for (auto &to : x) cout << to << " "; cout << '\n'; }

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;
ll f(ll x)
{
    return (1ll<<(x+1))-2;
}
ll find_near(ll x)
{
    ll l=0,r=60;
    ll ans=0;
    while (l<=r)
    {
        ll mid=((l+r)>>1);
        if (f(mid)<=x)
            l=mid+1,ans=mid;
        else
            r=mid-1;
    }
    return ans;
}
void solve()
{
    ll k;
    cin>>k;
    if (k&1)
    {
        cout<<-1<<'\n';
        return;
    }
    vector <int> ans;
//    ans.pb(1);
//    k-=2;
//    bool ok=true;
    while (k>0)
    {
        ll g=find_near(k);
//        if (ok)
//            ok=false;
//        else
            ans.pb(1);
        rep(i,g-1)
            ans.pb(0);
        k-=f(g);
    }
    cout<<ans.size()<<'\n';
    for (auto to:ans)
        cout<<to<<" ";
    cout<<'\n';
}

int main() {
    #ifdef Mip182
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #endif
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #endif
    int _t;
    _t=1;
    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}