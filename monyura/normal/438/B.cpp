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


const int SZ = 100100;
int pred[SZ];
int sz[SZ] = {0};

int getPred(int a)
{
    return a== pred[a] ? a : pred[a] = getPred(pred[a]);
}

void uni(int a, int b)
{
    int pra = getPred(a);
    int prb = getPred(b);
    if (pra != prb)
    {
        sz[prb] += sz[pra];
        pred[pra] = prb;
    }
}

vector<int> inc[SZ];

void run()
{
    int n,m;
    cin>>n>>m;
    int Cnt[SZ];
    rep(i,0,n)
        scanf("%d", Cnt+i);
    rep(i,0,m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        inc[a].push_back(b);
        inc[b].push_back(a);
    }
    pii V[SZ];
    rep(i,0,n)
    {
        V[i] = pii(Cnt[i], i);
        pred[i] = i;
        sz[i] = 1;
    }
    sort(V,V+n,greater<pii>());
    ll res = 0;
    rep(i,0,n)
    {
        int v = V[i].second;
        ll sum = 0,  sqSum = 0;
        ll wasSize = sz[getPred(v)];
        rep(j,0,inc[v].size())
        {
            int to = inc[v][j];
            if (Cnt[to] >= Cnt[v])
            {
                if (getPred(v) != getPred(to))
                {
                    ll nxtSz = sz[getPred(to)];
                    sum += nxtSz;
                    sqSum += nxtSz * ll(nxtSz);
                    uni(v, to);
                }
            }
        }
        res += (sum * sum  - sqSum + 2*sum*wasSize) * Cnt[v];
    }
    double ans = res/(double(ll(n)*(n-1)));
    printf("%.12lf\n", ans);
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