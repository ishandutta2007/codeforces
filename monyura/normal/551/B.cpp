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
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c.size())

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;


char Str[3][100100];
void run()
{
    int Cnt[3][26] = {0};
    rep(i,0,3)
    {
        scanf("%s",Str[i]);
        rep(j,0,strlen(Str[i]))
            Cnt[i][Str[i][j]-'a']++;
    }
    int bestCnt = 0, bestSec = 0;
    int mx = 0;
    rep(cnt, 0, 100100)
    {
        int Here[26];
        memcpy(Here, Cnt[0], sizeof(Here));
        bool ok = true;
        rep(i,0,26)
            if (Here[i] >= ll(cnt) * Cnt[1][i])
                Here[i] -= cnt * Cnt[1][i];
            else
                ok = false;
        if (!ok)
            continue;
        int sec = 1e9;
        rep(i,0,26)
            if (Cnt[2][i])
                sec = min(sec, Here[i]/Cnt[2][i]);
        int here = cnt + sec;
        if (here > mx)
        {
            mx = here;
            bestCnt = cnt;
            bestSec = sec;
        }
    }
//    cout<<mx<<' '<<bestCnt<<' '<<bestSec<<endl;
    rep(i,0,bestCnt) {
        printf("%s", Str[1]);
    }
    rep(i,0,bestSec) {
        printf("%s", Str[2]);
    }
    rep(i,0,26)
        Cnt[0][i] -= bestCnt * Cnt[1][i] + bestSec * Cnt[2][i];
    rep(i,0,26)
    rep(j,0,Cnt[0][i])
    putchar('a' + i);
    puts("");
}



int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen("../" prob ".in","r",stdin);
    freopen("../" prob ".out","w",stdout);
#else
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    time_t st=clock();
#endif
#else
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