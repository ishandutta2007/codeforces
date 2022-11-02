#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <iomanip>
#include <cstdio>
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

int Cnt[1000100][26]={0};

void run()
{
    ll n,m;
    cin>>n>>m;
    char S[1000100], T[1000100];
    scanf("%s%s",S,T);
    ll lena = strlen(S), lenb = strlen(T);
    char *A = S, *B = T;
    if (lena > lenb)
    {
        swap(n,m);
        swap(lena,lenb);
        swap(A,B);
    }
    ll g = gcd(lena,lenb);
    for (int i = 0; i < g; i++)
        for (int j = i; j<lenb; j+=g)
            Cnt[i][B[j]-'a']++;
    ll res = 0;
    ll total = lenb/g;
    rep(i,0,lena)
    {
        res += total - Cnt[i % g][A[i]-'a'];
    }
    ll nok = lena /g * lenb;
    res *= lena * n / nok;
    cout<<res<<endl;
}


int main()
{
#ifdef _MONYURA_
    //freopen("test.in","r",stdin);
    //freopen("test.out","w",stdout);
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