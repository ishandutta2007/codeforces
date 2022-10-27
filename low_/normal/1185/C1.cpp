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

int n, M;
int A[mn];

int findAns(int u)
{
    vector <int> V={};
    int ttl=0;
    for (int i=1; i<u; i++) V.push_back(A[i]), ttl+=A[i];
    sort(V.begin(), V.end());
    int ret=0;
    while (V.size()>0)
    {
        if (ttl+A[u]<=M) break;
        ret++;
        ttl-=V.back();
        V.pop_back();
    }
    return ret;
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

    cin>>n>>M;
    for (int i=1; i<=n; i++) cin>>A[i];
    for (int i=1; i<=n; i++) cout<<findAns(i)<<" ";

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/