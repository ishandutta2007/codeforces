//#define _GLIBCXX_DEBUG
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
#define int long long

const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=998244353;
const ll mod2=2e9+11;
int n,m;
ll b[35];
ll two[MAXN];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
        cin>>n>>m;
        ll f=1;
        for (int i=0;i<MAXN;i++)
            two[i]=f,f*=2,f%=mod1;
        int sz = 0;
        for (int i=0;i<n;i++) {
            ll x;
            cin >> x;
            for (ll j = 0; j < m; j++) {
                if (((x >> j) & 1ll)==0)
                    continue;
                if (b[j])
                    x ^= b[j];
                else {
                    sz++;
                    b[j] = x;
                    break;
                }
            }
        }
        vector <ll> ans(m+1);
        if (sz<=15)
        {
            vector <ll> basis;
            for (int i=0;i<m;i++)
            {
                if (b[i])
                    basis.pb(b[i]);
            }
            for (int mask=0;mask<(1<<sz);mask++)
            {
                ll x=0;
                for (int i=0;i<sz;i++)
                {
                    if ((mask>>i)&1)
                        x^=basis[i];
                }
                ans[__builtin_popcountll(x)]++;
            }
        }
        else
        {
            for (int i=0;i<m;i++)
            {
                if (b[i])
                {
                    for (int j=i+1;j<m;j++)
                    {
                        if (b[j]&&(b[i]>>j)&1)
                        {
                            b[i]^=b[j];
                        }
                    }
                }
            }
            vector <ll> basis;
            for (int i=0;i<m;i++)
            {
                if (b[i])
                {
                    ll x=0;
                    ll cur=0;
                    for (ll j=0;j<m;j++)
                    {
                        if (b[j])
                            continue;
                        if ((b[i]>>j)&1ll)
                            x|=(1ll<<cur);
                        cur++;
                    }
                    basis.pb(x);
                }
            }
            vector <vector <ll> > dp(sz+1,vector <ll> (1ll<<(m-sz)));
            dp[0][0]=1;
            for (int i=0;i<sz;i++)
            {
                for (int j=i;j>=0;j--)
                {
                    for (int mask=0;mask<(1ll<<(m-sz));mask++)
                    {
                        dp[j+1][(mask^basis[i])]+=dp[j][mask];
                        dp[j+1][(mask^basis[i])]%=mod1;
                    }
                }
            }
            for (int i=0;i<=sz;i++)
            {
                for (int mask=0;mask<(1ll<<(m-sz));mask++)
                {
                    ans[i+__builtin_popcount(mask)]+=dp[i][mask];
                    ans[i+__builtin_popcount(mask)]%=mod1;
                }
            }
        }
        //  cout<<sz<<'\n';
        for (int i=0;i<=m;i++)
            ans[i]=(ans[i]*two[n-sz])%mod1;
        for (auto to:ans)
            cout<<to<<" ";



    //n=1 ?
    //recursion - matrix exponential
    //check ios_base, MAXN, mod1 before submit
    //if debug more than 15 minutes - write stress
}