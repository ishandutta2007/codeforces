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

const int SZ = 1000000;
bool used[SZ];
int A[SZ];

void run()
{
    int n;
    cin>>n;
    rep(i,0,n)
    {
        int a;
        scanf("%d",&a);
        --a;
        used[a] = 1;
    }
    int need = 0;
    rep(i,0,SZ/2)
    {
        if (used[i] && used[SZ-1-i])
        {
            ++need;
        }
    }
    int pos = 0;
    rep(i,0,SZ/2)
    {
        if (used[i]  && !used[SZ-1-i])
        {
            A[pos++] = SZ-1-i;
        }
        else if (!used[i] && used[SZ-1-i])
        {
            A[pos++] = i;
        }
        else if (!used[i] && !used[SZ-1-i])
        {
            if (need > 0)
            {
                --need;
                A[pos++] = i;
                A[pos++] = SZ-1-i;
            }
        }
    }
    printf("%d\n",pos);
    rep(i,0,pos)
        printf("%d ",A[i] + 1);
    puts("");
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