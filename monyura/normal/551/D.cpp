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
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c.size())

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;

int mod;
struct mat {
    int arr[2][2];
    mat(int a00, int a01, int a10, int a11) {
        arr[0][0] = a00;
        arr[0][1] = a01;
        arr[1][0] = a10;
        arr[1][1] = a11;
    }
    mat() {
        memset(arr, 0, sizeof(arr));
    }
    mat operator*(const mat &other) const {
        mat res;
        for (int i = 0; i < 2; i++)
            for (int j =0 ; j < 2; j++) {
                ll sum = 0;
                for (int k = 0; k < 2; k++)
                    sum += arr[i][k] * ll(other.arr[k][j]);
                res.arr[i][j] = sum % mod;
            }
        return res;
    }
};;

mat toPow(mat a, ll b)
{
    mat res (1,0,0,1);
    while (b) {
        if (b&1)
            res = res * a;
        a = a * a;
        b>>=1;
    }
    return res;
}

ll toPow(ll a, ll b)
{
    ll res = 1;
    while (b) {
        if (b&1)
            res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}

void run()
{
    ll n, k;
    int l;
    cin>>n>>k>>l>>mod;
    mat f(1,1,1,0);
    auto p = toPow(f, n);
    int no11 = (p.arr[0][0] + p.arr[0][1]) % mod;
    int has11 = ((toPow(2, n) - no11)%mod + mod)%mod;
    int C[2] = {no11, has11};
    ll res = (l >= 63 || k < (1LL<<l)) ? 1 : 0;
    rep(i,0,l)
        res = (res * C[(k>>i)&1])%mod;
    cout<<res%mod<<endl;
    
}



int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen("../" prob ".in","r",stdin);
    freopen("../" prob ".out","w",stdout);
#else
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    time_t st=clock();
#endif
#else
#endif
    run();
#ifdef _MONYURA_
#ifndef prob
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
#endif
    
    return 0;
}