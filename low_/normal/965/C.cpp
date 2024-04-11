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

int n, k, M, D;

int cil(int u, int v)
{
    return (u-1)/v+1;
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

    cin>>n>>k>>M>>D;
    // int x;

    int ans=-inf;

    //calculate r by x: cil(n/x, k)
    for (int R=cil(n/M, k); R<=D; R++)
    {
        int l=1, r=M;
        while (r>l)
        {
            int mid=(l+r)/2+1;

            if (cil(n/mid, k)<R) r=mid-1;
            else l=mid;
        }
        int xmin=l;
        l=1, r=M;
        while (r>l)
        {
            int mid=(l+r)/2;

            if (R<cil(n/mid, k)) l=mid+1;
            else r=mid;
        }
        int xmax=l;

        if (cil(n/xmax, k)!=R) continue;

        ans=max(ans, cil(n/xmax, k)*xmax);
        ans=max(ans, cil(n/xmin, k)*xmin);
    }

    cout<<ans;

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/