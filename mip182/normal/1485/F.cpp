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
int add(int a,int b)
{
    a+=b;
    if (a>=mod1)
        return a-mod1;
    return a;
}

int mult(int a,int b)
{
    return 1ll*a*b%mod1;
}

int sub(int a,int b)
{
    a-=b;
    if (a<0)
        return a+mod1;
    return a;
}

void ad(int &x,int y)
{
    x=add(x,y);
}

int bin_pow(int base,ll deg)
{
    if (deg==0)
        return 1;
    int t=bin_pow(base,deg/2);
    if (deg&1)
        return 1ll*t*t%mod1*base%mod1;
    else
        return 1ll*t*t%mod1;
}

void solve()
{
    int n;
    cin>>n;
    vector <ll> b(n);
    rep(i,n)
        cin>>b[i];
    map<ll,int> m;
    int ans=1;
    m[0]=1;
    vector <ll> pref(n+1);
    for (int i=1;i<=n;i++)
        pref[i]=pref[i-1]+b[i-1];
    int inv=bin_pow(2,mod1-2);
    int norm=1;
    int sum=1;
    for (int i=1;i<=n;i++)
    {
        int now=sum;
        now=sub(now,m[pref[i-1]]);
        m[pref[i-1]]=add(m[pref[i-1]],now);
        sum=add(sum,now);
    }
    cout<<mult(sum,norm)<<'\n';
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