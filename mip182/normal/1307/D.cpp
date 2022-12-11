#include <bits/stdc++.h>
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
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int n,m,k;
vector <int> g[MAXN];
vector <int> d;
vector <int> dd;
int good[MAXN];
//int a[MAXN];
void bfs(int s)
{
    d=vector <int> (n,INF);
    d[s]=0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int f=q.front();
        q.pop();
        for (auto to:g[f])
        {
            if (d[to]==INF)
            {
                d[to]=d[f]+1;
                q.push(to);
            }
        }
    }
}
void bfs1(int s)
{
    dd=vector <int> (n,INF);
    dd[s]=0;
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int f=q.front();
        q.pop();
        for (auto to:g[f])
        {
            if (dd[to]==INF)
            {
                dd[to]=dd[f]+1;
                q.push(to);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    cin>>n>>m>>k;
    for (int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        x--;
        good[x]=1;
    }
    for (int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs(n-1);
    bfs1(0);
    int mx=1;
    vector <pair<int,int> > a(n);
    for (int i=0;i<n;i++)
    {
        if (good[i]==1)
            a[i].fi=d[i];
        else
        a[i].fi=-INF;
        a[i].se=i;
    }
    sort(all(a));
    reverse(all(a));
    vector <int > prefmax(n+1,-INF),sufmax(n+2,-INF);
    for (int i=1;i<=n;i++)
        prefmax[i]=max(prefmax[i-1],a[i-1].fi);
    for (int i=n;i>=1;i--)
        sufmax[i]=max(sufmax[i+1],a[i-1].fi);
    for (int i=0;i<n;i++)
    {
        if (good[a[i].se]==1)
        {
            int xm=-INF;
            xm=sufmax[i+2];
           // cout<<xm<<" "<<dd[a[i].se]+1<<" "<<d[0]<<'\n';
            if (xm!=-INF)
            mx=max(mx,min(xm+dd[a[i].se]+1,d[0]));
        }
    }
    cout<<mx;






}