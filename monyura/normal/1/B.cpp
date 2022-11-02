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

bool isRC(char *str)
{
    return (str[0] == 'R' && isdigit(str[1]) && strchr(str,'C') != 0);
}

ll step[100];
int cnt;
void RCtoAlpha(char *str)
{
    int r,c;
    sscanf(str,"R%dC%d",&r,&c);
    swap(r,c);
    int len = 1;
    rep(i,1,cnt)
        if (step[i] >= r)
        {
            len = i;
            break;
        }
        else
            r -= step[i];
    --r;
    char res[50]={0};
    for (int i = len-1;i>=0;i--)
    {
        res[i] = 'A' + (r%26);
        r/=26;
    }
    sprintf(res+len,"%d", c);
    puts(res);
}

void AlphaToRC(char *str)
{
    char *col = str;
    while (!isdigit(*col))
        ++col;
    int c;
    sscanf(col, "%d",&c);
    *col = 0;
    int r = 0;
    int len = strlen(str);
    rep(i,0,len)
        r += step[i];
    int add = 0;
    rep(i,0,len)
        add = add*26 + str[i] - 'A';
    r += add ;
    printf("R%dC%d\n",c,r);
}

void run()
{
    step[0] = 1;
    cnt = 1;
    rep(i,1,100)
    {
        ++cnt;
        step[i] = step[i-1] * 26;
        if (step[i] > 1e6)
            break;
    }
    int n;
    cin>>n;
    char str[1000];
    rep(i,0,n)
    {
        scanf("%s",str);
        if (isRC(str))
            RCtoAlpha(str);
        else
            AlphaToRC(str);
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