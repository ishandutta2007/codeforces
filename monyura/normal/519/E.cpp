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
    int pred[19];
    int h = 0;
    int size = 1;
 } g[100100];

void dfs(int k, int pred)
{
    g[k].pred[0] = pred;
    rep(i,1,19)
        if ((1<<i) <= g[k].h)
            g[k].pred[i] = g[g[k].pred[i-1]].pred[i-1];
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (to != pred)
        {
            g[to].h = g[k].h + 1;
            dfs(to, k);
            g[k].size += g[to].size;
        }
    }
}

int up(int k, int val)
{
    rep(i,0,19)
        if ((val>>i)&1)
            k = g[k].pred[i];
    return k;
}

int lca(int a, int b)
{
    if (g[a].h < g[b].h)
        swap(a, b);
    a = up(a, g[a].h - g[b].h);
    if (a == b)
        return a;
    for (int i = 18; i>=0; i--)
        if (g[a].pred[i] != g[b].pred[i])
        {
            a = g[a].pred[i];
            b = g[b].pred[i];
        }
    return g[a].pred[0];
}


void run()
{
    int n;
    cin>>n;
    rep(i,0,n-1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        g[a].inc.push_back(b);
        g[b].inc.push_back(a);
    }
    const int st = 0;
    dfs(st, -1);
    int m;
    cin>>m;
    rep(i,0,m)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        --x; --y;
        int res = 0;
        if (x == y)
            res = n;
        else
        {
            int l = lca(x, y);
            if (g[x].h > g[y].h)
                swap(x, y);
            int hx = g[x].h - g[l].h;
            int hy = g[y].h - g[l].h;
            if ((hx + hy)&1)
                res = 0;
            else
            {
                int midleh = (hx + hy)/2;
                int p = up(y, midleh);
                if (p == l)
                {
                    int nx = up(x, midleh - 1);
                    int ny = up(y, midleh - 1);
                    res = n - g[nx].size - g[ny].size;
                }
                else
                {
                    int ny = up(y, midleh - 1);
                    res = g[p].size - g[ny].size;
                }
            }
        }
        printf("%d\n", res);
    }
}

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