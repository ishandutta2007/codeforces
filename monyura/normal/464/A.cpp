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
    char str[2001];
    int n,p;
    cin>>n>>p;
    scanf("%s",str);
    if (n>=3 && p <=2)
    {
        puts("NO");
        return;
    }
    if (n>=3 && p == 3)
    {
        if (next_permutation(str, str+3))
        {
            rep(i,3,n)
                str[i] = str[i%3];
            puts(str);
        }
        else
            puts("NO");
        return;
    }
    for (int i = n-1; i>=0; i--)
    {
        rep(c,str[i]+1,'a'+p)
        {
            if ((i==0 || str[i-1]!=c) && (i==1 || str[i-2] != c))
            {
                str[i] = c;
                char pat[]="abc";
                do
                {
                    if (pat[0] != str[i] && (i==0 || pat[0] != str[i-1]) && pat[1] != str[i])
                        break;
                }
                while (next_permutation(pat, pat+3));
                rep(j,i+1,n)
                    str[j] = pat[(j-1-i)%3];
                puts(str);
                return;
            }
        }
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