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

const int SZ = 200200;
int isGood[SZ];
int pref[2*SZ + 10];
char buff[2*SZ + 10];

void kmp(char *pat, char *str, int add)
{
    int n = strlen(pat);
    int m = strlen(str);
    strcpy(buff, pat);
    buff[n] = '#';
    buff[n+1] = 0;
    strcat(buff, str);
    pref[0] = 0;
    int len = n + m + 1;
    rep(i,1,len)
    {
        int curr = pref[i-1];
        while (curr > 0 && buff[curr] != buff[i])
            curr = pref[curr-1];
        if (buff[curr] == buff[i])
            ++curr;
        pref[i] = curr;
        if (curr == n && (i - n - 1) - n + 1 >=0)
            isGood[(i - n - 1) - n + 1] += add;
    }
//    cout<<buff<<endl;
//    rep(i,0,len)
//        cout<<pref[i];
//    cout<<endl<<endl;
}

char A[SZ], B[SZ];
char ChA[SZ], ChB[SZ];

void run()
{
    memset(isGood, 0, sizeof(isGood));
    int n,m;
    cin>>n>>m;
    scanf("%s%s",A,B);
    rep(a,'a','z'+1)
    rep(b, a,'z'+1)
    {
        rep(i,0,n)
            ChA[i] = A[i] == a ? '1' : A[i] == b ? '2' : '0';
        int cnt = 0;
        rep(i,0,m)
        {
            ChB[i] = B[i] == b ? '1' : B[i] == a ? '2' : '0';
            cnt += ChB[i] != '0';
        }
        kmp(ChB, ChA, cnt);
    }
    vector<int> res;
    rep(i,0,n)
        if (isGood[i] == m)
            res.push_back(i);
    cout<<res.size()<<endl;
    rep(i,0,res.size())
        cout<<res[i] + 1<<' ';
}

//#define prob "graph"



int main()
{
#ifdef _MONYURA_
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
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