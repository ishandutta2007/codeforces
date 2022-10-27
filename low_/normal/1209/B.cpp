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
#define mn 2605
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n;
bool bit[mn];
int A[mn], B[mn];
bool brd[105][mn];

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
    char x;
    for (int i=1; i<=n; i++)
    {
        cin>>x;
        bit[i]=x-'0';
    }
    for (int i=1; i<=n; i++) cin>>A[i]>>B[i];

    for (int i=1; i<=n; i++)
    {
        brd[i][0]=bit[i];
        int nxt=B[i];
        for (int j=1; j<mn; j++) 
        {
            if (j==nxt) 
            {
                brd[i][j]=(!brd[i][j-1]);
                nxt+=A[i];
            }
            else brd[i][j]=brd[i][j-1];
        }
    }
    int ans=-inf;
    for (int j=0; j<mn; j++)
    {
        int tmp=0;
        for (int i=1; i<=n; i++) tmp+=brd[i][j];
        ans=max(ans, tmp);
    }
    cout<<ans;

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/