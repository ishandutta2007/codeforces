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

int n, A[mn];
deque <int> D;


int f1[mn], f2[mn];

bool check()
{
    for (int i=0; i<n; i++) if (f2[i]!=-1) return 0;
    return 1;
}
int dp2(int u)
{
    if (f2[u]!=-1) return f2[u];
    return f2[u]=(f1[u]+n-u)%n+dp2(f1[u]);
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
    for(int i=0; i<n; i++) cin>>A[i];
    for(int i=0; i<2*n; i++) D.push_back(A[i%n]);
    vector <pii> st={{inf, inf}};
    for (int i=2*n-1; i>-1; i--)
    {
        while (make_pair(D[i], i)>st.back()) st.pop_back();
        f1[i%n]=st.back().YY%n;
        st.push_back({D[i], i});
    }

    // for (int i=0; i<n; i++) cerr<<f1[i]<<"\n";

    deque <pii> qu={};
    for (int i=0; i<n; i++) f2[i]=-1;
    for (int i=0; i<2*n; i++)
    {
        while (qu.size()>0)
        {
            if ((qu[0].XX-1)/2<D[i]) break;
            f2[qu[0].YY%n]=(-qu[0].YY+n+i)%n;
            qu.pop_front();
        }
        while (qu.size()>0)
        {
            if (qu.back().XX>D[i]) break;
            qu.pop_back();
        }
        qu.push_back({D[i], i});
    }
    if (check()) for (int i=0; i<n; i++) cout<<"-1 ";
    else for (int i=0; i<n; i++) cout<<dp2(i)<<" ";
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/