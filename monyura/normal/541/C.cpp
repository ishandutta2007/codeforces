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

int check(int f[201], int n)
{
    int h[201];
    rep(i,0,n)
    h[i] = f[i];
    for (int i = 0; ;i++)
    {
        bool ok = 1;
        rep(j,0,n)
        ok &= h[h[j]] == h[j];
        if (ok)
        {
            return i + 1;
        }
        int t[201];
        rep(j,0,n)
        t[j] = f[h[j]];
        rep(j,0,n)
        h[j] = t[j];
    }
}

ll gcd(ll a, ll b)
{
    while (b)
    {
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}

ll nok(ll a, ll b)
{
    return a/gcd(a,b) * b;
}

bool inCicle[201] = {0};
int cicleInd[201] = {0};
int cicleLen[201] = {0};
int was[201] = {0};
int f[201];
int d[201];

vector<int> vec;
ll nk = 1;
int cicles = 0;
void dfs(int k)
{
    vec.push_back(k);
    was[k] = 1;
    if (was[f[k]] == 1)
    {
        cicleLen[cicles] = d[k] - d[f[k]] + 1;
        for (int i = (int)vec.size() - 1; ;i--)
        {
            inCicle[vec[i]] = 1;
            cicleInd[vec[i]] = cicles;
            if (vec[i] == f[k])
                break;
        }
        ++cicles;
    }
    d[f[k]] = d[k] + 1;
    if (was[f[k]] == 0)
        dfs(f[k]);
    vec.pop_back();
    was[k] = 2;
}

int maxLen[201];

void dfs2(int k)
{
    if (inCicle[k])
        return;
    dfs2(f[k]);
    maxLen[k] = maxLen[f[k]] + 1;
    cicleInd[k] = cicleInd[f[k]];
}

void run()
{

    int n;
    cin>>n;
    srand(0);
    rep(i,0,n)
    {
//        f[i] = rand() % 100 + 1;
        scanf("%d", f + i);
        --f[i];
    }
    rep(i,0,n)
        if (!was[i])
            dfs(i);
    rep(i,0,n)
        dfs2(i);
    //
//    cout<<cicles<<endl;
    //
    ll nk = 1;
    rep(i, 0, cicles)
        nk = nok(nk, cicleLen[i]);
    ll res = nk;
    rep(i,0,n)
    {
        int clen = cicleLen[cicleInd[i]];
        int need = (maxLen[i] + clen - 1)/ clen;
        while (res / clen < need)
            res += nk;
    }
    cout<<res<<endl;
//    cout<<check(f,n)<<endl;
    
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