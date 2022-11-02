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

int getCnt(vector<pii> V[2], int st, int x)
{
    bool used[2][2002]={0};
    int res = 0;
    while (1)
    {
        int mx = -1;
        rep(i,0,V[st].size())
        if (!used[st][i] && V[st][i].first <= x && (mx==-1 || V[st][i].second > V[st][mx].second))
            mx = i;
        if (mx == -1)
            break;
        used[st][mx] = 1;
        x += V[st][mx].second;
        st ^= 1;
        ++res;
    }
    return res;
}

void run()
{
    int n,x;
    cin>>n>>x;
    vector<pii> V[2];
    rep(i,0,n)
    {
        int t,h,m;
        scanf("%d%d%d",&t,&h,&m);
        V[t].push_back(pii(h,m));
    }
    int r1 = getCnt(V,0,x);
    int r2 = getCnt(V,1,x);
    int res = max(r1,r2);
    cout<<res<<endl;
}


//#define prob "D-small-attempt1"


int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#else
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
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