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

int n, S[mn];

int fret[(1<<20)];
int prefSum[20][mn];
deque <int> POS[20];
int COST[20][20]; // COST[i][j] - cost to move every i behind j


int clrCount(int clr, int l, int r)
{
    return prefSum[clr][r]-prefSum[clr][l-1];
}

int cost(int u, int v) // REMEMBER TO INITIALIZE
{
    if (COST[u][v]!=-1) return COST[u][v];
    int ret=0;
    for (int w:POS[u]) ret+=clrCount(v, w, n);
    return COST[u][v]=ret;
}

int calc(int mask, int u) //calculate cost of adding u into the new string
{
    int ret=0;
    for (int i=0; i<20;i++) if (i!=u) if (((1<<i)&mask)==0) ret+=cost(i, u);
    return ret;
}

int f(int mask) // REMEMBER TO INITIALIZE
{
    if (fret[mask]!=-1) return fret[mask];
    if (mask==0) return 0;
    int ret=inf;
    for (int i=0; i<20; i++) if (((1<<i)&mask)>0) ret=min(ret, f(mask^(1<<i))+calc(mask^(1<<i), i));
    return fret[mask]=ret;
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

    for (int i=0; i< (1<<20); i++) fret[i]=-1;
    for (int i=0; i<20; i++) for (int j=0; j<20; j++) COST[i][j]=-1;

    cin>>n;
    for (int i=1; i<=n; i++) 
    {
        cin>>S[i];
        S[i]--;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<20; j++) 
        {
            if (S[i]==j) 
            {
                prefSum[j][i]=prefSum[j][i-1]+1;
                POS[j].push_back(i);
            }
            else prefSum[j][i]=prefSum[j][i-1];
        }
    }

    cout<<f((1<<20)-1);
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/