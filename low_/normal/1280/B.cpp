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

int T;
int n, m;
int pSum[mn][mn];

int prefSum(int u1, int v1, int u2, int v2)
{
    return pSum[u2][v2]+pSum[u1-1][v1-1]-pSum[u2][v1-1]-pSum[u1-1][v2];
}

bool ansEq1()
{
    if (prefSum(1, 1, n, 1)==n) return 1;
    if (prefSum(1, m, n, m)==n) return 1;
    if (prefSum(1, 1, 1, m)==m) return 1;
    if (prefSum(n, 1, n, m)==m) return 1;
    return 0;
}

bool ansEq2()
{
    for (int i=1; i<=n; i++) if (prefSum(i, 1, i, m)==m) return 1;
    for (int i=1; i<=m; i++) if (prefSum(1, i, n, i)==n) return 1;

    if (prefSum(1, 1, 1, 1)==1) return 1;
    if (prefSum(1, m, 1, m)==1) return 1;
    if (prefSum(n, 1, n, 1)==1) return 1;
    if (prefSum(n, m, n, m)==1) return 1;
    return 0;
    
}

bool ansEq3()
{
    if (prefSum(1, 1, n, 1)>0) return 1;
    if (prefSum(1, m, n, m)>0) return 1;
    if (prefSum(1, 1, 1, m)>0) return 1;
    if (prefSum(n, 1, n, m)>0) return 1;
    return 0;
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

    cin>>T;
    while (T--)
    {
        cin>>n>>m;
        char c;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
        {
            cin>>c;
            if (c=='A') pSum[i][j]=1;
            else pSum[i][j]=0;
        }

        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) pSum[i][j]+=pSum[i-1][j];
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) pSum[i][j]+=pSum[i][j-1];

        if (prefSum(1, 1, n, m)==m*n) cout<<"0\n";
        else if (prefSum(1, 1, n, m)==0) cout<<"MORTAL\n";
        else if (ansEq1()) cout<<"1\n";
        else if (ansEq2()) cout<<"2\n";
        else if (ansEq3()) cout<<"3\n";
        else cout<<"4\n";
        
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/