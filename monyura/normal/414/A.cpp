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

int gcd(int a, int b)
{
    while (b)
    {
        int c = b;
        b = a % b;
        a = c;
    }
    return a;
}
void run()
{
    int n, k;
    cin>>n>>k;
    if (n == 1)
    {
        if (k == 0)
            puts("1");
        else
            puts("-1");
        return;
    }
    if (k == 0)
    {
        puts("-1");
        return;
    }
    bool odd = n&1;
    n = n / 2 * 2;
    int first = k - (n-2)/2;
    if (first <= 0)
    {
        puts("-1");
        return;
    }
    printf("%d %d ", first, 2*first);
    int left = n - 2;
    for (int i = 1; left>0; i+=2)
    {
        if (i != first && i !=2*first && (i+1)!=first && (i+1)!=2*first)
        {
            printf("%d %d ", i, i+1);
            left -= 2;
        }
    }
    if (odd)
        printf("%d ", 1000000000);
    printf("\n");
}


//#define prob "rvq"


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