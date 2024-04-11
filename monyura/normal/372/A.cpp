#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif


#include <iostream>
#include <iomanip>
#include <cstdio>
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



void run()
{
    int n;
    cin>>n;
    int A[500500];
    rep(i,0,n)
    scanf("%d",A+i);
    int res = 0;
    set<pii> st;
    sort(A,A+n);
    set<pii>::iterator iter;
    rep(i,0,n)
    {
        st.insert(pii(A[i],i));
    }
    bool used[500500] = {0};
    rep(i,0,n)
    {
        pii need(A[i] * 2, 0);
        if (!used[i])
        {
            iter = st.lower_bound(need);
            if (iter != st.end())
            {
                used[iter->second] = 1;
                st.erase(iter);
                ++res;
            }
        }
        else
        {
            iter = st.lower_bound(pii(A[i]+1,0));
            if (iter != st.end())
            {
                used[iter->second] = 1;
                st.erase(iter);
                iter = st.lower_bound(need);
                if (iter != st.end())
                {
                    used[iter->second] = 1;
                    st.erase(iter);
                    ++res;
                }
            }
        }
        st.erase(pii(A[i],i));
    }
    cout<<n - res << endl;
}

//#define prob "kids"

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
    printf("\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}