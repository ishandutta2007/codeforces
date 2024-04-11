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
typedef pair<double, double> pdd;

void build(int *A, int n, ll *Res, int k, int otn)
{
    priority_queue<ll> q;
    rep(i,0,n)
        q.push(A[i]);
    Res[0] = 0;
    rep(i,0,k)
    {
        Res[i+1] = q.top();
        q.pop();
        q.push(Res[i+1] - otn);
        Res[i+1] += Res[i];
    }
}

ll rowSum[1000100], colSum[1000100];

void run()
{
    int n,m,k,p;
    cin>>n>>m>>k>>p;
    int A[1001][1001];
    rep(i,0,n)
        rep(j,0,m)
            scanf("%d",&A[i][j]);
    int Rows[1001] = {0}, Cols[1001] = {0};
    rep(i,0,n)
    {
        rep(j,0,m)
        {
            Rows[i] += A[i][j];
            Cols[j] += A[i][j];
        }
    }
    build(Rows, n, rowSum, k, p*m);
    build(Cols, m, colSum, k, p*n);
    ll res;
    rep(i,0,k+1)
    {
        ll r = rowSum[i];
        ll c = colSum[k-i];
        ll here = r + c - p *ll(i) * (k-i);
        if (i == 0)
            res = here;
        res = max(res, here);
    }
    cout<<res<<endl;
}


//#define prob "path"


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