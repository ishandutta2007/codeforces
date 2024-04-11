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
    vector<int> inc[1001];
    int A[1001];
    pii Cost[1001];
    rep(i,0,n)
    {
        scanf("%d",A+i);
        Cost[i].first = A[i];
        Cost[i].second = i;
    }
    sort(Cost, Cost + n, greater<pii>());
    rep(i,0,m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        inc[a].push_back(b);
        inc[b].push_back(a);
    }
    ll res = 0;
    bool was[1001] = {0};
    rep(i,0,n)
    {
        int v = Cost[i].second;
        was[v] = 1;
        rep(j,0, inc[v].size())
        if (!was[inc[v][j]])
        {
            res += A[inc[v][j]];
        }
    }
    cout<<res<<endl;
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