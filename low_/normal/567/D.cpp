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
#define mn 200005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, k, a;
int m;
deque <int> A;
deque <pii> B;

int root[mn], cnt[mn];
pii join[mn];

int getroot(int u)
{
    if (u==root[u]) return u;
    else return root[u]=getroot(root[u]);
}

int cntShipInSeg(int u)
{
    return (u+1)/(a+1);
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

    cin>>n>>k>>a>>m;
    A.assign(m, 0);
    for (int i=0; i<m; i++) cin>>A[i];

    for (int i=0; i<m; i++) B.push_back({A[i], i});
    sort(B.begin(), B.end());
    B.push_front({0, 0});
    B.push_back({n+1, m+1});
    for (int i=1; i<=m; i++) join[B[i].YY]={i-1, i};
    for (int i=0; i<=m; i++) cnt[i]=B[i+1].XX-B[i].XX-1, root[i]=i;

    int c=0;
    for (int i=0; i<=m; i++) 
    {
        c+=cntShipInSeg(cnt[i]);
    //     cerr<<cnt[i]<<" ";
    }
    // cerr<<"\n";

    if (c>=k)
    {
        cout<<-1;
        return 0;
    }

    for (int i=m-1; i>=0; i--)
    {
        // cerr<<c<<"\n";
        //mergeRoot(join[i].XX, join[i].YY)
        int u=join[i].XX, v=join[i].YY;
        // cerr<<u<<" "<<v<<"\n";
        int ru=getroot(u), rv=getroot(v);

        c-=cntShipInSeg(cnt[ru]);
        c-=cntShipInSeg(cnt[rv]);
        cnt[ru]+=cnt[rv]+1;
        root[rv]=ru;
        c+=cntShipInSeg(cnt[ru]);

        if (c>=k)
        {
            cout<<i+1;
            return 0;
        }
    }


}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/