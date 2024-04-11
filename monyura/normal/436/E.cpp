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

set<pii> avSum;
set<pii> avA, usedA;
set<pii> avB, usedB;
int A[300100],B[300100];

void addSum(int i)
{
    avSum.erase(pii(A[i]+B[i], i));
    avA.erase(pii(A[i], i));
    usedB.insert(pii(B[i], i));
}

void run()
{
    int n,w;
    cin>>n>>w;
    
    rep(i,0,n)
    {
        int a,b;
        scanf("%d%d",&a, &b);
        b-=a;
        A[i] = a;
        B[i] = b;
        avSum.insert(pii(a+b,i));
        avA.insert(pii(a,i));
    }
    ll res = 0;
    rep(i,0,w)
    {
        set<pii>::iterator sumIt = avSum.begin();
        set<pii>::iterator aIt   = avA.begin();
        set<pii>::iterator bIt   = avB.begin();
        set<pii>::iterator it;
        ll newSum = 1e18;
        int move = -1;
        if (aIt !=  avA.end())
        {//move0
            ll here = res;
            here += aIt->first;
            if (here < newSum)
            {
                newSum = here;
                move = 0;
            }
        }
        if (bIt != avB.end())
        {//move1
            ll here = res;
            here += bIt->first;
            if (here < newSum)
            {
                newSum = here;
                move = 1;
            }
        }
        if (usedB.size() > 0 && sumIt != avSum.end())
        {//move2
            ll here = res;
            it = usedB.end();
            --it;
            here += sumIt->first - it->first;
            if (here < newSum)
            {
                newSum = here;
                move = 2;
            }
        }
        if (usedA.size() > 0 && sumIt != avSum.end())
        {//move3
            ll here = res;
            it = usedA.end();
            --it;
            here += sumIt->first - it->first;
            if (here < newSum)
            {
                newSum = here;
                move = 3;
            }
        }
        //apply
        res = newSum;
        if (move == 0)
        {
            int ind = aIt->second;
            avA.erase(aIt);
            usedA.insert(pii(A[ind],ind));
            avB.insert(pii(B[ind],ind));
            avSum.erase(pii(A[ind]+B[ind], ind));
        }
        if (move == 1)
        {
            int ind = bIt->second;
            avB.erase(bIt);
            usedB.insert(pii(B[ind],ind));
            usedA.erase(pii(A[ind], ind));
        }
        if (move == 2)
        {
            it = usedB.end();
            --it;
            int indb = it->second;
            avB.insert(pii(B[indb],indb));
            usedB.erase(pii(B[indb], indb));
            usedA.insert(pii(A[indb], indb));
            addSum(sumIt->second);
        }
        if (move == 3)
        {
            it = usedA.end();
            --it;
            int inda = it->second;
            avA.insert(pii(A[inda],inda));
            usedA.erase(pii(A[inda],inda));
            avB.erase(pii(B[inda], inda));
            avSum.insert(pii(A[inda]+B[inda],  inda));
            addSum(sumIt->second);
        }
        //
    }
    char Res[300100]={0};
    memset(Res,'0',n);
    for (auto p : usedA)
        Res[p.second] = '1';
    for (auto p : usedB)
        Res[p.second] = '2';
    cout<<res<<endl;
    puts(Res);
}


//#define prob "D-small-attempt1"


int main()
{
#ifdef _MONYURA_
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#else
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#endif
#else
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
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