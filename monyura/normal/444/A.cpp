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

struct vert
{
    vector<pii> inc;
    int v;
} g[501];

void run()
{
    int n,m;
    cin>>n>>m;
    int v = 0;
    int e = 0;
    rep(i,0,n)
    {
        scanf("%d",&g[i].v);
        v += g[i].v;
    }
    double res = 0;
    rep(i,0,m)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        --a;--b;
        g[a].inc.push_back(pii(b,c));
        g[b].inc.push_back(pii(a,c));
        res = max(res, (g[a].v + g[b].v)/double(c));
    }
//    double res = e == 0? 0 : v/double(e);
    printf("%.13lf\n", res);
}

//#define prob "path"


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