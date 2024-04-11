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

const int mod = 1e9 + 7;

ll toPow(ll a, int b)
{
    ll res = 1;
    while (b)
    {
        if (b&1)
            res = (res*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return res;
}


void run()
{
    char str[100100];
    scanf("%s",str);
    int vcnt = 0;
    int n = strlen(str);
    reverse(str, str+n);
    vector<pii> V[10];
    vector<pii> A[100100];
    int Len[100100];
    A[0].resize(n);
    Len[0] = n;
    rep(i,0,n)
    {
        A[0][i] = pii(0, str[i]-'0');
        V[str[i]-'0'].push_back(pii(0,i));
    }
    int q;
    cin>>q;
    char S[100100];
    rep(i,0,q)
    {
        char d;
        scanf("%s",S);
        d = S[0];
        char *str = S+3;
        Len[i+1] = strlen(str);
        reverse(str, str+Len[i+1]);
        A[i+1].resize(Len[i+1]);
        rep(j,0,Len[i+1])
            A[i+1][j] = pii(0, str[j] - '0');
        d-='0';
        rep(j,0,V[d].size())
        {
            pii p = V[d][j];
            A[p.first][p.second] = pii(1, i+1);
        }
        V[d].clear();
        rep(j,0,Len[i+1])
                V[str[j]-'0'].push_back(pii(i+1,j));
    }
    int Val[100100] = {0};
    int Cnt[100100] = {0};
    for (int i = q;i>=0;i--)
    {
        ll less = 0;
        ll sum = 0;
        rep(j,0,Len[i])
        {
            ll nxt = A[i][j].first == 0 ? A[i][j].second : Val[A[i][j].second];
            sum = (sum + toPow(10, less) * nxt) % mod;
            ll cnt = A[i][j].first == 0 ? 1 : Cnt[A[i][j].second];
            less = (less + cnt) % (mod - 1);
        }
        Val[i] = sum;
        Cnt[i] = less;
    }
    cout<<Val[0]<<endl;
}

//#define prob "fields"


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