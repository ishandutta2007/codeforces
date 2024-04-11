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
    char A[2][100];
    rep(i,0,2)
        scanf("%s",A[i]);
    char str[]="(8[";
    int Cnt[2] = {0};
    for (int i = 0; A[0][i]; i+=2)
    {
        int ind1 = strchr(str, A[0][i]) - str;
        int ind2 = strchr(str, A[1][i]) - str;
        if (ind2 == (ind1+1)%3)
            ++Cnt[0];
        if (ind1 == (ind2+1)%3)
            ++Cnt[1];
    }
    if (Cnt[0] != Cnt[1])
        printf("TEAM %d WINS\n", Cnt[0] > Cnt[1] ? 1 : 2);
    else
        puts("TIE");
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