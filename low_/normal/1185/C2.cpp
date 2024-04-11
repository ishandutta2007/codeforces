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
#define mn 400005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, M;
int t[mn];

class fenwick{
private:
    int FW[mn], cnt[mn];
public:
    fenwick()
    {
        for(int i=0; i<mn; i++) FW[i]=0, cnt[i]=0;
    };

    //update both BIT
    void update(int u, int w)
    {
        while (u<=n){
            FW[u]+=w;
            cnt[u]++;
            u+=u&(-u);
        }
    }
    //get sum
    int sumGet(int u)
    {
        int ret=0;
        while (u>0){
            ret+=FW[u];
            u-=u&(-u);
        }
        return ret;
    }

    //get count
    int cntGet(int u)
    {
        int ret=0;
        while (u>0){
            ret+=cnt[u];
            u-=u&(-u);
        }
        return ret;
    }
    
    int bs(int T, int i)
    {
        int l=0, r=n;
        while (r>l)
        {
            int mid=(l+r)/2+1;
            if (sumGet(mid)>T) r=mid-1;
            else l=mid;
        }
        return i-1-cntGet(l);
    }
} fw1;

pii AA[mn];
int updatePos[mn];

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
    for (int i=1; i<=n; i++) 
    {
        cin>>t[i];
        AA[i]={t[i], i};
    }
    sort(AA+1, AA+n+1);
    for (int i=1; i<=n; i++) updatePos[AA[i].YY]=i;

    for (int i=1; i<=n; i++)
    {
        cout<<fw1.bs(M-t[i], i)<<" ";
        fw1.update(updatePos[i], t[i]);
    }

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/