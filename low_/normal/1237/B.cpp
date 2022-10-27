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

int n, A[mn], B[mn];

class fwTree{
private:
    int FW[mn];
public:
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

    void update(int u, int g)
    {
        while (u<=n)
        {
            FW[u]+=g;
            u+=(u&(-u));
        }
    }

    fwTree()
    {
        for (int i=0; i<mn; i++) FW[i]=0;
    }
};

fwTree f1;
int rankA[mn], rankB[mn];

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
        cin>>A[i];
        rankA[A[i]]=i;
    }
    for (int i=1; i<=n; i++) 
    {
        cin>>B[i];
        rankB[B[i]]=i;
    }

    int ans=0;
    for (int i=n; i>0; i--)
    {
        ans+=(f1.get(rankA[B[i]])>0);
        f1.update(rankA[B[i]], 1);
    }
    cout<<ans;


}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/