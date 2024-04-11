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
typedef pair<double, double> pdd;

const int SZ = 100100;

bool check(ll a, ll b, ll c, ll left)
{
    ll A[3]={a,b,c};
    sort(A,A+3);
    ll has = A[2]-A[0] + A[2]-A[1];
    return has<=left && (left-has)%3 == 0;
}

void run()
{
    int t;
    cin>>t;
    ll n,k,d1,d2;
    rep(i,0,t)
    {
        scanf("%I64d%I64d%I64d%I64d",&n, &k, &d1,&d2);
//        cin>>n>>k>>d1>>d2;
        ll d3 = d2-d1 >0 ? d2-d1 : d1 -d2;
        ll d4 = max(d1,d2);
        n-= k;
        bool ok = false;
        if ((k - d1 - d2) % 3 == 0 && (k-d1-d2 >=0))
            ok |= check(0, d1, d2, n);
        if ((k - d1 - d1 - d2) % 3 == 0 && (k- d1 - d1 - d2)>=0)
            ok |= check(0, d1, d1+d2, n);
        if ((k - d1 - d2 - d2) % 3 == 0 && (k- d1 - d2 - d2)>=0)
            ok |= check(0, d2, d1+d2, n);
        if ((k - d3  - d4) % 3 == 0 && (k -  d3 - d4)>=0)
            ok |= check(0, d3, d4, n);
        puts(ok?"yes":"no");
    }
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