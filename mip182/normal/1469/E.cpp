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

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string ans;
    int now=0;
    while (k-now>=20)
        ans+='0',now++;
    set <int> not_done;
    vector <int> pref(n+1);
    for (int i=1;i<=n;i++)
        pref[i]=pref[i-1]+(s[i-1]=='0');
    vector <int> to_check;
    for (int i=1;i<=n-k+1;i++)
    {
        if (pref[i+now-1]-pref[i-1]==0)
            to_check.pb(i);
    }
    int sz=k-now;
    vector <bool> good((1<<sz),true);
    for (auto to:to_check)
    {
        int mask=0;
        for (int f=0;f<sz;f++)
        {
            if (s[f+to+now-1]=='0')
                mask|=(1<<(sz-1-f));
        }
        good[mask]=false;
    }
    for (int i=0;i<(1<<sz);i++)
    {
        if (!good[i])
            continue;
        for (int f=sz-1;f>=0;f--)
        {
            if((i>>f)&1)
                ans+='1';
            else
                ans+='0';
        }
        cout<<"YES\n";
        cout<<ans<<'\n';
        return;
    }
    cout<<"NO\n";
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