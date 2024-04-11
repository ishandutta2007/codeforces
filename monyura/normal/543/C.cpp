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
#include <array>
#include <tuple>
#include <unordered_map>


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

int Res[1<<20];
void run()
{
    int n,m;
    cin>>n>>m;
    int A[21][21];
    char str[21][21];
    rep(i,0,n)
    scanf("%s",str[i]);
    rep(i,0,n)
    rep(j,0,m)
    {
        scanf("%d",&A[i][j]);
    }
    const int INF = 1e9;
    rep(i,0,1<<n)
        Res[i] = INF;
    Res[0] = 0;
    rep(j,0,m)
    {
        rep(c, 'a', 'z' + 1)
        {
            int mask = 0;
            int sum = 0;
            int mx  = 0;
            rep(i, 0, n)
            if (str[i][j] == c)
            {
                mask |= 1<<i;
                sum += A[i][j];
                mx = max(mx, A[i][j]);
            }
            int cost = sum - mx;
            if (mask != 0)
            {
                rep(t,0,1<<n)
                Res[t | mask] = min(Res[t | mask], Res[t] + cost);
            }
        }
        rep(r, 0, n)
        {
            int mask = 1<<r;
            int cost = A[r][j];
            rep(t,0,1<<n)
                Res[t | mask] = min(Res[t | mask], Res[t] + cost);
        }

    }
    cout<<Res[(1<<n)-1]<<endl;
}

//#define prob "graph"



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