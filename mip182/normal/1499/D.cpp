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
const int MAXN = 2e7+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 1e9+21;
int p[MAXN];
void solve()
{
    int c,d,x;
    cin>>c>>d>>x;
    int g1=__gcd(c,d);
    if (x%g1)
    {
        cout<<0<<'\n';
        return;
    }
    c/=g1;
    d/=g1;
    x/=g1;
    ll ans=0;
//    cout<<"ahha\n";
    auto check =[&](int y)
    {
        int sum=(d+y);
        if (sum%c)
            return;
        sum/=c;
        ll aa=1;
        y=sum;
        while (y>1)
        {
            int u=p[y];
            aa*=2;
            while (y%u==0)
                y/=u;
        }
        ans+=aa;
    };
    for (int i=1;i*i<=x;i++)
    {
        if (x%i)
            continue;
        check(i);
        if (i*i!=x)
            check(x/i);
    }
    cout<<ans<<'\n';
}

int main() {
    p[1]=1;
    for (int i=2;i<MAXN;i++)
    {
        if (p[i])
            continue;
        p[i]=i;
        for (ll j=1ll*i*i;j<MAXN;j+=i)
        {
            if (p[j])
                p[j]=min(p[j],i);
            else
                p[j]=i;
        }
    }
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