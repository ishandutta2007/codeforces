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

const int SZ = 1200200 * 4;

pii D[SZ];

void setVal(int v, int l, int r, int pos, const pii &val)
{
    if (l == r)
    {
        D[v] = val;
        return;
    }
    int c = (l+r)/2;
    if (pos<=c)
        setVal(2*v,l,c,pos,val);
    else
        setVal(2*v+1,c+1,r,pos,val);
    D[v] = max(D[2*v], D[2*v+1]);
}


pii getVal(int v, int l, int r, int ql ,int qr)
{
    if (l == ql && r == qr)
    {
        return D[v];
    }
    int c = (l+r)/2;
    if (qr<=c)
        return getVal(2*v,l,c,ql,qr);
    else if (ql>c)
        return getVal(2*v+1,c+1,r,ql,qr);
    else
        return max(getVal(2*v,l,c,ql,c), getVal(2*v+1,c+1,r,c+1,qr));
}


struct Event
{
    int type;
    int a,b;
    int ind;
    bool operator<(const Event &other) const
    {
        if (b != other.b)
            return b < other.b;
        return type < other.type;
    }
} E[800400];
int ecnt = 0;

int A[1200200];
int acnt = 0;
inline int getPos(int val)
{
    return lower_bound(A, A + acnt, val) - A;
}

ll res = 0;
pii ans;

void solve(bool shouldUseDO)
{
    acnt = 0;
    rep(i,0,ecnt)
    {
        A[acnt++] = E[i].a;
        A[acnt++] = E[i].b;
    }
    sort(A,A + acnt);
    sort(E,E + ecnt);
    memset(D,0,sizeof(D));
    set<pii> ms;
    rep(i,0,ecnt)
    {
        if (E[i].type == -1)
            ms.insert({E[i].b, E[i].ind});
        else if (E[i].type == 0)
        {
            if (shouldUseDO)
                setVal(1,0,acnt-1, getPos(E[i].a), {E[i].b - E[i].a + 1, E[i].ind});
            ms.erase({E[i].a, E[i].ind});
        }
        else
        {
            ll cost = E[i].type;
            if (shouldUseDO)
            {
                pii maxCover = getVal(1,0,acnt-1, getPos(E[i].a), getPos(E[i].b));
                ll here = cost * maxCover.first;
                if (here > res)
                {
                    res = here;
                    ans = {E[i].ind, maxCover.second};
                }
            }
            if (!ms.empty())
            {
                auto p = *ms.begin();
                ll notEnd = E[i].b - max(p.first, E[i].a) + 1;
                ll here   = cost * notEnd;
                if (here > res)
                {
                    res = here;
                    ans = {E[i].ind, p.second};
                }
            }
        }
    }
}

void run()
{
    int n,m;
    cin>>n>>m;
    ecnt = 0;
    rep(i,0,n)
    {
        int a,b;
        scanf("%d%d",&a,&b);
//        a = rand(); b = a + rand() % 1000 + 1;
        --b;
        if (a <= b)
        {
            E[ecnt++] = {-1, b, a, i};
            E[ecnt++] = {0, a, b, i};
        }
    }
    rep(i,0,m)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
//        a = rand(); b = a + rand() % 1000 + 1;
        --b;
        if (a <= b)
        {
            E[ecnt++] = {c, a, b, i};
        }
    }
    solve(true);
    rep(i,0,ecnt)
    {
        swap(E[i].a, E[i].b);
        E[i].a = -E[i].a;
        E[i].b = -E[i].b;
    }
    solve(false);
    cout<<res<<endl;
    if (res > 0)
    {
        cout<<ans.second + 1 <<' '<<ans.first + 1<<endl;
    }
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