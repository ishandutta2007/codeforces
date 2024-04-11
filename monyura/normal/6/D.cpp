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

vector<int> best(1000);
int A[10];
int a,b;
vector<int> moves;

void rec(int pos, int total, int sumLeft)
{
    if (moves.size() >= best.size())
        return;
    if (pos == total)
    {
        if (*max_element(A, A+total) == 0)
        {
            if (moves.size() < best.size())
                best = moves;
        }
        return;
    }
    int v = pos;
    rec(pos+1,total, sumLeft);
    int mx = max((A[v-1]+b-1)/b, max((A[v]+a-1)/a, (A[v+1]+b-1)/b));
    int was[3] = {A[v-1], A[v], A[v+1]};
    rep(i,0,mx)
    {
        sumLeft -= max(A[v]-a, 0);
        sumLeft -= max(A[v-1] - b, 0);
        sumLeft -= max(A[v+1] - b , 0);
        A[v] = max(A[v]-a, 0);
        A[v-1] = max(A[v-1]-b, 0);
        A[v+1] = max(A[v+1]-b, 0);
        moves.push_back(v);
        rec(pos+1,total,sumLeft);
    }
    rep(i,0,mx)
    moves.pop_back();
    rep(i,0,3)
    A[v-1+i] = was[i];
}

void run()
{
    int n;
    int H[10];
    cin>>n>>a>>b;
    rep(i,0,n)
    {
        scanf("%d",H+i);
        ++H[i];
    }
    vector<int> res;
    rep(i,0,(H[0]+b-1)/b)
    {
        H[1] = max(0, H[1] - a);
        H[2] = max(0, H[2] - b);
        res.push_back(1);
    }
    H[0] = 0;
    rep(i,0,(H[n-1]+b-1)/b)
    {
        H[n-2] = max(H[n-2] - a, 0);
        H[n-3] = max(H[n-3] - b, 0);
        res.push_back(n-2);
    }
    H[n-1] = 0;
    int sum = 0;
    rep(i,0,n)
    sum += H[i];
    rep(i,0,n)
        A[i] = H[i];
    rec(0,n-2, sum);
    rep(i,0,best.size())
    res.push_back(best[i]);
    cout<<res.size()<<endl;
    rep(i,0,res.size())
    printf("%d ", res[i]+1);
    
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