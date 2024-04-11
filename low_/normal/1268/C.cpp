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
pii A[mn];

class fenTree{
public:
    int FW[mn];

    fenTree()
    {
        for (int i=0; i<mn; i++) FW[i]=0;
    }

    void clear()
    {
        for (int i=0; i<mn; i++) FW[i]=0;
    }

    void UPD(int u, int g)
    {
        while (u<=n)
        {
            FW[u]+=g;
            u+=(u&(-u));
        }
    }

    int GET(int u)
    {
        int ret=0;
        while (u>0)
        {
            ret+=FW[u];
            u-=(u&(-u));
        }
        return ret;
    }

    int getRange(int u, int v)
    {
        return GET(v)-GET(u-1);
    }
} FW1, FW2;

int cntR[mn];
int ans[mn];
int sumInt(int l, int r)
{
    return r*(r+1)/2-(l-1)*l/2;
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


    cin>>n;
    for (int i=1; i<=n; i++) cin>>A[i].XX, A[i].YY=i;
    sort(A+1, A+n+1);

    //build cntR
    for (int i=1; i<=n; i++)
    {
        cntR[i]=FW1.getRange(A[i].YY, n);
        FW1.UPD(A[i].YY, 1);
    }

    //
    for (int i=1; i<=n; i++) ans[i]=ans[i-1]+cntR[i];
    FW1.clear();
    for (int i=1; i<=n; i++)
    {
        FW1.UPD(A[i].YY, 1);
        FW2.UPD(A[i].YY, A[i].YY);
        int l=1, r=n;
        int midInd=(i+1)/2;
        while (r>l)
        {
            int mid=(l+r)/2;
            if (FW1.GET(mid)<midInd) l=mid+1;
            else r=mid;
        }
        // cerr<<i<<" "<<l<<"\n";

        ans[i]+=FW2.getRange(l+1, n)-sumInt(l+1, l+(i-midInd))-FW2.getRange(1, l-1)+sumInt(l-midInd+1, l-1);
    }

    for (int i=1; i<=n; i++) cout<<ans[i]<<" ";

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/