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

int T, n, x;
vector <int> A;

bool b_search(int u) {
    int l=0, r=n-1;
    while (r>l) {
        int mid=(l+r)/2;
        if (A[mid] < u) l = mid+1;
        else r=mid;
    }
    return (A[l]==u);
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
        cin>>n>>x;
        A.assign(n, 0);
        for (int i=0; i<n; i++) cin>>A[i];
        sort(A.begin(), A.end());

        if (x%A[n-1]==0) {
            cout<<x/A[n-1]<<"\n";
            continue;
        }
        
        int q=x/A[n-1], r=x%A[n-1];
        int ans=q + 1;
        if (q==0) 
        {
            ans = 2 - b_search(x);
        }
        cout<<ans<<"\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/