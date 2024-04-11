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
vector <int> adding;
vector <vector <int> > f;
void add(int w,int pos,int x)
{
    for (;pos<f[w].size();pos|=pos+1)
        f[w][pos]=min(f[w][pos],x);
}
int res(int w,int l)
{
    int ans=INF;
    for (;l>=0;l=((l+1)&l)-1)
        ans=min(ans,f[w][l]);
    return ans;
}
void solve()
{
    int n;
    cin>>n;
    adding=vi(n);
    f=vvi(n,vi(n,INF));
    vector <int> a(n);
    rep(i,n)
        cin>>a[i];
//    vector <vector <int> > dp(n,vi(n,INF));
//    dp[n-1][n-1]=0;
//    for (int last=n-1;last>0;last--)
//    {
//        for (int prev=last;prev<n;prev++) {
//            if (dp[last][prev]==INF)
//                continue;
//            vector<int> pos;
//            for (int j = 0; j < last; j++) {
//                if (j + a[j] >= last)
//                    pos.pb(j);
//            }
//            int cnt = 0;
//            reverse(all(pos));
//            for (auto to:pos) {
//                if (last==n-1||to+a[to]<prev)
//                    dp[to][last] = min(dp[to][last], cnt + dp[last][prev]);
//                cnt++;
//            }
//        }
//    }
    add(n-1,0,0);
    for (int i=n-2;i>=0;i--)
    {
        for (int nex=i+1;nex<n;nex++)
        {
            if (i+a[i]<nex)
                break;
//            cout<<i<<" "<<nex<<" "<<(nex!=n-1?n-1-(min(n-1,i+a[i]+1)):0)<<'\n';

            int val=res(nex,(nex!=n-1?n-1-(min(n,i+a[i]+1)):n-1));
            val+=adding[nex];
            add(i,n-1-nex,val);
//            cout<<val<<'\n';
        }
        for (int j=i+1;j<n;j++)
        {
            if (a[i]+i>=j)
                adding[j]++;
        }
    }
    cout<<res(0,n-1)<<'\n';
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