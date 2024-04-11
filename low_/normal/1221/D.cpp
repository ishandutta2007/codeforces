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
#define mn 300005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int q, n;
int A[mn], B[mn];

const int maxRise=4;
int fret[mn][maxRise];


int f(int u, int r)
{
    if (fret[u][r]!=-1) return fret[u][r];
    if (u==1) return B[u]*r;
    
    int ret=inf;
    for (int i=0; i<maxRise; i++) if (A[u-1]+i!=A[u]+r) ret=min(ret, f(u-1, i)+B[u]*r);
    return fret[u][r]=ret;
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

    for (int i=0; i<mn; i++) for (int j=0; j<maxRise; j++) fret[i][j]=-1;

    cin>>q;
    while (q--)
    {
        cin>>n;
        for (int i=1; i<=n; i++) cin>>A[i]>>B[i];

        int ans=inf;
        for (int i=0; i<maxRise; i++) ans=min(ans, f(n, i));
        cout<<ans<<"\n";
        for (int i=0; i<=n; i++) for (int j=0; j<maxRise; j++) fret[i][j]=-1;   
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/