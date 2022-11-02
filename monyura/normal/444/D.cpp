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

map<pii, int> mp;

vector<int> St[27*27*27*27];
vector<int> F[27*27*27*27];

void run()
{
    char str[100100];
    scanf("%s",str);
    int n = (int)strlen(str);
    rep(t,1,5)
    {
        rep(i,0,n-t+1)
        {
            int curr = 0;
            rep(j,0,t)
                curr = curr * 27 + str[i+j]-'a'+1;
            St[curr].push_back(i);
            F[curr].push_back(i+t-1);
        }
    }
    int q;
    cin>>q;
    rep(i,0,q)
    {
        char A[5], B[5];
        scanf("%s%s",A,B);
        int la = (int)strlen(A);
        int lb = (int)strlen(B);
        int lmx = max(la,lb);
        int a = 0;
        rep(j,0,la)
        a = a*27 + A[j] -'a' + 1;
        int b = 0;
        rep(j,0,lb)
        b = b*27 + B[j] - 'a' + 1;
        if (a > b)
            swap(a,b);
        if (mp.find(pii(a,b)) != mp.end())
            printf("%d\n", mp[pii(a,b)]);
        else
        {
            int &res = mp[pii(a,b)];
            if (St[a].size() ==0 || St[b].size() == 0)
            {
                res = -1;
                printf("-1\n");
                continue;
            }
            res = n;
            rep(i,0,la-lb+1)
            if (strncmp(A+i,B,lb)==0)
                res = min(res, la);
            rep(i,0,lb-la+1)
            if (strncmp(B+i, A, la)==0)
                res = min(res, lb);
            rep(t,0,2)
            {
                rep(i,0,St[a].size())
                {
                    auto iter = lower_bound(all(F[b]), St[a][i]+lmx-1);
                    if (iter == F[b].end())
                        break;
                    res = min(res, *iter - St[a][i]+1);
                }
                swap(a,b);
            }
            printf("%d\n", res);
        }
    }
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