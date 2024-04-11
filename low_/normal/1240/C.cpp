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
#define mn 500005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, q, k;
int u, v, w;
vector <pii> LL[mn];

int par[mn];
pii Fret[mn]; //take k-1 child _ take k child

bool byDiff(pii A, pii B)
{
    return ((B.YY-B.XX)>(A.YY-A.XX));
}

pii dp(int u)
{
    // cerr<<u<<" "<<par[u]<<"\n";
    if (Fret[u].XX!=-1) return Fret[u];
    for (pii p: LL[u])
    {
        if (par[p.XX]==-1)
        {
            par[p.XX]=u;
            dp(p.XX);
        }
    }

    pii ret={0, 0};
    vector <pii> temp={};
    for (pii p:LL[u]) if (par[p.XX]==u)
    {
        pii tt=dp(p.XX);
        temp.push_back({tt.XX+p.YY, tt.YY});
    }
    sort(temp.begin(), temp.end(), byDiff);

    for (int i=0; i<temp.size(); i++)
    {
        if (i<k-1)
        {
            ret.XX+=max(temp[i].XX, temp[i].YY);
            ret.YY+=max(temp[i].XX, temp[i].YY);
        }
        else if (i==k-1) 
        {
            ret.XX+=temp[i].YY;
            ret.YY+=max(temp[i].XX, temp[i].YY);
        }
        else 
        {
            ret.XX+=temp[i].YY;
            ret.YY+=temp[i].YY;
        }
    }

    return Fret[u]=ret;
}

void newTest()
{
    for (int i=1; i<=n; i++) LL[i].clear();
    for (int i=1; i<=n; i++)
    {
        par[i]=-1;
        Fret[i]={-1, -1};
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

    cin>>q;
    while (q--)
    {
        cin>>n>>k;
        newTest();
        for (int i=1; i<n; i++)
        {
            cin>>u>>v>>w;
            LL[u].push_back({v, w});
            LL[v].push_back({u, w});
        }

        
        // cerr<<"...\n";
        par[1]=0;
        cout<<dp(1).YY<<"\n";



    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/