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

int n, A[mn];

int incr[mn], decr[mn];
int ans[mn];

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

    //increasing
    vector <pii> stk={{0, 0}};
    for (int i=1; i<=n; i++)
    {
        while (stk.back().XX>A[i])
        {
            stk.pop_back();
        }
        incr[i]=incr[stk.back().YY]+(i-stk.back().YY)*A[i];
        stk.push_back({A[i], i});
    }

    // for (int i=1; i<=n; i++) cerr<<incr[i]<<" ";

    //decreasing
    stk={{0, n+1}};
    for (int i=n; i>=1; i--)
    {
        while (stk.back().XX>A[i])
        {
            stk.pop_back();
        }
        decr[i]=decr[stk.back().YY]+(stk.back().YY-i)*A[i];
        stk.push_back({A[i], i});
    }
    // for (int i=1; i<=n; i++) cerr<<decr[i]<<" ";

    pii ans2={-inf, 0};
    for (int i=1; i<=n; i++) ans2=max(ans2, {incr[i]+decr[i]-A[i], i});
    int ans1=ans2.YY;
    int temp=A[ans1];
    for (int i=ans1; i>0; i--) 
    {
        temp=min(temp, A[i]);
        ans[i]=temp;
    }
    temp=A[ans1];
    for (int i=ans1; i<=n; i++) 
    {
        temp=min(temp, A[i]);
        ans[i]=temp;
    }

    for (int i=1; i<=n; i++) cout<<ans[i]<<" ";

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/