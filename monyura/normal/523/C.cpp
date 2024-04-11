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

int getPos(char *str, char *pat)
{
    int pos = 0;
    int n = strlen(str);
    int m = strlen(pat);
    rep(i,0,n)
    {
        if (pos < m && str[i] == pat[pos])
            ++pos;
        if (pos == m)
            return i;
    }
    return -1;
}
char A[1001];
char B[1001000];
void run()
{
    scanf("%s%s",A,B);
    int n = strlen(A);
    int m = strlen(B);
    int p1 = getPos(B, A);
    reverse(A,A+n);
    reverse(B,B+m);
    int p2 = m - 1 - getPos(B, A);
    if (p1 == -1 || p1 >= p2)
        cout<<0<<endl;
    else
        cout<<p2 - p1<<endl;
}

//#define prob "exam"



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