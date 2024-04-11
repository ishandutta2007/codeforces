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
#include <complex>


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


const double PI = acos(-1.0);

const int SZ = 100100;
int D[4 * SZ];
void add(int v, int l, int r, int pos, int val)
{
    if (l == r)
    {
        D[v] = val;
        return;
    }
    int c = (l+r)/2;
    if (pos <= c)
        add(2*v, l, c, pos, val);
    else
        add(2*v+1,c+1,r,pos,val);
    D[v] = min(D[2*v], D[2*v+1]);
}

int get(int v, int l, int r, int ql, int qr)
{
    if (l == ql && r == qr)
    {
        return D[v];
    }
    int c =  (l+r)/2;
    if (qr <= c)
        return get(2*v, l, c, ql, qr);
    else if ( ql > c)
        return get(2*v+1,c+1,r,ql,qr);
    return min(get(2*v,l,c,ql,c), get(2*v+1,c+1,r,c+1,qr));
}


struct event
{
    int x,y;
    int id;
} E[400400];

bool cmpx(const event &a, const event &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    if (a.y != b.y)
        return a.y < b.y;
    return a.id < b.id;
}

bool cmpy(const event &a, const event &b)
{
    if (a.y != b.y)
        return a.y < b.y;
    if (a.x != b.x)
        return a.x < b.x;
    return a.id < b.id;
}

bool Ok[200200][2] = {0};
pii  C[200200];

void run()
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    rep(i,0,k)
    {
        scanf("%d%d",&E[i].x, &E[i].y);
        --E[i].x; --E[i].y;
        E[i].id = -1;
    }
    rep(i,0,q)
    {
        int eId = k + i;
        scanf("%d%d%d%d",&C[i].first, &C[i].second, &E[eId].x, &E[eId].y);
        --C[i].first;--C[i].second;
        --E[eId].x; --E[eId].y;
        E[eId].id = i;
    }
    int events = k + q;
    
    memset(D,-1,sizeof(D));
    sort(E, E+events, cmpx);
    rep(i, 0, events)
    {
        if (E[i].id == -1)
            add(1,0,m-1,E[i].y, E[i].x);
        else
        {
            int r = E[i].id;
            int v = get(1,0,m-1,C[r].second,E[i].y);
            Ok[r][0] = v >= C[r].first;
        }
    }
    memset(D,-1,sizeof(D));
    sort(E, E+events, cmpy);
    rep(i, 0, events)
    {
        if (E[i].id == -1)
            add(1,0,n-1,E[i].x, E[i].y);
        else
        {
            int r = E[i].id;
            int v = get(1,0,n-1,C[r].first,E[i].x);
            Ok[r][1] = v >= C[r].second;
        }
    }
    rep(i,0,q)
        puts(Ok[i][0] || Ok[i][1] ? "YES" : "NO");
    
}

//#define prob "exam"



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