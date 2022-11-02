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
    int n, prev;
    cin>>n>>prev;
    bool B[100100]={1};
    int A[100100];
    A[0] = prev;
    rep(i,1,n)
    {
        int a;
        scanf("%d",&a);
        A[i] = a;
        B[i] = prev < a;
        prev = a;
    }
    int cnt = 0;
    int st = -1;
    rep(i,1,n)
    {
        cnt += B[i-1]==1 && B[i]==0;
        if (B[i-1]==1 && B[i]==0)
            st = i;
    }
    if (cnt > 1)
    {
        puts("no");
        return;
    }
    if (cnt == 0)
    {
        puts("yes\n1 1");
        return;
    }
    int end = st;
    while (end < n && B[end] == 0)
        ++end;
    rep(i,0, (end-st+1)/2)
        swap(A[st-1+i], A[end-1-i]);
    bool ok = 1;
    rep(i,0,n-1)
        if (A[i] >= A[i+1])
            ok = 0;
    if (ok)
    {
        printf("yes\n%d %d\n", st, end);
    }
    else
        puts("no");
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