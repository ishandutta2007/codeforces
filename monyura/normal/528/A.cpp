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
    int w,h,n;
    cin>>w>>h>>n;
    set<int> Hor, Ver;
    Hor.insert(0);
    Hor.insert(h);
    Ver.insert(0);
    Ver.insert(w);
    char buff[10];
    multiset<int, greater<int> > Hq, Vq;
    Hq.insert(h);
    Vq.insert(w);
    rep(i,0,n)
    {
        int x;
        scanf("%s%d",buff,&x);
        if (buff[0] == 'H')
        {
            Hor.insert(x);
            auto iter = Hor.find(x);
            auto prev = iter;
            --prev;
            auto next = iter;
            ++next;
            //
            auto pos = Hq.find(*next - *prev);
            Hq.erase(pos);
            Hq.insert(*iter - *prev);
            Hq.insert(*next - *iter);
        }
        else
        {
            Ver.insert(x);
            auto iter = Ver.find(x);
            auto prev = iter;
            --prev;
            auto next = iter;
            ++next;
            //
            auto pos = Vq.find(*next - *prev);
            Vq.erase(pos);
            Vq.insert(*iter - *prev);
            Vq.insert(*next - *iter);
        }
        ll res = ll(*Vq.begin()) * (*Hq.begin());
        printf("%l""ld\n", res);
    }
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