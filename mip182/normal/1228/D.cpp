#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define fi first
#define se second
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
vvi g;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    g=vvi(n);
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector <int> used(n,0);
    used[0]=1;
    vector <int> c(n,0);
    c[0]=1;
    for (auto to:g[0])
    {
        c[to]=1;
    }
    for (int i=0;i<n;i++)
    {
        if (c[i]==0)
            used[i]=1;
    }
 //   cout<<"haha";
    int ind=0;
    while (ind<n&&used[ind]==1)
        ind++;
    if (ind==n)
    {
        cout<<-1;
        return 0;
    }
   // cout<<"ahha";
    used[ind]=2;
    vi p(n,0);
    p[ind]=1;
    for (auto to:g[ind])
    {   p[to]=1;
    }
    for (int i=0;i<n;i++)
    {
        if (p[i]==0)
        {
            if (used[i]!=0)
            {
                cout<<-1;
                return 0;
            }
            else
                used[i]=2;
        }
    }
    ind=0;
    while (ind<n&&used[ind]!=0)
        ind++;
    if (ind==n)
    {
        cout<<-1;
        return 0;
    }
    used[ind]=3;
    vi op(n,0);
    op[ind]=1;
    for (auto to:g[ind])
    {
        op[to]=1;
    }
    for (int i=0;i<n;i++)
    {
        if (op[i]==0)
        {
            if (used[i]!=0)
            {
                cout<<-1;
                return 0;
            }
            else
                used[i]=3;
        }
    }
    int u=0;
    while (u<n&&used[u]!=0)
        u++;
  // cout<<u;
    if (u!=n)
    {
        cout<<-1;
        return 0;
    }
    vector <int> cnt(3,0);
    for (int i=0;i<n;i++)
    {
        cnt[used[i]-1]++;
    }
    for (int i=0;i<n;i++)
    {
        int q=used[i];
        int chet=0;
        for (auto to:g[i])
        {
            if (used[to]==q)
            {
                cout<<-1;
                return 0;
            }
            else
                chet++;
        }
        if (chet!=cnt[0]+cnt[1]+cnt[2]-cnt[q-1])
        {
            cout<<-1;
            return 0;
        }
    }
    for (int i=0;i<n;i++)
        cout<<used[i]<<" ";
}