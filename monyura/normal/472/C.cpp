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
typedef pair<string, string> pss;



void run()
{
    int n;
    cin>>n;
    char A[100],B[100];
    pss V[100100];
    rep(i,0,n)
    {
        scanf("%s%s",A,B);
        V[i] = pss(A,B);
        if (V[i].first > V[i].second)
            swap(V[i].first, V[i].second);
    }
    int P[100100];
    rep(i,0,n)
    {
        scanf("%d",P+i);
        --P[i];
    }
    string last = V[P[n-1]].second;
    for (int i = n-2;i>=0;i--)
    {
        if (V[P[i]].second < last)
            last = V[P[i]].second;
        else if (V[P[i]].first < last)
            last = V[P[i]].first;
        else
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
    
    
}

//#define prob "fields"


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