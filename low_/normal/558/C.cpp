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
#define mn 100005
#define inf 1111111111
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, A[mn];
int passed[mn];

vector <pii> BFS(int u)
{
    // set <int> ss={};
    deque <pii> Q={{u, 0}};
    vector <pii> ret={{u, 0}};
    while (!Q.empty())
    {
        int v=Q.front().XX, d=Q.front().YY;
        Q.pop_front();
        if (v>mn) continue;
        if (passed[v]==u) continue;
        ret.push_back({v, d});
        passed[v]=u;
        if (v==0) continue;
        Q.push_back({v/2, d+1});
        Q.push_back({v*2, d+1});
    }

    return ret;
}

vector <pii> desti[mn];

int dist(int s, int f)
{
    int l=0, r=desti[s].size()-1;
    while (r>l)
    {
        int mid=(l+r)/2;
        if (desti[s][mid].XX<f) l=mid+1;
        else r=mid;
    }
    if (desti[s][l].XX==f) return desti[s][l].YY;
    else return inf;
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
    for (int i=1; i<=n; i++) cin>>A[i];
    sort(A+1, A+n+1);

    for (int i=1; i<=n; i++) 
    {
        if (A[i]==A[i-1]) desti[i]=desti[i-1];
        else
        {
            desti[i]=BFS(A[i]);
            sort(desti[i].begin(), desti[i].end());
        }
        
    }
    int ans=inf;

    for (pii p:desti[1])
    {
        int ret=p.YY;
        for (int i=2; i<=n; i++) 
        {
            ret+=dist(i, p.XX);
            if (ret>=inf) break;
        }
        ans=min(ans, ret);
    }

    cout<<ans;


}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/