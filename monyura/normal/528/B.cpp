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

const int SZ = 200200;
int Fen[SZ];
void addFen(int pos, int val)
{
    ++pos;
    for (int i = pos; i < SZ; i += i&-i)
        Fen[i] = max(Fen[i], val);
}

int getFen(int pos)
{
    ++pos;
    int res = 0;
    for (int i = pos; i > 0; i-= i & -i)
        res = max(res, Fen[i]);
    return res;
}

pii A[SZ];
int Comp[SZ];
void run()
{
    int n;
    cin>>n;
    rep(i,0,n)
    {
        scanf("%d%d",&A[i].first, &A[i].second);
        Comp[i] = A[i].first + A[i].second;
    }
    sort(A, A + n);
    sort(Comp, Comp + n);
    int res = 1;
    rep(i,0,n)
    {
        int x = A[i].first;
        int w = A[i].second;
        int pos  = upper_bound(Comp, Comp +n, x - w) - Comp - 1;
        int here = getFen(pos) + 1;
        int pos2 = lower_bound(Comp, Comp + n, x + w) - Comp;
        addFen(pos2, here);
        res = max(res, here);
    }
    cout<<res<<endl;
}

//#define prob "exam"



int main()
{
#ifdef _MONYURA_
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
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