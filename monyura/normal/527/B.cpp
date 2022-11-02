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
#include <complex>


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


const double PI = acos(-1.0);

char A[200200],B[200200];
void run()
{
    int n;
    cin>>n;
    scanf("%s%s",A,B);
    int pos[300][300];
    memset(pos,-1,sizeof(pos));
    int res = 0;
    rep(i,0,n)
        res += A[i] != B[i];
    pii p(-1, -1);
    rep(i,0,n)
        if (A[i] != B[i])
        {
            pos[A[i]][B[i]] = i;
            if (pos[B[i]][A[i]] != -1)
            {
                res -= 2;
                p.first = pos[B[i]][A[i]] + 1;
                p.second = i + 1;
                break;
            }
        }
    if (p.first == -1)
    {
        memset(pos,-1,sizeof(pos));
        rep(i,0,n)
            if (A[i] != B[i])
            {
                pos[A[i]][0] = i;
                pos[B[i]][1] = i;
                if (pos[A[i]][1]!=-1)
                {
                    --res;
                    p = pii(pos[A[i]][1] +1 , i+1);
                    break;
                }
                if (pos[B[i]][0]!=-1)
                {
                    --res;
                    p = pii(pos[B[i]][0]+1, i+1);
                    break;
                }
                
            }
    }
    cout<<res<<endl;
    cout<<p.first<<' '<<p.second<<endl;
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