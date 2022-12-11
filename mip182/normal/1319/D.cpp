#include <bits/stdc++.h>
//#pragma GCC optmize("O3,Ofast,unroll-loops,fast-math,no-stack-protector")
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i=0;i<(n);i++)
#define pii pair <int,int>
#define pll pair <ll,ll>
#define vi vector <int>
#define vvi vector <vector <int> >
#define vll vector <ll>
#define fi first
#define se second
#define mii map <int,int>
#define mll map <ll,ll>
#define si set <int>
#define sll set <ll>
#define pb push_back

const int MAXN=1e6+100;
const ll INF=1e9;
const ll INFLL=1e18;
const ll mod1=1e9+7;
int n,m,k;
vector <int> p;
vvi g,gg;
vector <int> d;
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
        for (auto to:gg[f])
        {
            if (d[to]==INF)
            {
                d[to]=d[f]+1;
                q.push(to);
            }
        }
    }
}
signed  main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
#endif
    cin>>n>>m;
    g=vvi(n);
    gg=vvi(n);
    rep(i,m)
    {
        int u,v;
        cin>>u>>v;
        u--,v--;
        g[u].pb(v);
        gg[v].pb(u);
    }
    cin>>k;
    p=vector <int> (k);
    rep(i,k)
    {
        cin>>p[i];
        p[i]--;
    }
    bfs(p[k-1]);
    int minix=0,maxik=0;
    vector <int> pref(n+1,INF);
    for (int j=0;j<n;j++)
        pref[j+1]=min(pref[j],d[j]);
    vector <int> suf(n+2,INF);
    for (int j=n-1;j>=0;j--)
    {
        suf[j+1]=min(suf[j+2],d[j]);
    }
    multiset <int> s[n];
    for (int i=0;i<n;i++)
    {
        for (auto to:g[i])
        {
            s[i].insert(d[to]);
        }
    }
//    rep(i,n)
//    cout<<d[i]<<" ";
//    cout<<'\n';
    for (int j=0;j<k-1;j++)
    {
       // cout<<p[j]<<" "<<p[j+1]<<" "<<d[p[j]]<<" "<<d[p[j+1]]<<'\n';
        if (d[p[j+1]]+1!=d[p[j]])
            minix++;
        int mx=d[p[j+1]];
        s[p[j]].erase(s[p[j]].find(mx));
        if (s[p[j]].size()>0){
        if (mx>=*s[p[j]].begin())
            maxik++; }


    }
    cout<<minix<<" "<<maxik;



}