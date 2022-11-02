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
    int n;
    scanf("%d",&n);
    char str[3001];
    scanf("%s",str);
    int L[3001];
    int R[3001];
    int pos = -1;
    rep(i,0,n)
    {
        if (str[i] == 'R')
            pos = i;
        if (str[i] == 'L')
            pos = -1;
        R[i] = pos;
    }
    pos = -1;
    for (int i = n-1;i>=0;i--)
    {
        if (str[i] == 'L')
            pos = i;
        if (str[i] == 'R')
            pos = -1;
        L[i] = pos;
    }
    int res = 0;
    rep(i,0,n)
    {
        //cout<<L[i]<<' '<<R[i]<<endl;
        if (str[i] == '.' && (L[i] != -1 && R[i]!=-1 && L[i] - i == i - R[i] || L[i]==-1 && R[i]==-1))
            ++res;
    }
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