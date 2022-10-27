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
#define X XX.XX
#define Y XX.YY
#define Z YY.XX
#define I YY.YY

int n;
deque <pair <pii, pii> > DQ;
deque <int> P;

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
    DQ.assign(n, {{0, 0}, {0, 0}});
    P.assign(n, 0);
    for (int i=0; i<n; i++) cin>>DQ[i].X>>DQ[i].Y>>DQ[i].Z, DQ[i].I=i;
    sort(DQ.begin(), DQ.end());
    vector <pii> ans;
    for (int i=1; i<n; i++)
    {
        if (DQ[i].X==DQ[i-1].X && DQ[i].Y==DQ[i-1].Y)
        {
            ans.push_back({DQ[i].I, DQ[i-1].I});
            P[i]=P[i-1]=1;
            i++;
        }
    }
    deque <pair <pii, pii> > D2={};
    for (int i=0; i<n; i++) if (P[i]==0) D2.push_back(DQ[i]);

    // cerr<<DQ.size()<<" "<<ans.size()<<"\n";
    DQ=D2;
    P.assign(DQ.size(), 0);
    for (int i=1; i<DQ.size(); i++)
    {
        if (DQ[i].X==DQ[i-1].X)
        {
            ans.push_back({DQ[i].I, DQ[i-1].I});
            P[i]=P[i-1]=1;
            i++;
        }
    }
    D2={};
    for (int i=0; i<DQ.size(); i++) if (P[i]==0) D2.push_back(DQ[i]);

    // cerr<<DQ.size()<<" "<<ans.size()<<"\n";
    DQ=D2;
    // cerr<<DQ.size()<<" "<<ans.size()<<"\n";
    for (int i=1; i<DQ.size(); i+=2)
    {
        ans.push_back({DQ[i].I, DQ[i-1].I});
    }
    for (int i=0; i<n; i+=2) cout<<ans[i/2].XX+1<<" "<<ans[i/2].YY+1<<'\n';
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/