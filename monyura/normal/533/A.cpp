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

const int SZ = 500500;
struct vert
{
    vector<int> inc;
    vector<pii> vec;
    bool was = false;
    int h;
    int currH;
} g[SZ];

inline void updatePair(pair<pii, pii> &arr, const pii &p)
{
    if (p.first < arr.first.first)
    {
        arr.second = arr.first;
        arr.first = p;
        return;
    }
    if (p.first < arr.second.first)
        arr.second = p;
}

void dfs(int k, pair<pii, pii> mn)
{
    updatePair(mn, pii(g[k].h, k));
    g[k].was = true;
    rep(i,0,g[k].inc.size())
    {
        int to = g[k].inc[i];
        if (!g[to].was)
            dfs(to, mn);
    }
    int mx = mn.second.first;
    g[k].h = g[k].currH = mn.first.first;
    g[mn.first.second].vec.push_back(pii(mx, k));
    //fprintf(stderr, "%d) h = %d v = %d mx = %d\n",k+1, g[k].h,  mn.first.second+1, mx);
}

int D[4 * SZ];
int Add[4 * SZ];
int A[SZ];

void build(int v, int l, int r)
{
    Add[v] = 0;
    if (l == r)
    {
        D[v] = A[l];
        return;
    }
    int c = (l + r)/2;
    build(2*v, l, c);
    build(2*v+1,c+1,r);
    D[v] = min(D[2*v], D[2*v+1]);
}

void addVal(int v, int l, int r, int ql, int qr, int val)
{
    if (ql > qr) return;
    if (l == ql && r == qr)
    {
        Add[v] += val;
        D[v] += val;
        return;
    }
    int c = (l+r)/2;
    if (qr<=c)
        addVal(2*v,l,c,ql,qr,val);
    else if (ql>c)
        addVal(2*v+1,c+1,r,ql,qr,val);
    else
    {
        addVal(2*v,l,c,ql,c,val);
        addVal(2*v+1,c+1,r,c+1,qr,val);
    }
    D[v] = min(D[2*v], D[2*v+1]) + Add[v];
}

int getVal(int v, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
        return D[v];
    int c = (l+r)/2;
    if (qr<=c)
        return getVal(2*v,l,c,ql,qr) + Add[v];
    if (ql > c)
        return getVal(2*v+1,c+1,r,ql,qr) + Add[v];
    return min(getVal(2*v,l,c,ql,c), getVal(2*v+1,c+1,r,c+1,qr)) + Add[v];
}

int getMaxNeg(int v, int l, int r, int add)
{
    if (l == r)
        return l;
    int c = (l+r)/2;
    if (D[2*v + 1] + Add[v] + add >= 0)
        return getMaxNeg(2*v, l, c, add + Add[v]);
    return getMaxNeg(2*v+1,c+1,r, add + Add[v]);
}


int getPosInSt(int* S,int  m, int val)
{
    return upper_bound(S, S + m, val) - S - 1;
}

int S[SZ];


const int INF = 1e9 + 100;

void run()
{
    int n;
    cin>>n;
    rep(i,0,n)
    {
        scanf("%d",&g[i].h);
    }
    rep(i,0,n-1)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        --a;--b;
        g[a].inc.push_back(b);
        g[b].inc.push_back(a);
    }
    
    int m;
    cin>>m;
    rep(i,0,m)
    scanf("%d", S + i);
    sort(S, S + m);
    
    pair<pii, pii> mn(pii(INF, 0), pii(INF, 0));
    dfs(0, mn);
    rep(i,0,n)
        sort(all(g[i].vec));
    
    rep(i, 0, m)
        A[i] = -m + i;
    build(1,0,m-1);
    rep(i, 0, n)
    {
        int pos = getPosInSt(S, m, g[i].currH);
        if (pos == -1)
            continue;
        addVal(1,0,m-1, 0, pos, 1);
    }
    
    if (getVal(1,0,m-1,0,m-1) >= 0)
    {
        puts("0");
        return;
    }
    
    //    rep(k,0,m)
    //    fprintf(stderr, "%d ",getVal(1, 0, m-1, k, k));
    //    fprintf(stderr, "\n");
    
    int res = INF;
    rep(i,0,n)
    {
        rep(j,0,g[i].vec.size())
        {
            int val = g[i].vec[j].first;
            int maxNegPos = getMaxNeg(1, 0, m-1, 0);
            
//            rep(k,0,m)
//                fprintf(stderr, "%d ",getVal(1, 0, m-1, k, k));
//            fprintf(stderr, "\n%d\n",maxNegPos);

            val = min(val, S[maxNegPos]);
            val = max(val, g[i].currH);
            int v = g[i].vec[j].second;
            int add = 1;
            if (v != i)
            {
                int posCurr = getPosInSt(S, m, g[i].currH);
                addVal(1, 0, m-1, 0, posCurr, -1);
                g[i].currH = val;
                add = 2;
            }
            int posV = getPosInSt(S, m, g[v].currH);
            addVal(1, 0, m-1, 0, posV, -1);
            
            g[v].currH = val;
            int posNew  = getPosInSt(S, m, g[v].currH);
            addVal(1, 0, m-1, 0, posNew, add);
            
            int mn = getVal(1, 0, m-1, 0, m-1);
            if (mn >= 0)
                res = min(res, g[i].currH - g[i].h);
            
        }
        rep(j,0,g[i].vec.size())
        {
            int v = g[i].vec[j].second;
            int posCurr = getPosInSt(S, m, g[v].currH);
            addVal(1, 0, m-1, 0, posCurr, -1);
            g[v].currH = g[v].h;
            int posNew  = getPosInSt(S, m, g[v].currH);
            addVal(1, 0, m-1, 0, posNew, 1);
        }
    }
    if (res == INF)
        res = -1;
    cout<<res<<endl;
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