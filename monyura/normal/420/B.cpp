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


void run()
{
    int n,m;
    cin>>n>>m;
    bool cannotBe[100100] = {0};
    int inside[100100] = {0};
    int Q[100100];
    char str[10];
    int cnt = 0;
    bool was[100100];
    rep(i,0,m)
    {
        scanf("%s%d",str,Q+i);
        was[Q[i]] = 1;
        inside[Q[i]] ^= 1;
        if (str[0]=='-')
        {
            if (inside[Q[i]])
            {
                inside[Q[i]] ^= 1;
                ++cnt;
            }
            Q[i] = -Q[i];
        }
    }
    int last = -1;
    rep(i,0,m)
    {
        if (Q[i] < 0)
        {
            --cnt;
            if (cnt > 0)
                cannotBe[-Q[i]] = 1;
            if (cnt == 0)
                last = - Q[i];
        }
        else
        {
            if (cnt == 0)
            {
                if (last != -1 && last != Q[i])
                {
                    cannotBe[Q[i]] = 1;
                    cannotBe[last] = 1;
                }
            }
            if (cnt > 0)
                cannotBe[Q[i]] = 1;
            ++cnt;
        }
    }
    vector<int> res;
    rep(i,1,n+1)
        if (!cannotBe[i])
            res.push_back(i);
    printf("%d\n", res.size());
    rep(i,0,res.size())
        printf("%d%c",res[i], i==res.size() - 1 ?'\n':' ');
}


//#define prob "D-large"


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