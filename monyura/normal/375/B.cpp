#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif


#include <iostream>
#include <iomanip>
#include <cstdio>
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

char A[5002][5002];
short Ans[5001][5001]={0};
void run()
{
    int n,m;
//    n = 5000;
//    m = 5000;
//    rep(i,0,n)
//    memset(A[i],'1',m);
    cin>>n>>m;
    rep(i,0,n)
        scanf("%s",A[i]);
    rep(i,0,n)
    {
        for (int j = m-1; j>=0; j--)
            if (A[i][j] == '1')
            {
                int nxt = j+1 < m && A[i][j+1] == '1' ? Ans[i][j+1] : 0;
                Ans[i][j] = 1 + nxt;
            }
    }
    int Col[5001];
    int res = 0;
    rep(j,0,m)
    {
        rep(i,0,n)
        Col[i] = Ans[i][j];
        sort(Col,Col+n);
        rep(i,0,n)
        res = max(res, (n-i) * Col[i]);
    }
    cout<<res<<endl;
}

//#define prob "kids"

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
    printf("\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}