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

int t;
int n;
vector <pii> dsk[mn];

int par[mn];
int W[mn];
int cntDec[mn];

void refresh()
{
    for (int i=1; i<=n; i++) par[i]=0, W[i]=0, dsk[i].clear();
}

void DFS(int u, int w)
{
    W[u]=w;
    cntDec[u]=1;
    for (pii v:dsk[u]) if (v.XX!=par[u])
    {
        par[v.XX]=u;
        DFS(v.XX, v.YY);
        cntDec[u]+=cntDec[v.XX];
    }
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

    cin>>t;
    int u, v, c;
    while (t--)
    {
        cin>>n;
        n*=2;
        refresh();
        int G=0;
        for (int i=1; i<n; i++)
        {
            cin>>u>>v>>c;
            dsk[u].push_back({v, c});
            dsk[v].push_back({u, c});
            G+=c;
        }

        DFS(1, 0);
        for (int i=1; i<=n; i++) if (cntDec[i]%2==0) G-=W[i];

        // int pivot=0;
        int B=0;
        for (int i=1; i<=n; i++) B+=min(cntDec[i], n-cntDec[i])*W[i];


        cout<<G<<' '<<B<<"\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/