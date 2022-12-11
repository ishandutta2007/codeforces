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
ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}
void solve()
{
    int n,k;
    cin>>n>>k;
    if ((n-(k-1))*2<=n)
    {
        for (int i=0;i<k-1;i++)
            cout<<1<<" ";
        cout<<n-(k-1)<<'\n';
        return;
    }
    // a*(k-1)=n-b
    int now=n%(k-1);
    while (now<n)
    {
        if (now==0){
            now+=k-1;
            continue;
        }
        ll a=(n-now)/(k-1);
        if (lcm(a,now)*2<=n)
        {
            for (int i=0;i<k-1;i++)
                cout<<a<<" ";
            cout<<now<<'\n';
            return;
        }
        now+=k-1;
    }
    assert(false);
}

int main() {
    #ifdef Mip182
    freopen("a.in", "r", stdin);
    #else
    ios_base::sync_with_stdio(0);
    cin.tie(0);
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