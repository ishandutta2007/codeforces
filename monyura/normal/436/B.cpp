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


char A[2002][2002];
int Cnt[2002][2002]={0};
void run()
{
    int n,m,k;
    cin>>n>>m>>k;
    rep(i,0,n)
    {
        scanf("%s",&A[i]);
    }
    int dx[]={0,0};
    int dy[]={1,-1};
    char s[]="LR";
    rep(j,0,m)
    {
        int res = 0;
        rep(i,0,n)
        {
            rep(k,0,2)
            {
                int x = i + dx[k]*i;
                int y = j + dy[k]*i;
                if (x>=0 && x<n && y>=0 && y<m && A[x][y] == s[k])
                    ++res;
            }
            res += A[i][j]=='U' && ((i&1)==0);
        }
        printf("%d ",res);
    }
    puts("");
}


//#define prob "D-small-attempt1"


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