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

int n, k;
vector <int> dsk[mn*3];
int passed[mn*3];

void DFS(int u)
{
    passed[u]=1;
    for (int v:dsk[u]) if (passed[v]==0) DFS(v);
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

    cin>>n>>k;
    int x, y;
    for (int i=1; i<=k; i++)
    {
        cin>>x>>y;
        dsk[x+k].push_back(i);
        dsk[y+k].push_back(i);
        dsk[i].push_back(x+k);
        dsk[i].push_back(y+k);
    }

    int ans=n;
    for (int i=k+1; i<=k+n; i++) if (passed[i]==0)
    {
        ans--;
        DFS(i);
    }
    ans=min(k, ans);
    cout<<k-ans;

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/