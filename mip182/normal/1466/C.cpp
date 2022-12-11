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
    string s;
    cin>>s;
    int n=s.size();
    vector <vector <int> > dp(27,vi(27,INF));
    vector <vector <int> > pref(27,vi(27,INF));
    vector <vector <int> > suf(27,vi(28,INF));
    dp[0][0]=0;
    for (int i=0;i<27;i++)
        pref[i]=vi(27,0);
    for (int i=0;i<27;i++)
        suf[i]=vi(28,0);
    for (int i=1;i<=n;i++)
    {
        vector <vector <int>> dpp(27,vi(27,INF));
        vector <vector <int>> preff(27,vi(27,INF));
        vector <vector <int>>suff(27,vi(28,INF));
        for (int prev1=0;prev1<=26;prev1++)
        {
            //dp[i][j][prev1] =min(dp[i-1][prev1][prev2],prev2!=j);
            for (int j=1;j<=26;j++) {
                if (j==prev1)
                    continue;
                int x=(s[i-1]!='a'+j-1);
                dpp[j][prev1] = min({dpp[j][prev1], pref[prev1][j - 1]+x, suf[prev1][j + 1]+x});
            }
        }
        for (int j=0;j<=26;j++)
        {
            preff[j][0]=dpp[j][0];
            for (int f=1;f<=26;f++)
                preff[j][f]=min(preff[j][f-1],dpp[j][f]);
            for (int f=26;f>=0;f--)
                suff[j][f]=min(suff[j][f+1],dpp[j][f]);
        }
        swap(dp,dpp);
        swap(preff,pref);
        swap(suf,suff);
    }
    int ans=INF;
    for (int i=0;i<=26;i++)
    {
        for (int j=0;j<=26;j++)
            ans=min(ans,dp[i][j]);
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