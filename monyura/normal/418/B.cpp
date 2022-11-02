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



struct Fr
{
    int x,k;
    int mask;
    bool operator<(const Fr &other) const
    {
        return k < other.k;
    }
};

void run()
{
    Fr A[100];
    int n,m,b;
    cin>>n>>m>>b;
    rep(i,0,n)
    {
        int m;
        scanf("%d%d%d",&A[i].x, &A[i].k, &m);
        A[i].mask = 0;
        rep(j,0,m)
        {
            int a;
            scanf("%d",&a);
            A[i].mask |= (1<<(a-1));
        }
    }
    sort(A,A+n);
    ll D[1<<20];
    const ll INF = 7e18;
    rep(i,0,1<<m)
    D[i] = INF;
    D[0]  = 0;
    ll res = INF;
    rep(i,0,n)
    {
        for (int j = (1<<m)-1;j>=0; j--)
        {
            ll &val = D[j | A[i].mask];
            val = min(val, D[j] + A[i].x);
        }
        res = min(res, D[(1<<m)-1] + A[i].k * ll(b));
    }
    if (res == INF)
        res = -1;
    cout<<res<<endl;
}


//#define prob "D-large"


int main()
{
#ifdef _MONYURA_
    #ifdef prob
        freopen(prob".in","r",stdin);
        freopen(prob".out","w",stdout);
    #else
        freopen("test.in","r",stdin);
        freopen("test.out","w",stdout);
        time_t st=clock();
    #endif
#else
    #ifdef prob
        freopen(prob".in","r",stdin);
        freopen(prob".out","w",stdout);
    #endif
#endif
    run();
#ifdef _MONYURA_
    #ifndef prob
        printf( "\n=============\n");
        printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
    #endif
#endif
    
    return 0;
}