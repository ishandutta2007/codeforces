#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, m;
vector <int> LL[mn];
vector <pii> E;
int ans[mn];

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    // for (int i=1; i<=n; i++) cnt[i]=3;
    int u, v;
    for (int i=1; i<=m; i++)
    {
        cin>>u>>v;
        LL[u].push_back(v);
        LL[v].push_back(u);
        E.push_back({u, v});
    }

    //make set 1
    for (int i=1; i<=n; i++) ans[i]=1;
    int w=0;
    for (int v:LL[1]) 
    {
        ans[v]=2;
        w=v;
    }
    // cerr<<"...\n";

    if (w==0)
    {
        cout<<-1;
        return 0;
    }
    // cerr<<"...\n";
    u=0;
    for (int v:LL[w]) if (ans[v]==2)
    {
        ans[v]=3;
        u=v;
    }
    // cerr<<"...\n";
    if (u==0)
    {
        cout<<-1;
        return 0;
    }
    // cerr<<"...\n";
    // for (int i=1; i<=n; i++) cerr<<ans[i]<<" ";
    for (pii p:E) if (ans[p.XX]==ans[p.YY])
    {
        cout<<-1;
        return 0;
    }
    // cerr<<"...\n";

    int cnt[4]={0, 0, 0, 0};
    for (int i=1; i<=n; i++) cnt[ans[i]]++;
    if (m != cnt[1]*cnt[2]+cnt[2]*cnt[3]+cnt[3]*cnt[1]) cout<<-1;
    else 
    {
        for (int i=1; i<=n; i++) cout<<ans[i]<<" ";
    }

    
    
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/