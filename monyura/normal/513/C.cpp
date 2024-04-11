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

void run()
{
    int n;
    cin>>n;
    int L[5],R[5];
    rep(i,0,n)
    cin>>L[i]>>R[i];
    long double D[10001][5] = {0};
    long double res = 0.0;
    rep(i,0,10001)
    {
        bool can = i >= *max_element(L, L+n);
        if (can)
        {
            rep(j,1,1<<n)
            {
                long double here = 1.0;
                int ones = -1;
                int cnt = 0;
                rep(k,0,n)
                if ((j>>k)&1)
                {
                    ones = k;
                    if (L[k] <= i && i <= R[k])
                        here *= 1.0/(R[k] - L[k] + 1);
                    else
                        here =0;
                    ++cnt;
                }
                else
                {
                    if (L[k] <= i && i <= R[k])
                        here *= (i - L[k])/(long double)(R[k] - L[k] + 1);
                }
                res += cnt == 1? here * D[i-1][ones] : here * i;
            }
        }
        rep(d, 0, n)
        {
            double p = 0.0;
            bool can = true;
            rep(j,0,n)
                if (j != d && L[j] > i)
                    can = false;
            if (can)
            {
                rep(j,0,1<<n)
                if ((j & (1<<d))==0)
                {
                    double here = 1.0;
                    int cnt = 0;
                    rep(k,0,n)
                    if ((j>>k)&1)
                    {
                        if (L[k] <= i && i <= R[k])
                            here *= 1.0/(i - L[k]+1);
                        else
                            here = 0;
                        ++cnt;
                    }
                    else if (k != d)
                    {
                        if (L[k]<=i && i<=R[k])
                            here *= (i-L[k])/(long double)(i - L[k] + 1);
                    }
                    if (cnt > 0)
                        p += here;
                }
                D[i][d] = D[i-1][d]*(1-p) + i * p;
//                cout<<i<<' '<<d<<' '<<p<<' '<<D[i][d]<<endl;
            }
        }
  //      cout<<endl;
    }
    printf("%.12lf\n",(double)res);
}

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