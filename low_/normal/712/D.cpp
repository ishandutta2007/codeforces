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
#define mn 100000
#define mod 1000000007
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

vector <int> F, G;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    F.assign(mn*4+1, 0);
    G.assign(mn*4+1, 0);
    int a, b, k, t;
    cin>>a>>b>>k>>t;

    F[mn*2]=1;
    for (int i=0; i<2*t; i++)
    {
        G[0]=F[0];
        for (int j=1; j<=mn*4; j++) G[j]=(G[j-1]+F[j])%mod;

        

        for (int j=0; j<=mn*4; j++)
        {
            int l=max(0, j-k-1), r=min(mn*4, j+k);
            F[j]=(G[r]-G[l]+mod)%mod; 
        }
        // for (int j=mn*2-5; j<=mn*2+5; j++) cerr<<F[j]<<" ";
        // cerr<<"\n";
    }

    int ans=0;
    for (int i=mn*2-(a-b)+1; i<=mn*4; i++) ans=(ans+F[i])%mod;
    cout<<ans;
    
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/