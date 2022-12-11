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
const int MAXN = 6000000+100;
const ll INF = 1e9;
const int mod1 = 1e9+7;
const int mod2 = 2e9+11;
const int k = 30;
int cur=1;
int go[MAXN][2];
int cnt[MAXN];
int dfs(int s) {
    if (cnt[s]==1)
        return 0;
    if (go[s][0]==0)
    {
        return dfs(go[s][1]);
    }
    if (go[s][1]==0)
        return dfs(go[s][0]);
    int cnt0=cnt[go[s][0]],cnt1=cnt[go[s][1]];
    return min(cnt1-1+dfs(go[s][0]),cnt0-1+dfs(go[s][1]));
}
void solve()
{
    int n;
    cin>>n;
    rep(iii,n)
    {
        int x;
        cin>>x;
        int now=0;
        cnt[now]++;
        for (int i=k-1;i>=0;i--)
        {
            if ((x>>i)&1)
            {
                if (go[now][1]==0)
                    go[now][1]=cur++;
                now=go[now][1];
            }
            else
            {
                if (go[now][0]==0)
                    go[now][0]=cur++;
                now=go[now][0];
            }
            cnt[now]++;
        }
    }
    cout<<dfs(0)<<'\n';
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