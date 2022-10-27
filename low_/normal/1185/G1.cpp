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
#define inf 1111111111
#define mod 1000000007
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int dpret[32800][230][4];
int t[20], g[20];
int n, T;

int dp(int bit, int T, int last)
{
    // cerr<<bit<<" "<<T<<" "<<last<<"\n";
    if (dpret[bit][T][last]!=-1) return dpret[bit][T][last];
    if (T<0) return dpret[bit][T][last]=0;
    if (T==0) return dpret[bit][T][last]=1;

    int ret=0;
    for (int i=0; i<n; i++) if ((bit&(1<<i))==0 && g[i]!=last)
    {
        ret=(ret+dp(bit^(1<<i), T-t[i], g[i]))%mod;
    }
    return dpret[bit][T][last]=ret;
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
    for  (int i=0; i<32800; i++) for (int j=0; j<230; j++) 
        for (int k=0; k<4; k++) dpret[i][j][k]=-1;

    cin>>n>>T;
    for (int i=0; i<n; i++) cin>>t[i]>>g[i];
    cout<<dp(0, T, 0);
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/