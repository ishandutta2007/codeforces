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

int check(char* A, char* B)
{
    //cerr<<A<<' '<<B<<endl;
    int st = 0;
    int lenb = strlen(B);
    int lena = strlen(A);
    while (st < lenb && A[st] == B[st])
        ++st;
    int en = 0;
    while (en < lenb && A[lena - 1 - en] == B[lenb - 1 - en])
        ++en;
    int res = st + en >= lenb ? 1 : 0;
    return res;
        
}

void run()
{
    int n;
    cin>>n;
    char A[100100];
    char B[100100];
    scanf("%s%s",A + 1,B + 1);
    int st = 1;
    while (A[st] == B[st])
        ++st;
    int en = n;
    while (A[en] == B[en])
        --en;
    A[en+1] = 0;
    B[en+1] = 0;
    int res = 0;
    A[st-1] = B[st];
    res += check(A + st  - 1, B + st);
    B[st-1] = A[st];
    res += check(B + st - 1, A + st);
    cout<<res<<endl;
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