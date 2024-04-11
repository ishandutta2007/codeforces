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

struct vert
{
    vector<int> inc;
    int pred[20];
    int h;
    vert()
    {
        h = 0;
    }
} g[100100];

void dfs(int k, int prev)
{
    if (prev != -1)
    {
        g[k].pred[0] = prev;
        rep(i,1,20)
        {
            if ((1<<i) <= g[k].h)
                g[k].pred[i] = g[g[k].pred[i-1]].pred[i-1];
        }
    }
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (to != prev)
        {
            g[to].h = g[k].h + 1;
            dfs(to, k);
        }
    }
}

int lca(int a, int b)
{
    if (g[a].h < g[b].h)
        swap(a,b);
    int diff = g[a].h - g[b].h;
    rep(i,0,20)
    if ((diff>>i)&1)
    {
        a = g[a].pred[i];
    }
    if (a == b)
        return a;
    for (int i = 19; i>=0; i--)
        if ((1<<i)<=g[a].h && g[a].pred[i] != g[b].pred[i])
        {
            a = g[a].pred[i];
            b = g[b].pred[i];
        }
    a = g[a].pred[0];
    return a;
}

bool canGo(ll x0, ll y0, ll x1, ll y1, ll xp, ll yp)
{
    ll dy = y1 - y0;
    ll dx = x1 - x0;
    ll py = yp - y0;
    ll px = xp - x0;
    return dy * px > dx * py;
}

int pred[100100];
void run()
{
    int n;
    scanf("%d",&n);
    ll X[100100], Y[100100];
    memset(pred,-1,sizeof(pred));
    rep(i,0,n)
    {
        scanf("%lld%lld",X+i,Y+i);
    }
    for (int i = n-2; i>=0; i--)
    {
        int v = i + 1;
        while (pred[v] != -1)
        {
            int pr = pred[v];
            if (canGo(X[i], Y[i], X[pr], Y[pr], X[v], Y[v]))
                v = pr;
            else
                break;
        }
        pred[i] = v;
    }
    rep(i,0,n)
    {
        int a = i;
        int b = pred[i];
        if (a!=-1 && b!=-1)
        {
            g[a].inc.push_back(b);
            g[b].inc.push_back(a);
        }
     //   cout<<a<<' '<<b<<endl;
    }
    dfs(n-1, -1);
    int q;
    scanf("%d",&q);
    rep(i,0,q)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        int res = lca(a,b);
        printf("%d ",res+1);
    }
    puts("");
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