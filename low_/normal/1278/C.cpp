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

int T;
int n;
int L[mn], R[mn];
int NR[2*mn];



signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for (int i=0; i<mn*2; i++) NR[i]=inf;

    cin>>T;
    while (T--)
    {
        cin>>n;
        int b=0, s=0; //blueberry and strawberry counts
        for (int i=n; i>0; i--) 
        {
            cin>>L[i];
            if (L[i]==2) L[i]=-1, b++;
            else s++;
        }
        for (int i=1; i<=n; i++) 
        {
            cin>>R[i];
            if (R[i]==2) R[i]=-1, b++;
            else s++;
        }

        for (int i=1; i<=n; i++) L[i]+=L[i-1], R[i]+=R[i-1];

        for (int i=0; i<=n; i++) NR[mn+R[i]]=min(NR[mn+R[i]], i);

        // for (int i=1; i<=n; i++) cout<<L[i]<<" ";
        // cout<<"\n";
        // for (int i=1; i<=n; i++) cout<<R[i]<<" ";
        // cout<<"\n\n";

        int ans=inf;
        int h=s-b;
        for (int i=0; i<=n; i++) ans=min(ans, i+NR[mn-L[i]+h]);

        cout<<ans<<"\n";
        //reset;
        for (int i=1; i<=n; i++) NR[mn+R[i]]=inf;
        
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/