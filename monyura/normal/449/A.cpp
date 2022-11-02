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

ll f(ll n , ll m, ll k, ll x)
{
    return (n/(x+1)) * (m/(k-x+1));
}

ll getRes(ll n, ll m, ll k)
{
    if (n-1 + m-1  < k)
        return -1;
    ll l = max(0LL, k-m+1), r = min(k, n-1);
    ll res = f(n,m,k,l);
    res = max(res, f(n,m,k,r));
    while (r - l >=3)
    {
        ll nl = l  + (r-l)/3;
        ll nr = r - (r-l)/3;
        ll fl = f(n,m,k,nl);
        ll fr = f(n,m,k,nr);
        if (fl < fr)
            l = nl;
        else
            r = nr;
    }
    for (ll i = l; i<=r; i++)
        res = max(res, f(n,m,k,i));
    return res;
}

ll bf(ll n, ll m, ll k)
{
    if (n-1+m-1 < k)
        return -1;
    ll res = -1;
    rep(i,0,min(k+1,n))
    {
        ll here = f(n,m,k,i);
        //cout<<here<<' ';
        res = max(res, here );
    }
    return res;
}

void run()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll res = getRes(n,m,k);
    cout<<res<<endl;
//    rep(n,1,100)
//    rep(m,1,100)
//    rep(k,1,200)
//    {
//        ll my = getRes(n, m, k);
//        ll real = bf(n, m, k);
//        if (my != real)
//        {
//            cout<<n<<' '<<m<<' '<<k<<endl;
//            cout<<my<<" "<<real<<endl;
//            cout<<"fail"<<endl;
//            exit(0);
//        }
//    }
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