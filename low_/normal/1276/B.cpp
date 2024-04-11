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

int t, n, m, a, b;
vector <int> LL[mn];
bool passed[mn];

void reset()
{
    for (int i=0; i<=n; i++) LL[i].clear();
}

int BFS(int u, int av)
{
    deque <int> Q={u};
    passed[u]=1;
    int ret=1, a=1;
    while (!Q.empty())
    {
        int w=Q.front();
        Q.pop_front();
        if (w==av) a=0;
        for (int v: LL[w]) if (!passed[v]) 
        {
            passed[v]=1;
            Q.push_back(v);
            ret++;
        }
    }
    return ret*a;
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

    int ntest;
    cin>>ntest;
    while (ntest--)
    {
        reset();
        cin>>n>>m>>a>>b;
        int u, v;
        while(m--)
        {
            cin>>u>>v;
            LL[u].push_back(v);
            LL[v].push_back(u);
        }

        int ansA=0, ansB=0;
        for (int i=1; i<=n; i++) passed[i]=0;
        passed[a]=1;
        for (int i=1; i<=n; i++) if (!passed[i]) ansA+=BFS(i, b);
        for (int i=1; i<=n; i++) passed[i]=0;
        passed[b]=1;
        for (int i=1; i<=n; i++) if (!passed[i]) ansB+=BFS(i, a);
        // cerr<<ansA<<" "<<ansB<<"\n";
        cout<<ansA*ansB<<"\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/