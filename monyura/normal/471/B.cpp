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


void run()
{
    int n;
    cin>>n;
    pii A[2001];
    rep(i,0,n)
    {
        scanf("%d",&A[i].first);
        A[i].second = i;
    }
    sort(A,A+n);
    vector<pii> V[2];
    rep(i,0,n-1)
        if (A[i].first==A[i+1].first)
            V[0].push_back(pii(i,i+1));
    rep(i,0,n-2)
        if (A[i].first==A[i+1].first && A[i+1].first==A[i+2].first)
            V[1].push_back(pii(i,i+2));
    if (V[0].size()>=2)
    {
        puts("YES");
        rep(i,0,n)
            printf("%d ", A[i].second+1);
        puts("");
        swap(A[V[0][0].first], A[V[0][0].second]);
        rep(i,0,n)
            printf("%d ", A[i].second+1);
        puts("");
        swap(A[V[0][1].first], A[V[0][1].second]);
        rep(i,0,n)
            printf("%d ", A[i].second+1);
        puts("");
        return;
    }
    if (V[1].size()>=1)
    {
        puts("YES");
        rep(t,0,3)
        {
            rep(i,0,n)
                printf("%d ",A[i].second + 1);
            puts("");
            swap(A[V[1][0].first+t],A[V[1][0].first+t+1]);
        }
        return;
    }
    puts("NO");
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