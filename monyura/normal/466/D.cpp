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
void add(int &a, int b)
{
    a = (a+b)%mod;
}

void run()
{
    int n,h;
    cin>>n>>h;
    int A[2002];
    rep(i,0,n)
    {
        scanf("%d",A+i);
        A[i] = h- A[i];
        if (A[i] < 0)
        {
            puts("0");
            return;
        }
    }
    //    vector<int> st;
    //    vector<int> vec;
    //    rep(i,0, n)
    //    {
    //        if (A[i] != 0)
    //        {
    //            if (i==0 || A[i-1] == 0 || A[i-1] < A[i])
    //                st.push_back(i);
    //            if (i==n-1 || A[i+1] == 0 || A[i] > A[i+1])
    //            {
    //                if (st.empty() || A[st.back()] != A[i])
    //                {
    //                    puts("0");
    //                    return;
    //                }
    //                if (i != st.back())
    //                    vec.push_back(i - st.back() + 1);
    //                vec.pop_back();
    //            }
    //        }
    //    }
    //    int D[2002] = {1};
    //    rep(i,1,2002)
    //    add(D[i],)
    //
    A[n] = 0;
    n++;
    int D[2003][2003]={0};
    D[0][0] = 1;
    rep(i,0,n)
    {
        add(D[i+1][A[i]], D[i][A[i]]);
        if (A[i] > 0)
        {
            add(D[i+1][A[i]], D[i][A[i]-1]);
            add(D[i+1][A[i]-1], ll(D[i][A[i]]) * A[i] % mod);
            add(D[i+1][A[i]-1], ll(D[i][A[i]-1]) * A[i] % mod);
        }
//        cout<<A[i]<<endl;
//        rep(j,0,5)
//            printf("%d ", D[i+1][j]);
//        puts("");
    }
    int res = D[n][0];
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