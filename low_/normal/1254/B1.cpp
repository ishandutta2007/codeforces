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
#define mn 1000005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n;
int A[mn];
int ttl=0;
int B[mn];

bool IP[mn];

int tryDiv(int u)
{
    vector <pii> track;
    int ptr=0;
    int sumTr=0;
    int q=ttl/u;
    int ret=0;
    while (1)
    {
        if (q==0) break;
        // cerr<<ptr<<"\n";
        int ad=min(B[ptr], u-sumTr);
        if (ad==0) 
        {
            ptr++;
            continue;//insig
        }
        // cerr<<ptr<<" "<<ad<<"\n";
        B[ptr]-=ad;
        sumTr+=ad;
        track.push_back({ptr, ad});
        if (sumTr==u)
        {
            q--;
            //find median
            int tempSum=0;
            int med=0;
            for (pii P:track)
            {
                if (tempSum<=u/2 && tempSum+P.YY>u/2) 
                {
                    med=P.XX;
                    break;
                }
                tempSum+=P.YY;
            }

            //calc ret
            for (pii P:track)
            {
                ret+=abs(med-P.XX)*P.YY;
            }

            sumTr=0;
            track.clear();
        }
    }

    for (int i=1; i<=n; i++) B[i]=A[i];
    // cerr<<u<<" "<<ret<<"\n";
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

    //sieve
    for (int i=2; i<mn; i++) IP[i]=1;
    for (int i=2; i<mn; i++) if (IP[i])
    {
        // if (i<10) cerr<<i<<" ";
        for (int j=i*i; j<mn; j+=i) IP[j]=0;
    }

    cin>>n;
   
    for (int i=1; i<=n; i++) 
    {
        cin>>A[i];
        ttl+=A[i];
        B[i]=A[i];
    }

    if (ttl==1)
    {
        cout<<-1;
        return 0;
    }

    vector <int> U={ttl};
    for (int i=2; i*i<=ttl; i++) if (ttl%i==0)
    {
        if (IP[i]) U.push_back(i);
        if (i*i<ttl) if (IP[ttl/i]) U.push_back(ttl/i);
        // cerr<<ttl<<" "<<i<<"\n";
    }

    int ans=inf;

    for (int u:U)
    {
        ans=min(ans, tryDiv(u));
    }

    cout<<ans;

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/