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

struct vert
{
    vector<int> inc;
    int a;
    ll d[2];
} g[200200];

void dfs(int k)
{
    g[k].d[0] = 0;
    g[k].d[1] = -1e18;
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        dfs(to);
        ll w[2] = {g[k].d[0], g[k].d[1]};
        g[k].d[0] = max(w[0] + g[to].d[0], w[1] + g[to].d[1]);
        g[k].d[1] = max(w[1] + g[to].d[0], w[0] + g[to].d[1]);
    }
    g[k].d[1] = max(g[k].d[1], g[k].a + g[k].d[0]);
    //cout<<k+1<<' '<<g[k].d[0]<<' '<<g[k].d[1]<<endl;

}

void run()
{
    int n;
    cin>>n;
    int rt = 0;
    rep(i,0,n)
    {
        int p,a;
        scanf("%d%d",&p,&a);
        --p;
        if (p >= 0)
            g[p].inc.push_back(i);
        else
            rt = i;
        g[i].a = a;
    }
    dfs(rt);
    cout<<max(g[rt].d[0], g[rt].d[1]);
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