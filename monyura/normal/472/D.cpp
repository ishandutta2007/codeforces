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
typedef pair<string, string> pss;


vector<pii> inc[2001];
struct elem
{
    int a,b;
    int w;
    elem(int a0, int b0, int w0)
    {
        a = a0;
        b = b0;
        w = w0;
    }
    bool operator<(const elem &b) const
    {
        return w < b.w;
    }
};

int pred[2001];
int getPred(int a)
{
    return a == pred[a] ? a : pred[a] = getPred(pred[a]);
}



void run()
{
    int n;
    cin>>n;
    int D[2001][2001];
    vector<elem> V;
    rep(i,0,n)
        rep(j,0,n)
        {
            scanf("%d",&D[i][j]);
            if (D[i][j] > 0)
                V.push_back(elem(i,j, D[i][j]));
        }
    if (n == 1)
    {
        puts(D[0][0] == 0?"YES":"NO");
        return;
    }
    sort(all(V));
    rep(i,0,n)
        pred[i] = i;
    int edges = 0;
    rep(i,0,V.size())
    {
        int a = getPred(V[i].a);
        int b = getPred(V[i].b);
        if (a != b)
        {
            pred[a] = b;
            inc[V[i].a].push_back(pii(V[i].b,V[i].w));
            inc[V[i].b].push_back(pii(V[i].a,V[i].w));
//            cout<<V[i].a<<' '<<V[i].b<<endl;
            ++edges;
        }
    }
    if (edges != n-1)
    {
        puts("NO");
        return;
    }
    ll A[2001][2001];
    ll INF = 1e18;
    rep(i,0,n)
    {
        rep(j,0,n)
            A[i][j] = INF;
        A[i][i] = 0;
        bool close[2001] = {0};
        priority_queue<pll> pq;
        pq.push(pll(0, i));
        while (!pq.empty())
        {
            int v = pq.top().second;
            pq.pop();
            if (close[v]) continue;
            close[v] = 1;
            rep(j,0,inc[v].size())
            {
                int to = inc[v][j].first;
                int w = inc[v][j].second;
                if (!close[to] && A[i][to] > A[i][v] + w)
                {
                    A[i][to] = A[i][v] + w;
                    pq.push(pll(-A[i][to], to));
                }
            }
        }
        rep(j,0,n)
            if (!close[j])
            {
                puts("NO");
                return;
            }
    }
    rep(i,0,n)
    rep(j,0,n)
    if (A[i][j] != D[i][j])
    {
        puts("NO");
        return;
    }
    puts("YES");
}

//#define prob "fields"


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