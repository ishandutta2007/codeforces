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

const int blockSize = 750;
typedef pair<ll, int> pli;

struct block {
    vector<pli> arr;
    ll add = 0;
    int l,r;
} D[blockSize];

void run()
{
    assert(blockSize * blockSize > 500100);
    int n, q;
    cin>>n>>q;
    rep(i,0,n)
    {
        int val;
        scanf("%d", &val);
        D[i/blockSize].arr.push_back(pli(val, i));
    }
    int blocks = (n + blockSize - 1)/blockSize;
    rep(i,0,blocks)
    {
        sort(all(D[i].arr));
        D[i].l = i * blockSize;
        D[i].r = D[i].l + sz(D[i].arr) - 1;
    }
    rep(i,0,q)
    {
        int t;
        scanf("%d",&t);
        if (t == 1) {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            --l;--r;
            rep(i,0,blocks)
                if (l <= D[i].l && D[i].r <= r)
                    D[i].add += x;
                else if (max(D[i].l, l) <= min(D[i].r, r))
                {
                    rep(j,0,D[i].arr.size())
                        if (l <= D[i].arr[j].second && D[i].arr[j].second <= r)
                            D[i].arr[j].first += x;
                    sort(all(D[i].arr));
                }
        }
        else {
            int y;
            scanf("%d", &y);
            int mnpos = n;
            int mxpos = -1;
            rep(i,0,blocks) {
                ll need = y - D[i].add;
                auto lw = lower_bound(all(D[i].arr), pli(need,-1));
                if (lw != D[i].arr.end() && lw->first == need)
                    mnpos = min(mnpos, lw->second);
                auto up = upper_bound(all(D[i].arr), pli(need,n));
                if (up != D[i].arr.begin())
                    --up;
                if (up != D[i].arr.end() && up->first == need)
                    mxpos = max(mxpos, up->second);
            }
            if (mxpos == -1)
                mxpos = mnpos - 1;
            printf("%d\n", mxpos - mnpos);
        }
    }
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