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

int n, a, b;
map <int, int> M[2];
map <pii, int> S;

int crossProd(pii A, pii B)
{
    return A.XX*B.YY-A.YY*B.XX;
}

int AtoBC(pii A, pii B, pii C)
{
    int cp=crossProd({A.XX-B.XX, A.YY-B.YY}, {A.XX-C.XX, A.YY-C.YY});
    return cp;
}

bool CCW(pii A, pii B, pii C)
{
    return ((C.XX-B.XX)*(B.YY-A.YY)-(B.XX-A.XX)*(C.YY-B.YY))>0;
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

    cin>>n>>a>>b;
    int x, vx, vy;
    for (int i=1; i<=n; i++)
    {
        cin>>x>>vx>>vy;
        pii P={x+vx, a*x+b+vy}, P0={0, b}, P1={1, a+b};
        int cp=AtoBC(P, P0, P1);
        if (M[CCW(P0, P1, P)].count(cp)==0) M[CCW(P0, P1, P)][cp]=1;
        else M[CCW(P0, P1, P)][cp]++;
        if (S.count({vx, vy})==0) S[{vx, vy}]=1;
        else S[{vx, vy}]++;
    }

    int ans=0;
    for (pii p: M[0]) ans+=(p.YY-1)*p.YY;
    for (pii p: M[1]) ans+=(p.YY-1)*p.YY;
    for (pair <pii, int> p: S) ans-=(p.YY-1)*p.YY;
    cout<<ans;

    


}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/