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
#define mn 250005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int fctrl[mn];

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

    fctrl[0]=1;
    for (int i=1; i<=n; i++) fctrl[i]=(fctrl[i-1]*i)%m;

    int ans=0;
    for (int k=1; k<=n; k++) 
    {
        int ret=(n-k+1);
        ret=(ret*ret)%m;
        ret=(ret*fctrl[k])%m;
        ret=(ret*fctrl[n-k])%m;
        ans=(ans+ret)%m;
    }
    cout<<ans;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/