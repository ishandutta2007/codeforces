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

int T, n;
int A[mn];

bool all_hidden()
{
    for (int i=1; i<=n; i++) if (A[i]!=-1) return 0;
    return 1;
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
        cin>>n;
        for (int i=1; i<=n; i++) cin>>A[i];

        if (all_hidden()) {
            cout<<"0 1\n";
            continue;
        }
        A[0]=-1, A[n+1]=-1;
        int minQ=inf, maxQ=-inf;
        for (int i=1; i<=n; i++) if (A[i]==-1)
        {
            if (A[i-1]!=-1) minQ=min(minQ, A[i-1]), maxQ=max(maxQ, A[i-1]);
            if (A[i+1]!=-1) minQ=min(minQ, A[i+1]), maxQ=max(maxQ, A[i+1]);
        }

        int ans=(maxQ-minQ+1)/2;
        for (int i=1; i<n; i++) if (A[i]!=-1 && A[i+1]!=-1) {
            ans=max(ans, abs(A[i]-A[i+1]));
        }
        cout << ans << " " << (maxQ+minQ)/2 << "\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/