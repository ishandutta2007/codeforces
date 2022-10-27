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
#define mn 2005
#define inf 4444444444444444444
#define mod 998244353
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, k;
int H[mn];
int fret[mn][mn*2];

int f(int ind, int h)
{
    // cerr<<ind<<" "<<h<<"\n";
    if (fret[ind][h+mn]!=-1) return fret[ind][h+mn];
    if (ind==0) return (h==0);

    int ret=0;
    if (H[ind]==H[ind%n+1]) return fret[ind][h+mn]=ret=(f(ind-1, h)*k)%mod;
    else
    {
        ret=(ret+f(ind-1, h-1))%mod;
        ret=(ret+f(ind-1, h+1))%mod;
        ret=(ret+f(ind-1, h)*(k-2))%mod;
    }
    return fret[ind][h+mn]=ret;
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

    for (int i=0; i<mn; i++) for (int j=0; j<mn*2; j++) fret[i][j]=-1;

    cin>>n>>k;
    for (int i=1; i<=n; i++) cin>>H[i];
    int ans=0;
    for (int i=1; i<=n; i++) ans=(ans+f(n, i))%mod;
    cout<<ans;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/