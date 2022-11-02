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
#include <array>
#include <tuple>
#include <unordered_map>


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


const int SZ = 200100;


struct vert
{
    vector<int> inc;
    vector<ll> pref;
    vector<ll> suff;
    ll d;
    int ans;
    bool was = false;
} g[SZ];

const int mod = 1e9 + 7;

void dfs(int k)
{
    g[k].was = true;
    g[k].d = 1;
    g[k].pref.push_back(1);
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        g[k].pref.push_back(1);
        g[k].suff.push_back(1);
        if (!g[to].was)
        {
            dfs(to);
            g[k].pref.back() = 1 + g[to].d;
            g[k].suff.back() = 1 + g[to].d;
            g[k].d *= (1 + g[to].d);
            g[k].d %= mod;
        }
    }
    g[k].suff.push_back(1);
    rep(i,1,g[k].pref.size())
    {
        g[k].pref[i] *= g[k].pref[i-1];
        g[k].pref[i] %= mod;
    }
    for (int i = (int)g[k].suff.size() - 2; i>=0; i--)
    {
        g[k].suff[i] *= g[k].suff[i+1];
        g[k].suff[i] %= mod;
    }
}

void dfs2(int k, ll uper)
{
    g[k].was = true;
    g[k].ans = g[k].d * (1 + uper) % mod;
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (!g[to].was)
        {
            ll nextUpper = g[k].pref[i] * g[k].suff[i+1] % mod * (1 + uper) % mod;
            dfs2(to, nextUpper);
        }
    }
}

void run()
{
    int n;
    cin>>n;
    rep(i,0,n-1)
    {
        int p;
        scanf("%d",&p);
        --p;
        g[i+1].inc.push_back(p);
        g[p].inc.push_back(i+1);
    }
    int st = 0;
    dfs(st);
    rep(i,0,n)
        g[i].was = false;
    dfs2(st, 0);
    rep(i,0,n)
        printf("%d ", g[i].ans);
    puts("");
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