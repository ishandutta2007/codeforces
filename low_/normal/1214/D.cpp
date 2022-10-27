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

vector <vector <char> > B;
vector <vector <int> > dp, dp2;
vector <int> cnt;
int n, m;

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
    char x;
    B.assign(n, {});
    for (int i=0; i<n; i++) 
    {
        B[i].assign(m, '.');
        for (int j=0; j<m; j++) cin>>B[i][j];
    }

    //dp1
    dp.assign(n, {});
    for (int i=0; i<n; i++) dp[i].assign(m, 0);
    dp[0][0]=1;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if ((i!=0 || j!=0) && B[i][j]=='.')
    {
        if (i>0) dp[i][j]|=dp[i-1][j];
        if (j>0) dp[i][j]|=dp[i][j-1];
    }

    if (dp[n-1][m-1]==0) cout<<0;
    else 
    {
        bool b=0;
        //dp2
        dp2.assign(n, {});
        for (int i=0; i<n; i++) dp2[i].assign(m, 0);
        dp2[n-1][m-1]=1;
        for (int i=n-1; i>-1; i--) for (int j=m-1; j>-1; j--) if (B[i][j]=='.')
        {
            if (i<n-1) dp2[i][j]|=dp2[i+1][j];
            if (j<m-1) dp2[i][j]|=dp2[i][j+1];
        }

        cnt.assign(m+n+5, 0);
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (dp[i][j]>0 && dp2[i][j]>0) cnt[i+j]++;
        for (int i=1; i<m+n-2; i++) if (cnt[i]==1) b=1;
        if (b) cout<<1;
        else cout<<2;

    }

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/