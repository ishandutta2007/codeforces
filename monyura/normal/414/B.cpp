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

void run()
{
    int n,k;
    cin>>n>>k;
    const int mod = 1e9 + 7;
    int D[2001][2001]={0};
    rep(i,1,n+1)
        D[i][1] = 1;
    for (int i = n; i>=1; i--)
    {
        for (int len = 2; len <= k; len++)
        {
            ll res = 0;
            for (int j = i; j <= n; j+=i)
                res += D[j][len-1];
            D[i][len] = res % mod;
           // cout<<i<<' '<<len<<' '<<D[i][len]<<endl;
        }
    }
    ll res = 0;
    rep(i,1,n+1)
    res += D[i][k];
    res %= mod;
    cout<<res<<endl;
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