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
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c.size())

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
    int n,m;
    cin>>n>>m;
    int A[100100];
    rep(i,0,n)
        scanf("%d", A+i);
    while (A[n-1] == 0)
        --n;
    ll l = 0, r = 1e16;
    ll res = 0;
    while (l <= r) {
        ll t = (l+r)/2;
        int B[100100];
        memcpy(B, A, sizeof(int) * n);
        int studs = m;
        ll tm = t;
        bool ok = true;
        rep(i,0,n)
        {
            if (B[i] > (tm-i-1)) {
                --studs;
                if (studs == 0)
                {
                    ok = false;
                    break;
                }
                B[i] -= (tm-i-1);
                tm = t;
                --i;
            }
            else
                tm -= B[i];
        }
        if (ok) {
            res = t;
            r = t - 1;
        }
        else {
            l = t + 1;
        }
    }
    cout<<res<<endl;
}



int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen("../" prob ".in","r",stdin);
    freopen("../" prob ".out","w",stdout);
#else
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    time_t st=clock();
#endif
#else
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