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

struct vert
{
    vector<int> inc;
} g[3001];;

int Dist[3001][3001];

void bfs(int st)
{
    memset(Dist[st], -1, sizeof(int)*3001);
    queue<int> q;
    q.push(st);
    Dist[st][st] = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        rep(i,0,g[v].inc.size())
        {
            int to = g[v].inc[i];
            if (Dist[st][to] == -1)
            {
                Dist[st][to] = Dist[st][v] + 1;
                q.push(to);
            }
        }
    }
}

void run()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        g[a].inc.push_back(b);
        g[b].inc.push_back(a);
    }
    rep(i,0,n)
        bfs(i);
    int s1,t1,l1, s2,t2,l2;
    cin>>s1>>t1>>l1>>s2>>t2>>l2;
    --s1;--t1;
    --s2;--t2;
    if (Dist[s1][t1] > l1 || Dist[s2][t2] > l2)
    {
        cout<<-1<<endl;
        return;
    }
    int res = Dist[s1][t1] + Dist[s2][t2];
    rep(a,0,n)
    rep(b,0,n)
    {
        {
            int len1 = Dist[s1][a] + Dist[a][b] + Dist[b][t1];
            int len2 = Dist[s2][a] + Dist[a][b] + Dist[b][t2];
            if (len1 <= l1 && len2 <= l2)
                res = min(res, len1 + len2 - Dist[a][b]);
        }
        {
            int len1 = Dist[s1][a] + Dist[a][b] + Dist[b][t1];
            int len2 = Dist[t2][a] + Dist[a][b] + Dist[b][s2];
            if (len1 <= l1 && len2 <= l2)
                res = min(res, len1 + len2 - Dist[a][b]);
        }
    }
    cout<< m - res<<endl;
    
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