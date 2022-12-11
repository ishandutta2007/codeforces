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
const int mod1 = 998'244'353;
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
vvi g;
vector <int> path;
vb used;
void dfs(int s)
{
    used[s]=true;
    for (auto to:g[s])
    {
        if (used[to])
            continue;
        dfs(to);
    }
    path.pb(s);
}
vi dp;
int mex(vi &a)
{
    a.pb(1e9);
    sort(all(a));
    a.resize(unique(all(a))-a.begin());
    for (int i=0;i<a.size();i++)
    {
        if (a[i]!=i)
            return i;
    }
}
void gauss_jordan(vector<vector<int> > &gg, int n) {
    for (int col=0,row=0;col<n&&row<gg.size();col++) {
        int x = row;
        while (x < n && gg[x][col] == 0)
            x++;
        if (x==n)
            continue;
        swap(gg[row], gg[x]);
        int val = bin_pow(gg[row][col], mod1 - 2);
        for (int j = col; j < n + 1; j++)
            gg[row][j] = mult(gg[row][j], val);
        for (int j = 0; j < n; j++) {
            if (j == row || gg[j][col] == 0)
                continue;
            val = gg[j][col];
            for (int f = col; f < n + 1; f++)
                gg[j][f] = sub(gg[j][f], mult(val, gg[row][f]));
        }
        row++;
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    g=vvi(n);
    while (m--){
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
    }
    used=vb(n);
    for (int i=0;i<n;i++)
    {
        if (!used[i])
            dfs(i);
    }
    dp=vi(n);
    for (auto to:path)
    {
        vi a;
        for (auto too:g[to])
            a.pb(dp[too]);
        dp[to]=mex(a);
    }
//    for (auto to:dp)
//        cout<<to<<" ";
//    cout<<'\n';
    int mx=*max_element(all(dp));
    int v=1;
    while (v<=mx)
        v<<=1;
    vector <vector <int> > ans(v,vi(v+1));
    int x=bin_pow(n+1,mod1-2);
    // e[now] = p[i] * e[i] ... + (now==0?0:1)*x;
    for (int i=0;i<v;i++)
    {
        ans[i][v]=mult(x,mult(mod1-1,(i==0?0:1)));
        ans[i][i]=mod1-1;
        for (int j=0;j<n;j++)
        {
            ad(ans[i][(i^dp[j])],x);
        }
    }
//    for (int i=0;i<v;i++)
//    {
//        for (int j=0;j<v+1;j++)
//            cout<<ans[i][j]<<" ";
//        cout<<'\n';
//    }
    gauss_jordan(ans,v);
//    for (int i=0;i<v;i++)
//    {
//        for (int j=0;j<v+1;j++)
//            cout<<ans[i][j]<<" ";
//        cout<<'\n';
//    }
    cout<<ans[0][v]<<'\n';
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
//    cin>>_t;
    while (_t--)
        solve();
    #ifdef Mip182
    cout<<'\n'<<"Time : "<<(double)(clock())/CLOCKS_PER_SEC<<'\n';
    #endif
}