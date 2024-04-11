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

const int mod = 1e9+7;

ll toPow(ll a, ll b)
{
    ll res = 1;
    a %= mod;
    while (b)
    {
        if (b&1)
            res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

int rev[21];

inline int calcC(ll n, int k)
{
    if (k > n || n < 0)
        return 0;
    if (k == n)
        return 1;
    ll res = 1;
    for (ll i = n-k+1;i<=n;i++)
        res = (res * (i % mod)) % mod;
    rep(i,1,k+1)
        res = (res * rev[i]) % mod;
    return res;
}

void run()
{
    rep(i,1,21)
        rev[i] = toPow(i, mod-2);
    int n;
    ll s;
    cin>>n>>s;
    ll F[21];
    ll sum = 0;
    rep(i,0,n)
    {
        cin>>F[i];
        sum += F[i];
    }
    if (sum < s)
    {
        puts("0");
        return;
    }
    ll res = calcC(s+n-1, n-1);
    rep(i,1,1<<n)
    {
        int cnt = 0;
        ll here = 0;
        rep(j,0,n)
            if ((i>>j)&1)
            {
                cnt ++;
                here += F[j];
            }
        ll c = calcC(s - here - cnt + n - 1, n - 1);
        if (cnt & 1)
            res = (res - c) % mod;
        else
            res = (res + c) % mod;
    }
    res = (res % mod + mod)%mod;
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