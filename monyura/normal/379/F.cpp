#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif


#include <iostream>
#include <iomanip>
#include <cstdio>
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
    int prev[22];
    int h;
    vert()
    {
        h = 0;
        memset(prev,-1,sizeof(prev));
    }
} g[1000100];

void add(int k, int prev)
{
    g[k].h = g[prev].h + 1;
    g[k].prev[0] = prev;
    rep(j,1,22)
        if ((1<<j) <= g[k].h)
        {
            g[k].prev[j] = g[g[k].prev[j-1]].prev[j-1];
        }
}

int up(int k, int val)
{
    rep(i,0,22)
    if ((val>>i)&1)
        k = g[k].prev[i];
    return k;
}

int getLCA(int a, int b)
{
    if (g[a].h > g[b].h)
        swap(a,b);
    b = up(b, g[b].h - g[a].h);
    if (a == b)
        return a;
    for (int i = 21; i>=0; i--)
    if (g[a].prev[i] != g[b].prev[i])
    {
        a = g[a].prev[i];
        b = g[b].prev[i];
    }
    return g[a].prev[0];
}

int getDist(int a,int b)
{
    int lca = getLCA(a,b);
    return -g[lca].h + g[a].h - g[lca].h + g[b].h;
}

int c1 = 0, c2;
bool two = false;
int dist = 1;

void update(int to, int k)
{
    add(k,to);
    if (!two)
    {
        if (getDist(k,c1)>dist)
        {
            int anc = getLCA(k,c1);
            if (g[anc].h < g[c1].h)
                c2 = g[c1].prev[0];
            else
                c2 = up(k, g[k].h - g[c1].h - 1);
            two = 1;
        }
    }
    else
    {
        int d1 = getDist(k,c1);
        int d2 = getDist(k,c2);
        if (min(d1,d2)>dist)
        {
            if (d2 < d1)
                c1 = c2;
            two = 0;
            dist++;
        }
    }
}



void run()
{
    int q;
    add(1,0);
    add(2,0);
    add(3,0);
    int n = 4;
    cin>>q;
    rep(i,0,q)
    {
        int v;
        scanf("%d",&v);
        --v;
        update(v,n++);
        update(v,n++);
        printf("%d\n",2*dist + two);
    }
}

//#define prob "kids"

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
    printf("\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}