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
pii seg[mn];

vector <pii> Edg;
int A[mn]; 

int root[mn];
int getroot(int u)
{
    if (u==root[u]) return u;
    else return root[u]=getroot(root[u]);
}

bool mergeroot(int u, int v)
{
    if (getroot(u)==getroot(v)) return 0;
    root[getroot(u)]=getroot(v);
    return 1;
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

    for (int i=0; i<mn; i++) root[i]=i;

    cin>>n;
    for (int i=1; i<=n; i++) cin>>seg[i].XX>>seg[i].YY;
    // sort(seg+1, seg+n+1);

    for (int i=1; i<=n; i++) A[seg[i].XX]=seg[i].XX, A[seg[i].YY]=-seg[i].XX;

    vector <int> V1={}, V2={};
    for (int i=1; i<=2*n; i++)
    {
        if (A[i]>0) V1.push_back(A[i]);
        else
        {
            while (!V1.empty())
            {
                if (V1.back()+A[i]==0)
                {
                    V1.pop_back();
                    break;
                }

                Edg.push_back({-A[i], V1.back()});
                V2.push_back(V1.back());
                V1.pop_back();
            }

            while (!V2.empty())
            {
                V1.push_back(V2.back());
                V2.pop_back();
            }

            if (Edg.size()>=n) break;
        }
    }

    for (pii p: Edg)
    {
        // cerr<<p.XX<<" "<<p.YY<<"\n";
        if (!mergeroot(p.XX, p.YY))
        {
            cout<<"NO";
            // cerr<<p.XX<<" "<<p.YY<<"\n";
            return 0;
        }
    }
    if (Edg.size()==n-1) cout<<"YES";
    else cout<<"NO";






}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: ttuandung1803@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie.exe/