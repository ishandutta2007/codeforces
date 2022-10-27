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


double dist(pii A, pii B)
{
    int x=A.XX-B.XX;
    int y=A.YY-B.YY;
    return sqrt(x*x+y*y);
}



pair <double, array <pii, 4> > calc(array <pii, 4> A)
{
    double ret=dist(A[1], A[0])+dist(A[2], A[1])+dist(A[3], A[2]);
    return {ret, A};
}

vector <array<pii, 4> > V;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin>>n>>m;

    if (n==0) V.push_back(array <pii, 4>{{{0, 1}, {0, m}, {0, 0}, {0, m-1}}});
    else if (m==0) V.push_back(array<pii, 4>{{{1, 0}, {n, 0}, {0, 0}, {n-1, 0}}});
    else 
    {
        V.push_back(array <pii, 4>{{{0, 1}, {n, m}, {0, 0}, {n, m-1}}});
        V.push_back(array <pii, 4>{{{1, 0}, {n, m}, {0, 0}, {n, m-1}}});
        V.push_back(array <pii, 4>{{{0, 1}, {n, m}, {0, 0}, {n-1, m}}});
        V.push_back(array <pii, 4>{{{1, 0}, {n, m}, {0, 0}, {n-1, m}}});
        V.push_back(array <pii, 4>{{{n, m}, {0, 0}, {0, m}, {n, 0}}});
        V.push_back(array <pii, 4>{{{n, m}, {0, 0}, {n, 0}, {0, m}}});
    }

    pair <double, array<pii, 4> > ans={0, V[0]};
    for (auto A:V)  ans=max(ans, calc(A));
    for (pii A:ans.second) cout<<A.XX<<" "<<A.YY<<"\n";
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/