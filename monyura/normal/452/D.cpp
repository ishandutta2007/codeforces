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
typedef pair<double, double> pdd;

short int Cnt[15000100][3]={0};
void run()
{
    int k;
    int n1,n2,n3;
    int t1,t2,t3;
    cin>>k;
    cin>>n1>>n2>>n3;
    cin>>t1>>t2>>t3;
    int add1 = k, add2 = 0, add3 = 0;
    Cnt[0][0] = n1;
    Cnt[0][1] = n2;
    Cnt[0][2] = n3;
    for (int t = 1; ;t++)
    {
        add2 += Cnt[t][0];
        add3 += Cnt[t][1];
        Cnt[t][0] += Cnt[t-1][0];
        Cnt[t][1] += Cnt[t-1][1];
        Cnt[t][2] += Cnt[t-1][2];
        //
        int can1 = min((int)Cnt[t][0], add1);
        add1 -= can1;
        Cnt[t][0] -= can1;
        Cnt[t+t1][0] += can1;
        //
        int can2 = min((int)Cnt[t][1], add2);
        add2 -= can2;
        Cnt[t][1] -= can2;
        Cnt[t+t2][1] += can2;
        //
        int can3 = min((int)Cnt[t][2], add3);
        add3 -= can3;
        Cnt[t][2] -= can3;
        Cnt[t+t3][2] += can3;
        if (add1 ==0 && add2 == 0 && add3 == 0 && Cnt[t][0]==n1 && Cnt[t][1]==n2 && Cnt[t][2]==n3)
        {
            printf("%d\n", t-1);
            return;
        }
    }
}

//#define prob "path"


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