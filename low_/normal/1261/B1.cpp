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

int n;
int m, A[mn];

class fwTree{
public:
    int FW[mn];

    fwTree()
    {
        for (int i=0; i<mn; i++) FW[i]=0;
    }
    void update(int u, int g)
    {
        // cerr<<u<<" "<<g<<"\n";
        while (u<=n)
        {
            FW[u]+=g;
            u+=(u&(-u));
        }
    }
    int get(int u)
    {
        int ret=0;
        while (u>0)
        {
            ret+=FW[u];
            u-=(u&(-u));
        }
        return ret;
    }
} FW1;

int BS(int u)
{
    int l=1, r=n;
    while (r>l)
    {
        int mid=(l+r)/2;

        if (FW1.get(mid)<u) l=mid+1;
        else r=mid;
    }
    return l;
}


pair <pii, int> Q[mn];
vector <int> ans;

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
    for (int i=1; i<=n; i++) cin>>A[i];
    cin>>m;
    for (int i=1; i<=m; i++) cin>>Q[i].XX.XX>>Q[i].XX.YY, Q[i].YY=i;
    sort(Q+1, Q+m+1);
    // for (int i=1; i<=m; i++) cerr<<Q[i].XX.XX<<' '<<Q[i].XX.YY<<" "<<Q[i].YY<<"\n";

    vector <pii> pri={{0, 0}};
    for (int i=1; i<=n; i++) pri.push_back({-A[i], i});
    sort(pri.begin()+1, pri.end());
    // cerr<<"...\n";

    int ptrq=1;
    ans.assign(m+1, 0);
    for (int i=1; i<=n; i++)
    {
        FW1.update(pri[i].YY, 1);
        // cerr<<pri[i].YY<<"\n";
        while (ptrq<=m)
        {
            if (Q[ptrq].XX.XX>i) break;
            int t=BS(Q[ptrq].XX.YY);
            ans[Q[ptrq].YY]=A[t];
            ptrq++;
            // cerr<<ptrq<<"\n";
        }
    }

    for (int i=1; i<=m; i++) cout<<ans[i]<<"\n";
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/