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


const int SZ = 510000;
int D[SZ];
void run()
{
    int n,d;
    cin>>n>>d;
    int A[100];
    rep(i,0,n)
       scanf("%d",A+i);
    sort(A,A+n);
    int sum = 0;
    int to = n;
    rep(i,0,n)
    {
        if (sum + d < A[i])
        {
            to = i;
            break;
        }
        sum += A[i];
    }
    const int INF = 1e9;
    D[0] = 1;
    rep(i,0,n)
    {
        for (int s = SZ-1;s>=0;s--)
        {
            if (s + A[i] < SZ)
                D[s+A[i]] |= D[s];
        }
    }
    if (sum == 0)
    {
        cout<<"0 0"<<endl;
        return;
    }
    int mxSum = 0;
    int mxPos = 0;
    rep(i,0,SZ)
    {
        int pr = mxSum;
        while (mxPos < SZ && mxPos <= pr + d)
        {
            if (D[mxPos])
                mxSum = mxPos;
            mxPos++;
        }
        if (mxSum == sum)
        {
            cout<<sum<<' '<<i+1<<endl;
            return;
        }
        
    }
    
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
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}