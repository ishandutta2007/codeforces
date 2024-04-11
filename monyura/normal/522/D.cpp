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


const int INF = 1e9;
const int SZ = 500500;
int Fen[SZ];
void addFen(int pos, int val)
{
    pos++;
    for (int i = pos; i > 0; i -= i&-i)
    Fen[i] = min(Fen[i], val);
}

int getFen(int pos)
{
    pos++;
    int res = INF;
    for (int i = pos; i < SZ; i += i&-i)
        res = min(res, Fen[i]);
    return res;
}

int A[SZ];
int Ans[SZ];
pair<pii, int> Q[SZ];
void run()
{
    int n,m;
    cin>>n>>m;
    rep(i,0,n)
        scanf("%d",A+i);
    rep(i,0,m)
    {
        scanf("%d%d",&Q[i].first.second, &Q[i].first.first);
        --Q[i].first.first;
        --Q[i].first.second;
        Q[i].second = i;
        Ans[i] = INF;
    }
    sort(Q, Q + m);
    rep(i,0,SZ)
        Fen[i] = INF;
    map<int, int> mp;
    int pos = 0;
    rep(i,0,n + 1)
    {
        if (i < n)
        {
            auto iter = mp.find(A[i]);
            if (iter != mp.end())
            {
                int len = i - iter->second;
                addFen(iter->second, len);
            }
            mp[A[i]] = i;
        }
        while (pos < m && Q[pos].first.first <= i)
        {
            int a = Q[pos].first.second;
            int ind = Q[pos].second;
            int curr = getFen(a);
            Ans[ind] = min(Ans[ind], curr);
            ++pos;
        }
    }
    rep(i,0,m)
        printf("%d\n", Ans[i] == INF ? -1 : Ans[i]);
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