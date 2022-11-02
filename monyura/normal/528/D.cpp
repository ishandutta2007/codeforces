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
#include <complex>


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


const double PI = acos(-1.0);

const int SZ = 200200;
char A[SZ];


const int LOGN = 21;
const int MAXN = 1<<LOGN;
typedef complex<double> base;
int rev[MAXN];
base wlen_pw[MAXN];


void fft (base a[], int n, bool invert) {
    for (int i=0; i<n; ++i)
        if (i < rev[i])
            swap (a[i], a[rev[i]]);
    
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert?-1:+1);
        int len2 = len>>1;
        
        base wlen (cos(ang), sin(ang));
        wlen_pw[0] = base (1, 0);
        for (int i=1; i<len2; ++i)
            wlen_pw[i] = wlen_pw[i-1] * wlen;
        
        for (int i=0; i<n; i+=len) {
            base t,
            *pu = a+i,
            *pv = a+i+len2,
            *pu_end = a+i+len2,
            *pw = wlen_pw;
            for (; pu!=pu_end; ++pu, ++pv, ++pw) {
                t = *pv * *pw;
                *pv = *pu - t;
                *pu += t;
            }
        }
    }
    
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] /= n;
}

void calc_rev (int n, int log_n) {
    for (int i=0; i<n; ++i) {
        rev[i] = 0;
        for (int j=0; j<log_n; ++j)
            if (i & (1<<j))
                rev[i] |= 1<<(log_n-1-j);
    }
}


base S[(1<<19) + 1][4]  = {0};
base T[(1<<19) + 1][4]  = {0};



void run()
{
    int n,m, k;
    cin>>n>>m>>k;
    scanf("%s",A);
    char pat[] = "ATGC";
    int last[4] = {-1,-1,-1,-1};
    rep(i,0,n)
    {
        int pos = strchr(pat, A[i]) - pat;
        last[pos] = i;
        rep(j,0,4)
            if (last[j] != -1 && i - last[j] <= k)
                S[i][j] = base(1, 0);
    }
    memset(last,-1,sizeof(last));
    for (int i = n-1; i>=0; i--)
    {
        int pos = strchr(pat, A[i]) - pat;
        last[pos] = i;
        rep(j,0,4)
        if (last[j] != -1 && last[j] - i <= k)
            S[i][j] = base(1, 0);
    }
    scanf("%s",A);
    rep(i,0,m)
    {
        int pos = strchr(pat, A[i]) - pat;
        T[i][pos] = base(1, 0);
    }
//    rep(i,0,n)
//    {
//        rep(j,0,4)
//            printf("%d ", (int)S[i][j].real());
//        puts("");
//    }
//    puts("");
//    rep(i,0,n)
//    {
//        rep(j,0,4)
//        printf("%d ", (int)T[i][j].real());
//        puts("");
//    }
//    puts("");
    base *p1 = S[0];
    base *p2 = T[0];
    calc_rev(MAXN, LOGN);
    
//    rep(i,0,MAXN)
//    cout<<p1[i].real();
//    cout<<endl;
//    rep(i,0,MAXN)
//    cout<<p2[i].real();
//    cout<<endl;

    reverse(p2, p2 + MAXN);
    
    
    fft(p1, MAXN, false);
    fft(p2, MAXN, false);
    rep(i,0,MAXN)
        p1[i] *= p2[i];
    fft(p1, MAXN, true);
//    rep(i,0,MAXN)
//        cout<<p1[i].real()<<endl;
    int res = 0;
    for (int i = MAXN - 1; i>=0; i-= 4)
    {
        res += (int)(p1[i].real() + 0.5) == m;
    }
    cout<<res<<endl;
}

//#define prob "exam"



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