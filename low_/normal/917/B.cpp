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
#define mn 105
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, m;
vector <pii> dsk[mn];

int F[105][105][26][2];

int dp(int u, int v, int c, int turn)
{
    if (F[u][v][c][turn]!=-1) return F[u][v][c][turn];
    // cerr<<u<<" "<<v<<" "<<c<<" "<<turn<<endl;

    if (turn==0)
    {
        for (int i=0; i<dsk[u].size(); i++)
        {
            int w=dsk[u][i].XX; int c1=dsk[u][i].YY;
            // cerr<<u<<" "<<w<<" "<<c1<<endl;
            if (c1<c) continue;
            if (dp(w, v, c1, turn^1)==0) return F[u][v][c][turn]=1;
        }
    }
    else
    {
        for (int i=0; i<dsk[v].size(); i++)
        {
            int w=dsk[v][i].XX; int c1=dsk[v][i].YY;
            // cerr<<v<<" "<<w<<" "<<c1<<endl;
            if (c1<c) continue;
            if (dp(u, w, c1, turn^1)==0) return F[u][v][c][turn]=1;
        }
    }
    return F[u][v][c][turn]=0;
    
}

char ans[105][105];

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=0; i<105; i++) for (int j=0; j<105; j++)
        for (int ii=0; ii<26; ii++) for (int jj=0; jj<2; jj++) F[i][j][ii][jj]=-1;

    cin>>n>>m;
    int u, v; char c;
    for (int i=1; i<=m; i++)
    {
        cin>>u>>v>>c;
        // cerr<<u<<" "<<v<<" "<<(int)c-'a'<<endl;
        dsk[u].push_back({v, c-'a'});
    }
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++)
    {
        ans[i][j]='B'-dp(i, j, 0, 0);
    }
    for (int i=1; i<=n; i++) 
    {
        for (int j=1; j<=n; j++) cout<<ans[i][j];
        cout<<"\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/