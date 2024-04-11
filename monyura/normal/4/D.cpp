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

void run()
{
    int n,w,h;
    cin>>n>>w>>h;
    int W[5001], H[5001], Ind[5001];
    rep(i,0,n)
        scanf("%d%d",W+i,H+i);
    int pos = 0;
    rep(i,0,n)
        if (W[i] > w && H[i] > h)
        {
            W[pos] = W[i];
            H[pos] = H[i];
            Ind[pos] = i;
            ++pos;
        }
    n = pos;
    if (n == 0)
    {
        puts("0");
        return;
    }
    pair<pii, int> A[5001];
    rep(i,0,n)
        A[i] = make_pair(pii(W[i], H[i]), Ind[i]);
    sort(A,A+n, greater<pair<pii, int> >());
    int D[5001] = {0};
    int From[5001];
    rep(i,0,n)
    {
        D[i] = 1;
        From[i] = -1;
        rep(j,0,i)
            if (A[j].first.first > A[i].first.first && A[j].first.second > A[i].first.second && D[j] + 1 > D[i])
            {
                D[i] = D[j] + 1;
                From[i] = j;
            }
    }
    pos = max_element(D, D+n) - D;
    cout<<D[pos]<<endl;
    vector<int> vec;
    while (pos != -1)
    {
        vec.push_back(A[pos].second);
        pos = From[pos];
    }
//    reverse(all(vec));
    rep(i,0,vec.size())
        printf("%d ", vec[i]+1);
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