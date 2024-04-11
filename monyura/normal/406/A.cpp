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



int A[1001][1001];
char str[1000100];
int getRes(int n)
{
    int res = 0;
    rep(i,0,n)
    rep(j,0,n)
    {
        if (A[i][j] == A[j][i] && A[i][j] == 1)
            ++res;
    }
    return res&1;
}

void flipRow(int r, int n)
{
    rep(i,0,n)
        A[r][i] = 1- A[r][i];
}

void flipCol(int c, int n)
{
    rep(i,0,n)
        A[i][c] = 1 - A[i][c];
}

void run()
{
    int n;
    cin>>n;
    rep(i,0,n)
    {
        rep(j,0,n)
        {
            scanf("%d",&A[i][j]);
        }
    }
    int R[1001]={0}, C[1001]={0};
    int res = 0;
    rep(i,0,n)
        rep(j,0,n)
        {
            R[i] += A[i][j];
            C[j] += A[i][j];
            if (A[i][j] == A[j][i] && A[i][j] == 1)
                ++res;
        }
    res &= 1;
    int q;
    scanf("%d",&q);
    int pos = 0;
    rep(i,0,q)
    {
        int t;
        scanf("%d",&t);
        int x;
        if (t == 1)
        {
            scanf("%d",&x);
            --x;
            res = (res+A[x][x])&1;
            A[x][x] = (A[x][x]+1)&1;
            res = (res+A[x][x])&1;
//            flipRow(x, n);
        }
        else if (t == 2)
        {
            scanf("%d",&x);
            --x;
  //          flipCol(x, n);
            res = (res+A[x][x])&1;
            A[x][x] = (A[x][x]+1)&1;
            res = (res+A[x][x])&1;
        }
        else
        {
            str[pos++] = '0'+(res&1);
//            int real = getRes(n);
//            printf("%d %d\n", res&1, real);
        }
    }
    puts(str);
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