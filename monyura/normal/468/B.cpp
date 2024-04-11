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
    set<int> st[2];
    int n,a,b;
    cin>>n>>a>>b;
    int A[100100];
    rep(i,0,n)
    {
        scanf("%d",A+i);
        st[0].insert(A[i]);
    }
    rep(i,0,n)
    {
        if (st[0].find(A[i]) != st[0].end() && st[0].find(a - A[i]) == st[0].end())
        {
            st[0].erase(A[i]);
            st[1].insert(A[i]);
        }
    }
    queue<int> q;
    rep(i,0,n)
        if (st[1].find(A[i]) != st[1].end() && st[1].find(b - A[i]) == st[1].end())
            q.push(A[i]);
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (st[1].find(b - v) != st[1].end())
            continue;
        if (st[0].find(b - v) != st[0].end())
        {
            st[0].erase(b - v);
            st[0].erase(a - b + v);
            st[1].insert(b - v);
            st[1].insert(a - b + v);
            q.push(b - v);
            q.push(a - b + v);
        }
        else
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
    rep(i,0,n)
        printf("%d ",1 - (int)(st[0].find(A[i]) != st[0].end()));
    puts("");
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