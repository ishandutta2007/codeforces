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
#define mn 1005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

char A[mn][mn];
int n, m;

int dpH[mn][mn], dpV[mn][mn];

int r[mn][mn][12];
int RMQ(int u, int v, int k)
{
    int t=0, ret=inf;
    // cerr<<u<<" "<<v<<" "<<k<<"\n";
    while (k>0)
    {
        if (k%2==1)
        {
            ret=min(ret, r[u][v][t]);
            u-=(1<<t);
        }
        k/=2;
        t++;
    }
    return ret;
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

    // for (int i=0; i<mn; i++) for (int j=0; j<mn; j++) for (int k=0; k<12; k++) r[i][j][k]=0;
    cin>>n>>m;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) cin>>A[i][j];
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) 
    {
        if (j==1) dpH[i][j]=1;
        else dpH[i][j]= (A[i][j]==A[i][j-1]) ? dpH[i][j-1]+1 : 1;

        if (i==1) dpV[i][j]=1;
        else dpV[i][j]= (A[i][j]==A[i-1][j]) ? dpV[i-1][j]+1 : 1;

        r[i][j][0]=dpH[i][j];
    }

    //RMQ init:
    for (int k=1; k<12; k++) for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
    {
        r[i][j][k]=min(r[i][j][k-1], r[max(0ll, i-(1<<(k-1)))][j][k-1]);
    }

    // for (int i=1; i<=n; i++) 
    // {
    //     for (int j=1; j<=m; j++) 
    //     {
    //         for (int k=0; k<3; k++) cout<<r[i][j][k]<<"-";
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans=0;
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
    {
        int i1=i-dpV[i][j], i2=i-dpV[i][j]*2;
        if (i1<=0 || i2<=0) continue;
        if (dpV[i1][j]!=dpV[i][j] || dpV[i2][j]<dpV[i][j]) continue;
        // cerr<<"Got here: "<<i<<" "<<j<<endl;
        int temp=RMQ(i, j, dpV[i][j]);
        temp=min(temp, RMQ(i1, j, dpV[i][j]));
        temp=min(temp, RMQ(i2, j, dpV[i][j]));

        ans+=temp;
    }
    cout<<ans;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/