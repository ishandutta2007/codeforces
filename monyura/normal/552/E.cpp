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
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <cassert>


using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c.size())

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double, int> pdi;
typedef pair<double, double> pdd;


char str[100100];

ll build(char *str, ll *Sum, ll *Mul, ll * Terms, ll *TermId) {
    int D[5001];
    int Op[5001] = {'+'};
    int n = (int)strlen(str);
    for (int i = 0; i < n; i+=2) {
        D[i/2] = str[i] - '0';
        Op[i/2+1] = str[i+1];
    }
    n = (n+1)/2;
    ll val = 0;
    ll term = 0;
    rep(i,0,n)
    {
        if (Op[i] == '+') {
            val += term;
            term = 1;
        }
        else
            int st =1;
        Sum[i] = val;
        Mul[i] = term;
        term *= D[i];
    }
    val += term;
    if (Terms) {
        ll currTerms = 1;
        int id = 0;
        for (int i = n-1; i>=0; i--) {
            if (i == n-1 || Op[i+1] == '+')
            {
                currTerms = Mul[i] * D[i];
                id++;
            }
            Terms[i] = currTerms;
            TermId[i] = id;
        }
    }
    return val;
}

void run()
{
    scanf("%s",str);
    ll PrefSum[5001], PrefMul[5001], SuffSum[5001], SuffMul[5001], Terms[5001], TermId[5001];
    ll res = build(str, PrefSum, PrefMul, Terms, TermId);
    reverse(str, str + strlen(str));
    build(str, SuffSum, SuffMul, nullptr, nullptr);
    int n = ((int)strlen(str)+1)/2;
    reverse(SuffSum, SuffSum + n);
    reverse(SuffMul, SuffMul + n);
    ll all = res;
    rep(i,0,n)
        rep(j,i, n)
    if (TermId[i] != TermId[j]) {
                ll valInside = 0;
                valInside = all - PrefSum[i] - SuffSum[j] - Terms[i] - Terms[j];
                valInside += Terms[i]/PrefMul[i] + Terms[j]/SuffMul[j];
                ll here = PrefSum[i] + SuffSum[j] + PrefMul[i]*SuffMul[j] * valInside;
                if (here > res) {
                    res = here;
                }
            }
    cout<<res<<endl;
    
}



int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen("../" prob ".in","r",stdin);
    freopen("../" prob ".out","w",stdout);
#else
    freopen("../test.in","r",stdin);
    freopen("../test.out","w",stdout);
    time_t st=clock();
#endif
#else
#endif
    run();
#ifdef _MONYURA_
#ifndef prob
    printf( "\n=============\n");
    printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
#endif
    
    return 0;
}