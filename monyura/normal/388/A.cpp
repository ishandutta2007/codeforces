#pragma comment(linker,"/STACK:128000000")
#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>
#include <functional>
#include <cstdlib>
#include <complex>
#include <ctime>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> cd;

#define rep(x,y,z) for (int x = (y), e##x = (z); x < e##x; x++)
#define all(c) (c).begin(), (c).end()
const double PI = acos(-1.0);


void run()
{
    int n;
    cin>>n;
    int A[101];
    rep(i,0,n)
    scanf("%d",A+i);
    sort(A,A+n,greater<int>());
    rep(i,1,n+1)
    {
        bool ok = 1;
        int B[101];
        rep(j,0,i)
            B[j] = A[j];
        rep(j,i,n)
        {
            int mx = 0;
            rep(k,0,i)
            if (B[k] > B[mx])
                mx = k;
            if (B[mx] > 0)
            {
                B[mx] = min(B[mx]-1, A[j]);
            }
            else
            {
                ok = 0;
                break;
            }
            
        }
        if (ok)
        {
            printf("%d\n",i);
            return;
        }
    }
}

//#define problem "finals"

int main()
{
#ifdef _MONYURA_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t start = clock();
#else
#ifdef problem
    freopen(problem".in","r",stdin);
    freopen(problem".out","w",stdout);
#endif
#endif
    run();
#ifdef _MONYURA_
    printf("============\nTime: %.3lf\n",(clock() - start)/double(CLOCKS_PER_SEC));
#endif
    return 0;
}