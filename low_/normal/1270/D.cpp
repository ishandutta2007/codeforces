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

signed main()
{
    int n, k;
    cin>>n>>k;

    //first 2 queries
    pii sm, lg;
    cout<<"? ";
    for (int i=1; i<=k; i++) cout<<i<<" ";
    cout<<endl;

    int u, v;
    cin>>u>>v;
    sm={u, v};
    cout<<"? ";
    for (int i=1; i<=k+1; i++) if (i!=sm.XX) cout<<i<<" ";
    cout<<endl;
    cin>>u>>v;
    lg={u, v};
    if (lg.YY<sm.YY) 
    {
        pii tmp=sm;
        sm=lg;
        lg=tmp;
    }

    // Qs to find answer:
    int ans=0;
    for (int i=1; i<=k+1; i++) if (i!=sm.XX && i!=lg.XX)
    {
        cout<<"? ";
        for (int j=1; j<=k+1; j++) if (j!=i) cout<<j<<" ";
        cout<<endl;
        cin>>u>>v;
        if (lg.XX==u)ans++;
    }
    cout<<"! "<<ans+1<<endl;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/