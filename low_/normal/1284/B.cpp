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

int n;
vector <int> A[mn];

bool ascent(vector <int> V)
{
    int mnm=inf;
    for (int i:V) 
    {
        if (mnm<i) return 1;
        mnm=min(mnm, i);
    }
    return 0;
}

vector <pii> desc;
int cntR[mn*10];

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
    for (int i=1; i<=n; i++)
    {
        int sz;
        cin>>sz;
        A[i].assign(sz, 0);
        for (int j=0; j<sz; j++) cin>>A[i][j];
    }

    for (int i=1; i<=n; i++) if (!ascent(A[i])) desc.push_back({A[i].back(), A[i][0]});

    int sz=n-desc.size();
    int ans=sz*sz+2*sz*(n-sz);

    for (pii p: desc) cntR[p.YY]++;
    for (int i=1e6; i>=0; i--) cntR[i]+=cntR[i+1];

    for (pii p: desc) ans+=cntR[p.XX+1];

    cout<<ans;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/