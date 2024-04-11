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

void run()
{
    int n,m;
    cin>>n>>m;
    pii A[200200];
    ll sum[2] = {0};
    rep(i,0,n)
    {
        scanf("%d",&A[i].first);
        A[i].second = 0;
        sum[0] += A[i].first;
    }
    rep(i,0,m)
    {
        scanf("%d", &A[i+n].first);
        sum[1] += A[i+n].first;
        A[i+n].second = 1;
    }
    sort(A, A+n+m);
    ll res = sum[0] + sum[1] - A[n+m-1].first;
    ll use[2] = {0};
    ll was[2] = {sum[0], sum[1]};
    for (int i = n+m-1; i>=0; i--)
    {
        use[A[i].second]++;
        sum[A[i].second] -= A[i].first;
        if (double(use[0])*was[1] + double(use[1])*was[0] + sum[0]*(use[0]>0) + sum[1]*(use[1]>0) > res)
            continue;
        ll here = use[0] * was[1] + use[1] * was[0] + sum[0]*(use[0]>0) + sum[1]*(use[1]>0);
        res = min(res, here);
    }
    cout<<res<<endl;

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