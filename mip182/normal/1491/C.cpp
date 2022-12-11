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
    int n;
    cin>>n;
    vi s(n);
    in(s);
    ll ans=0;
    vector <ll> now(n);
    for (int i=0;i<n;i++)
    {
        if (i==n-1)
        {
            s[i]=max(s[i]-now[i],1ll);
            ans+=s[i]-1;
            continue;
        }
        if (s[i]+i>=n)
        {
            ll total=s[i]-(n-i)+1;
            ll x=min(total,now[i]);
            total-=x;
            now[i]-=x;
            ans+=total;
            s[i]=n-i-1;
        }
        while (s[i]!=1)
        {
            now[s[i]+i]++;
            if (now[i]>0)
                now[i]--;
            else
                ans++;
            s[i]--;
        }
        now[i+1]+=now[i];
    }
    cout<<ans<<'\n';
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