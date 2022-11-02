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


struct vert
{
    vector<int> inc;
    vector<ll> suff;
    vector<ll> pref;
    ll d[2];
    ll total;
    int col;
} g[100100];

const int mod = 1e9+7;


ll ans = 1;
void dfs(int k, int pred)
{
    g[k].d[0] = 1;
    g[k].pref.assign(g[k].inc.size(), 0);
    g[k].suff.assign(g[k].inc.size(), 0);
    ll prev = 1;
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        g[k].pref[i] = prev;
        if (to != pred)
        {
            dfs(to, k);
            g[to].total = (g[to].d[0] + g[to].d[1]) % mod;
            g[k].d[0]  = (g[k].d[0] * g[to].total) % mod;
            prev = (prev * g[to].total) % mod;
        }
        
    }
    prev = 1;
    for (int i = (int)g[k].inc.size() - 1 ;i>=0; i--)
    {
        int to = g[k].inc[i];
        g[k].suff[i] = prev;
        if (to != pred)
        {
            prev = (prev * g[to].total) % mod;
        }
    }
    g[k].d[1] = 0;
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (to != pred)
        {
            g[k].d[1] = (g[k].d[1] + g[k].suff[i] * g[k].pref[i] % mod * g[to].d[1]) % mod;
        }
    }
    if (g[k].col == 1)
    {
        ans = (ans * g[k].d[0]) % mod;
        g[k].d[0] = 0;
        g[k].d[1] = 1;
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
        g[p].inc.push_back(i+1);
        g[i+1].inc.push_back(p);
    }
    int blackId = -1;
    rep(i,0,n)
    {
        scanf("%d",&g[i].col);
        if (g[i].col)
            blackId = i;
    }
    dfs(blackId, -1);
//    rep(i,0,n)
//    cout<<i<<") "<<g[i].d[0]<<' '<<g[i].d[1]<<endl;
    cout<<ans<<endl;
    
 
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