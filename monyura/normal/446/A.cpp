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
    int n;
    cin>>n;
    int A[100100];
    rep(i,0,n)
    scanf("%d",A+i);
    int Pr[100100], S[100100];
    int res = 1;
    Pr[0] = 1;
    rep(i,1,n)
    {
        if (A[i] > A[i-1])
            Pr[i] = Pr[i-1] + 1;
        else
            Pr[i] = 1;
    }
    S[n-1] = 1;
    for (int i = n-2; i>=0; i--)
    {
        if (A[i] < A[i+1])
            S[i] = S[i+1]+1;
        else
            S[i] = 1;
    }
    rep(i,0,n)
    {
        res = max(res, Pr[i] + (i<n-1));
        res = max(res, (i>0) + S[i]);
    }
    rep(i, 1, n-1)
    {
        if (A[i-1] + 1 < A[i+1])
            res = max(res, Pr[i-1] + S[i+1] + 1);
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