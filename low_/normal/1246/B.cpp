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

int n, cnt[mn];
int k;

int IP[mn];

int minimize(int u)
{
    int ret=1;
    while (u>1)
    {
        int tmp=1, v=IP[u], cnt=0;
        while (u%v==0)
        {
            cnt++;
            tmp*=v;
            if (cnt==k) cnt=0, tmp=1;
            u/=v;
        }
        ret*=tmp;
    }
    return ret;
}

int findCntr(int u)
{
    int ret=1;
    while (u>1)
    {
        int v=IP[u];
        int cnt=0;
        while (u%v==0)
        {
            cnt=(cnt+1)%k;
            u/=v;
        }
        for (int i=0; i<k-cnt; i++) 
        {
            ret*=v;
            if (ret>=mn) return 0;
        }
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

    for (int i=0; i<mn; i++) IP[i]=i;
    for (int i=2; i<mn; i++) if (IP[i]==i) for (int j=i*i; j<mn; j+=i) IP[j]=i;

    cin>>n>>k;
    int u;
    for (int i=1; i<=n; i++)
    {
        cin>>u;
        u=minimize(u);
        cnt[u]++;
    }

    int ans=0;
    for (int i=1; i<mn; i++) if (cnt[i]>0)
    {
        int v=findCntr(i);
        if (i==v) ans+=cnt[i]*(cnt[i]-1);
        else ans+=cnt[i]*cnt[v];
    }

    cout<<ans/2;




}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/