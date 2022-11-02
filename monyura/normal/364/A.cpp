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


void run()
{
    int a;
    cin>>a;
    int Cnt[50100]={0};
    char str[10100];
    scanf("%s",str);
    int n = strlen(str);
    rep(i,0,n)
    {
        int s =  0;
        rep(j,i,n)
        {
            s += str[j] - '0';
            Cnt[s]++;
        }
    }
    ll res = 0;
    if (a > 0)
    {
        rep(i,0,n)
        {
            int s =  0;
            rep(j,i,n)
            {
                s += str[j] - '0';
                if (s != 0 && a % s == 0 && a/s<50100)
                {
                    res += Cnt[a/s];
                }
            }
        }
    }
    else
    {
        res = n*ll(n+1);
        res *= Cnt[0];
        res -= Cnt[0] * ll(Cnt[0]);
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
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}