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
#define mn 200005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n;
vector <int> dsk[mn];
int par[mn];
int dp1[mn]; // count child;
int dp2[mn]; // sum of dp1 of all descendants
int dppar[mn]; // support dp3
int dp3[mn]; //ans;

void dfs(int u)
{
    for (int v:dsk[u]) if (v!=par[u])
    {
        par[v]=u;
        dfs(v);
    }
}

int f1(int u)
{
    if (dp1[u]!=-inf) return dp1[u];
    int ret=1;
    for (int v:dsk[u]) if (v!=par[u]) ret+=f1(v);
    return dp1[u]=ret;
}

int f2(int u)
{
    if (dp2[u]!=-inf) return dp2[u];
    int ret=f1(u);
    for (int v:dsk[u]) if (v!=par[u]) ret+=f2(v);
    return dp2[u]=ret;
}

int f3(int u);

int fpar(int u)
{
    if (dppar[u]!=-inf) return dppar[u];
    if (u==1) return 0;
    int ret=f3(par[u])-f2(u)-f1(u);
    return dppar[u]=ret;
}

int f3(int u)
{
    if (dp3[u]!=-inf) return dp3[u];
    int ret=fpar(u)+f2(u)-f1(u)+n;
    return dp3[u]=ret;
}

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++) dp1[i]=dp2[i]=dp3[i]=dppar[i]=-inf;
    int u, v;
    for (int i=1; i<n; i++)
    {
        cin>>u>>v;
        dsk[u].push_back(v);
        dsk[v].push_back(u);
    }

    dfs(1);
    deque <int> Q={1};
    int ans=-inf;
    while (!Q.empty())
    {
        u=Q.front();
        Q.pop_front();
        ans=max(ans, f3(u));
        for(int v:dsk[u]) if (v!=par[u]) 
        {
            Q.push_back(v);
        }
    }

    // for (int i=1; i<=n; i++)
    // {
    //     cerr<<f1(i)<<" "<<f2(i)<<" "<<fpar(i)<<" "<<f3(i)<<endl;
    // }
    cout<<ans;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/