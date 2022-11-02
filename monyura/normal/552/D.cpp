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

struct point {
    int x,y;
    point(){x=y=0;}
    point(int x0, int y0){
        x = x0;
        y = y0;
    }
    point operator+(const point &b) const {
        return {x + b.x, y + b.y};
    }
    point operator-(const point &b) const {
        return {x - b.x, y - b.y};
    }
    int operator*(const point &b) const {
        return x*b.x + y*b.y;
    }
    int operator^(const point &b) const {
        return x*b.y - y*b.x;
    }
    bool operator<(const point &b) const {
        int cros = *this ^ b;
        if (cros == 0)
            return *this * *this < b*b;
        return cros > 0;
    }
};

void run()
{
    int n;
    cin>>n;
    point P[2001];
    rep(i,0,n)
        scanf("%d%d",&P[i].x, &P[i].y);
    ll res = ll(n)*ll(n-1)*ll(n-2)/6;
    rep(i,0,n) {
        point A[2001];
        memcpy(A,P,sizeof(A));
        point origin = A[i];
        int cnt = 0;
        rep(j,0,n) {
            A[j] = A[j] - origin;
            if ((A[j].x>=0 && A[j].y>=0) || A[j].x > 0)
                A[cnt++] = A[j];
        }
        sort(A, A + cnt);
        for (int j = 1; j < cnt ;) {
            int st = j;
            while (j < cnt && (A[st] ^ A[j])==0)
                ++j;
            ll here = j - st;
            ll dif = here*(here-1)/2;
            res -=dif;
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