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

int n, A[mn];
pii P[mn];

map <int, int> MAP;

void delMap(int u)
{
    MAP[u]--;
    if (MAP[u]<=0) MAP.erase(u);
}

void pushMap(int u)
{
    if (MAP.count(u)==0) MAP[u]=1;
    else MAP[u]++; 
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
    for (int i=1; i<=n; i++) 
    {
        cin>>A[i];
        P[i]={A[i], i};
    }

    if (n<=3)
    {
        cout<<1;
        return 0;
    }

    sort(P+1, P+n+1);
    for (int i=1; i<n; i++) 
    {
        int x=P[i+1].XX-P[i].XX;
        pushMap(x);
    }
    if (MAP.size()>3) 
    {
        cout<<-1;
        return 0;
    }

    int ans=-1;

    for (int i=2; i<n; i++)
    {
        delMap(P[i].XX-P[i-1].XX);
        delMap(P[i+1].XX-P[i].XX);
        pushMap(P[i+1].XX-P[i-1].XX);
        if (MAP.size()==1) 
        {
            ans=P[i].YY;
            break;
        }
        pushMap(P[i].XX-P[i-1].XX);
        pushMap(P[i+1].XX-P[i].XX);
        delMap(P[i+1].XX-P[i-1].XX);
    }

    if (ans>=0)
    {
        cout<<ans;
        return 0;
    }

    delMap(P[2].XX-P[1].XX);
    if (MAP.size()==1)
    {
        cout<<P[1].YY;
        return 0;
    }
    pushMap(P[2].XX-P[1].XX);

    delMap(P[n].XX-P[n-1].XX);
    if (MAP.size()==1)
    {
        cout<<P[n].YY;
        return 0;
    }
    pushMap(P[2].XX-P[1].XX);

    cout<<-1;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/