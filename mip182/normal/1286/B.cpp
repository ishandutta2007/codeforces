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
vector <int> g[2000];
int c[2000];
ll cur=20000;
ll mcur=-1;
vector <int> s[2000];
bool ok=true;
void dfs(int v)
{
    if (ok==false)
        return;
    for (auto to:g[v])
    {
        dfs(to);
    }
    if (g[v].size()==0)
    {
        s[v].pb(v);
        if (c[v]!=0)
        {
            ok=false;
            return;
        }
    } else
    {
        for (auto to:g[v])
        {
            for (auto too:s[to])
                s[v].pb(too);
        }
        if (c[v]>(int)s[v].size())
        {
            ok=false;
            return;
        }
        vector <int> neww;
        for (int i=0;i<c[v];i++)
            neww.pb(s[v][i]);
        neww.pb(v);
        for (int i=c[v];i<s[v].size();i++)
            neww.pb(s[v][i]);
        s[v]=neww;
        }

    }
int main() {
   // ios_base::sync_with_stdio(0);
   // cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int n;
    cin>>n;
    int root=0;
    for (int i=0;i<n;i++)
    {
        int p;
        cin>>p>>c[i];
        p--;
        if (p==-1)
            root=i;
        else
        g[p].pb(i);
    }
    dfs(root);
    if (ok)
    {
        cout<<"YES\n";
        vector <int> a(n);
        int l=1;
        for (int i=0;i<s[root].size();i++)
        {
            a[s[root][i]]=l;
            l++;
        }
        for (int i=0;i<n;i++)
            cout<<a[i]<<" ";
    } else
    {
        cout<<"NO";
    }
}