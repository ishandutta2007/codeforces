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
ll Sum[SZ];
int A[SZ];
int Q[SZ];
void run()
{
    int n,t;
    double c;
    cin>>n>>t>>c;
    rep(i,0,n)
        scanf("%d",A + i);
    Sum[0] = A[0];
    rep(i,1,n)
        Sum[i] = A[i] + Sum[i-1];
    int m;
    cin>>m;
    rep(i,0,m)
    {
        int t;
        scanf("%d",&t);
        Q[t-1]++;
    }
    double mean = 0;
    rep(i,0,n)
    {
        mean = (mean + A[i]/double(t))/c;
        double rl =  i - t  >= 0 ? (Sum[i] - Sum[i-t])/double(t) : Sum[i]/double(t);
        double err = fabs(rl - mean)/rl;
        rep(j,0,Q[i])
        printf("%.8lf %.8lf %.8lf\n", rl, mean, err);
    }
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