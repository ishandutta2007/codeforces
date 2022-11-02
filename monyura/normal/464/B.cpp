#include <iostream>
#include <iomanip>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

struct tri
{
    ll a,b,c;
    tri(){}
    tri(ll a0, ll b0, ll c0)
    {
        a = a0;
        b = b0;
        c = c0;
    }
};

bool isCube(tri *A)
{
    rep(i,0,8)
    {
        ll d[8];
        rep(j,0,8)
            d[j] = SQR(A[i].a-A[j].a) + SQR(A[i].b - A[j].b) + SQR(A[i].c - A[j].c);
        sort(d,d+8);
        if (d[1] == 0 || d[1]!=d[2] || d[2]!=d[3] || d[3]==d[4])
            return false;
        if (d[4] == 0 || d[4]!=d[5] || d[5] != d[6] || d[6] == d[7])
            return false;
        if (d[2] + d[3] != d[4] || d[1]+d[2]+d[3] != d[7])
            return false;
    }
    return true;
}

tri A[8];
bool found = false;

void rec(int pos)
{
    if (found)
        return;
    if (pos == 8)
    {
        if (isCube(A))
        {
            puts("YES");
            rep(i,0,8)
                printf("%d %d %d\n",int(A[i].a), int(A[i].b), int(A[i].c));
            found = true;
        }
        return;
    }
    ll V[3] = {A[pos].a, A[pos].b, A[pos].c};
    sort(V,V+3);
    do
    {
        A[pos].a = V[0];
        A[pos].b = V[1];
        A[pos].c = V[2];
        rec(pos+1);
    }
    while (next_permutation(V, V+3));
}

void run()
{
    rep(i,0,8)
        cin>>A[i].a>>A[i].b>>A[i].c;
    found = false;
    rec(0);
    if (!found)
        puts("NO");
}

//#define prob "fields"


int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}