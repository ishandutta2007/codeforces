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


const int mod = 1e9+7;
const int Row = 14, Mask = 4782969;
int D[2][2][Mask];
int setbit[Mask][3];
int getbit[Mask][3];


int p3[20] = {1};

inline int setBit(int mask, int pos, int val)
{
    return (mask/p3[pos+1]*3 + val)*p3[pos] + mask % p3[pos];
}

inline int getBit(int mask, int pos)
{
    return mask/p3[pos] % 3;
}

inline int up(int i, int mask)
{
    if (i == 0)
        return 3;
    return getbit[mask][i-1];
}

inline int left(int i, int j, int mask)
{
    if (j == 0)
        return 3;
    return getbit[mask][i];
}

inline void addTo(int &a, int val)
{
    a += val;
    if (a>=mod)
        a-=mod;
}

inline int &next(int flag, int flag2, int i, int n, int mask)
{
    if (i == n-1)
        return D[flag^1][0][mask];
    return D[flag][flag2 ^ 1][mask];
}

void run()
{
    char str[]={"AHIMOTUVWXY"};
    char A[100100];
    scanf("%s",A);
    bool ok = 1;
    int n = strlen(A);
    rep(i,0,n/2)
    if (A[i] != A[n-1-i])
        ok = 0;
    rep(i,0,n)
     if (strchr(str,A[i]) == 0)
         ok = 0;
    puts(ok?"YES":"NO");
}


//#define prob "D-large"


int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#else
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
#ifndef prob
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
#endif
    
    return 0;
}