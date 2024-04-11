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
    char str[1000100];
    scanf("%s",str);
    int A[]={1,6,8,9};
    set<int> was(A,A+4);
    char ans[1000100] = {0};
    int n = strlen(str);
    int pos = 0;
    rep(i,0,n)
    {
        if (was.find(str[i]-'0') != was.end())
            was.erase(str[i]-'0');
        else
            ans[pos++] = str[i];
    }
    int res = 0;
    rep(i,0,pos)
    res = (res*10 + ans[i]-'0')%7;
    res = (7-res) % 7;
    int left = 1;
    rep(i,0,n-4)
    left = (left*10)%7;
    do
    {
        int a = 0;
        rep(i,0,4)
          a = (a *10 + A[i]) % 7;
        a = (a * left)%7;
        if (a  == res)
            break;
    }
    while (next_permutation(A,A+4));
    rep(i,0,4)
    printf("%d",A[i]);
    printf("%s",ans);
    puts("");
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