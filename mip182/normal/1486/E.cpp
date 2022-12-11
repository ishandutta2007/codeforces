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
int cost(int a,int b)
{
    return (a+b)*(a+b);
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vvpii g(n);
    for (int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    vector <vector <ll> > d(n,vll(51,INFLL));
    d[0][0]=0;
    set<pair <int,pii> > s;
    s.insert({0,{0,0}});
    while (!s.empty())
    {
        auto to=s.begin();
        pii a=(*to).se;
        s.erase(to);
        for (auto [x,y]:g[a.fi])
        {
            if (a.se==0)
            {
                if (d[x][y]>d[a.fi][a.se])
                {
                    s.erase({d[x][y],{x,y}});
                    d[x][y]=d[a.fi][a.se];
                    s.insert({d[x][y],{x,y}});
                }
            }
            else
            {
                if (d[x][0]>d[a.fi][a.se]+cost(a.se,y))
                {
                    s.erase({d[x][0],{x,0}});
                    d[x][0]=d[a.fi][a.se]+cost(a.se,y);
                    s.insert({d[x][0],{x,0}});
                }
            }
        }
    }
    for (int i=0;i<n;i++)
        cout<<(d[i][0]==INFLL?-1:d[i][0])<<" ";
    cout<<'\n';
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