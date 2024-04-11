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
    int n,m;
    cin>>n>>m;
    if (m == 1)
    {
        cout<<n<<endl;
        return;
    }
    int A[200100];
    int B[400100];
    rep(i,0,n)
        scanf("%d",A+i);
    rep(i,0,m)
        scanf("%d",B+i);
    rep(i,0,n-1)
        A[i] = A[i+1]-A[i];
    rep(i,0,m-1)
        B[i] = B[i+1]-B[i];
    B[m-1] = 2e9;
    memcpy(B+m,A, sizeof(int) * (n-1));
    int cnt = n + m - 1;
    int Z[400100]={0};
    int l = 0, r = -1;
    int res = 0;
    rep(i,1,cnt)
    {
        int here = max(0, min(r - i + 1, Z[i-l]));
        while (i + here<cnt && B[here] == B[i+here])
            ++here;
        if (i > m-1 && here == m-1)
            ++res;
        if (i + here - 1 > r)
        {
            l = i;
            r = i + here - 1;
        }
        Z[i] = here;
    }
//    rep(i,0,cnt)
//        printf("%d ",B[i]);
//    puts("");
//    rep(i,0,cnt)
//        printf("%d ",Z[i]);
//    puts("");
    cout<<res<<endl;

}

//#define prob "fields"


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