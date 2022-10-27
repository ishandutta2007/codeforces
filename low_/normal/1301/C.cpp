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

    int ntest;
    cin>>ntest;
    while (ntest--) {
        cin>>n>>m;
        int no_of_0 = n-m;
        int q = no_of_0 / (m+1), r = no_of_0 % (m+1);

        // cerr<<q<<" "<<r<<"\n";

        int ans = n*(n+1)/2;
        if (r!=0) {
            ans -= r * (q+1) * (q+2) / 2;
            ans -= (m+1-r) * (q) * (q+1) / 2;
        }
        else {
            ans -= (m+1) * q * (q+1) /2;
        }
        cout<<ans<<"\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/