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

const int SZ = 300100;
int Fen[SZ] = {0};
void addFen(int pos, int val)
{
    ++pos;
    for (int i = pos; i > 0; i-=i&-i)
        Fen[i] += val;
}

int getFen(int pos)
{
    ++pos;
    int res = 0;
    for (int i = pos; i< SZ; i+=i&-i)
        res += Fen[i];
    return res;
}

vector<int> V[300100];
void run()
{
    int n,p;
    cin>>n>>p;
    int Cnt[300100] = {0};
    map<pii, int> mp;
    rep(i,0,n)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (x > y)
            swap(x,y);
        --x;--y;
        V[y].push_back(x);
        mp[pii(x,y)]++;
        Cnt[x]++;
        Cnt[y]++;
    }
rep(i,0,n)
sort(all(V[i]));
    ll res = 0;
    rep(i,0,n)
    {
        int here = 0;
        rep(j,0, V[i].size())
if (j==0 || V[i][j] != V[i][j-1])
        {
            int to = V[i][j];
            addFen(Cnt[to], -1);
            here += Cnt[i] + Cnt[to] - mp[pii(to,i)] >= p;
        }
        here += getFen(max(0,p - Cnt[i]));
        res += here;
        rep(j,0, V[i].size())
if (j==0 || V[i][j] != V[i][j-1])
        {
            int to = V[i][j];
            addFen(Cnt[to], 1);
        }
        addFen(Cnt[i], 1);
    }
    cout<<res<<endl;
}


//#define prob "D-large"


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