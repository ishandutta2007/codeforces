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


char A[1001][100];

struct edge
{
    int a,b;
    int cost;
    bool operator<(const edge &other) const
    {
        return cost < other.cost;
    }
    edge(){}
    edge(int a0, int b0, int c0)
    {
        a= a0;
        b= b0;
        cost = c0;
    }
} E[1000100];
int ecnt = 0;

int pred[1002];

int getPred(int a)
{
    return pred[a] == a ? a : pred[a] = getPred(pred[a]);
}

struct vert
{
    vector<int> inc;
    bool was;
    vert()
    {
        was = false;
    }
} g[1001];

void dfs(int k, int pred)
{
    g[k].was = true;
    printf("%d %d\n", k+1, pred+1);
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (!g[to].was)
            dfs(to, k);
    }
    
}

void run()
{
    int n,m,k,w;
    cin>>n>>m>>k>>w;
    cin.get();
    rep(i,0,k)
        rep(j,0,n)
            gets(A[i]+j*m);
    int tot = n*m;
    rep(i,0,k)
    {
        rep(j,i+1,k)
        {
            int diff = 0;
            rep(g,0,tot)
                diff += A[i][g] != A[j][g];
            if (diff * w < tot)
                E[ecnt++] = edge(i,j,diff*w);
        }
    }
    sort(E,E+ecnt);
    int From[1001];
    rep(i,0,k)
    {
        pred[i] = i;
        From[i] = -1;
    }
    int res = 0;
    int cnt = k;
    rep(i,0,ecnt)
    {
        int pra = getPred(E[i].a);
        int prb = getPred(E[i].b);
        if (pra != prb)
        {
            g[E[i].a].inc.push_back(E[i].b);
            g[E[i].b].inc.push_back(E[i].a);
            pred[pra] = prb;
            --cnt;
            res += E[i].cost;
        }
    }
    res += cnt * tot;
    printf("%d\n",res);
    rep(i,0,k)
    if (!g[i].was)
        dfs(i,-1);
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