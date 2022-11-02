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

void norm(char *str, int n)
{
    reverse(str,str+n);
    str[n+1] = 0;
    str[n] = '0';
    for (int i = n-2;i>=0;i--)
    {
        int pos = i;
        while(pos < n - 1 && str[pos]=='1' && str[pos+1]=='1')
        {
            str[pos+2] = '1';
            str[pos+1]='0';
            str[pos]='0';
            pos = pos+2;
        }
    }
}

void run()
{
    char A[100100];
    char B[100100];
    scanf("%s",A);
    scanf("%s",B);
    int n = strlen(A);
    norm(A,n);
    int m = strlen(B);
    norm(B, m);
    n++; m++;
    //cout<<A<<endl;
    //cout<<B<<endl;
    int mx = max(n,m);
    rep(i,0,mx)
    {
        if (i >= n)
            A[i] = '0';
        if (i >= m)
            B[i] = '0';
    }
    A[mx] = B[mx] = 0;
    for (int i = mx-1;i>=0;i--)
        if (A[i] != B[i])
        {
            if (A[i] > B[i])
                puts(">");
            else
                puts("<");
            return;
        }
    puts("=");
    
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