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

const int mod = 1e9 + 9;
const int SZ = 300300;
struct mat
{
    ll A[2][2];
    mat(int a = 0, int b = 0, int c= 0, int d = 0)
    {
        A[0][0] = a;
        A[0][1] = b;
        A[1][0] = c;
        A[1][1] = d;
    }
    mat operator*(const mat &other) const
    {
        mat res;
        rep(i,0,2)
        rep(j,0,2)
        {
            rep(k,0,2)
                res.A[i][j]+= A[i][k] * other.A[k][j];
            res.A[i][j] %= mod;
        }
        return res;
    }
    mat operator+(const mat &other) const
    {
        mat res;
        rep(i,0,2)
        rep(j,0,2)
        {
            res.A[i][j] = A[i][j] + other.A[i][j];
            res.A[i][j] %= mod;
        }
        return res;
    }
    mat operator-(const mat &other) const
    {
        mat res;
        rep(i,0,2)
        rep(j,0,2)
        {
            res.A[i][j] = A[i][j] - other.A[i][j];
            res.A[i][j] %= mod;
        }
        return res;
    }
};
mat Fib(1,1,1,0);
mat EminusArev(-1,-1,-1,0);
mat Step[SZ];

ll Sum[4*SZ];
mat M[4*SZ];
int A[SZ];

void build(int v, int l, int r)
{
    if (l == r)
    {
        Sum[v] = A[l];
        return;
    }
    int c = (l+r)/2;
    build(2*v, l, c);
    build(2*v+1,c+1,r);
    Sum[v] = (Sum[2*v] + Sum[2*v+1])%mod;
}

inline mat sumUp(int a, int b)
{
    mat res = EminusArev * (Step[0] - Step[b-a+1]);
    return Step[a] * res;
}

void add(int v, int l, int r, int ql, int qr, int st)
{
    Sum[v] = (Sum[v] + sumUp(ql-st, qr-st).A[0][0]) % mod;
    if (l==ql && r==qr)
    {
        M[v] = M[v] + Step[ql - st];
        return;
    }
    int c = (l+r)/2;
    if (qr<=c)
        add(2*v,l,c,ql,qr,st);
    else if (ql>c)
        add(2*v+1,c+1,r,ql,qr,st);
    else
    {
        add(2*v,l,c,ql,c,st);
        add(2*v+1,c+1,r,c+1,qr,st);
    }
}

ll getSum(int v, int l, int r, int ql, int qr)
{
    if (l==ql && r ==qr)
    {
        return Sum[v];
    }
    int c = (l+r)/2;
    ll res = 0;
    if (qr<=c)
        res = getSum(2*v,l,c,ql,qr);
    else if (ql>c)
        res = getSum(2*v+1,c+1,r, ql,qr);
    else
        res = getSum(2*v, l, c, ql, c) + getSum(2*v+1, c+1,r,c+1,qr);
    return (res + (M[v] * sumUp(ql-l, qr-l)).A[0][0])%mod;
}


void run()
{
    Step[0] = mat(1,0,0,1);
    rep(i,1,SZ)
        Step[i] = Step[i-1] * Fib;
//    rep(i,0,5)
//    rep(j,i,5)
//    {
//        cout<<i<<' '<<j<<' ';
//        cout<<sumUp(i, j).A[0][0]<<endl;
//    }
    int n,m;
    cin>>n>>m;
    rep(i,0,n)
        scanf("%d",A+i);
    build(1,0,n-1);
    rep(i,0,m)
    {
        int t,a,b;
        scanf("%d%d%d",&t,&a,&b);
        --a;--b;
        if (t == 1)
        {
            add(1,0,n-1,a,b,a);
//            rep(j,0,n)
//            {
//                int v = getSum(1, 0, n-1, j,j);
//                printf("%d ", v);
//            }
//            puts("");
        }
        else
        {
            int res = getSum(1, 0, n-1, a, b);
            res = (res + mod)%mod;
            printf("%d\n", res);
        }
    }
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