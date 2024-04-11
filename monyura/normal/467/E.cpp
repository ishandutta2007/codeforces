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

const int SZ = 500100;
int A[SZ];
int D[SZ];
int From[SZ];
pii Val[SZ];
map<int,int> mp;
int NextSame[SZ];
vector<int> mn[4*SZ];
void build(int v, int l, int r)
{
    if (l == r)
    {
        mn[v].push_back(NextSame[l]);
        return;
    }
    int c = (l+r)/2;
    build(2*v, l, c);
    build(2*v+1, c+1, r);
    mn[v].resize(mn[2*v].size()+ mn[2*v+1].size());
    merge(all(mn[2*v]), all(mn[2*v+1]), mn[v].begin());
}

int pred;
int N;
int getMin(int v, int l, int r, int ql, int qr)
{
    if (l==ql && r==qr)
    {
        int pos = lower_bound(all(mn[v]), pred) - mn[v].begin();
        if (pos == mn[v].size())
            return N;
        return mn[v][pos];
    }
    int c = (l+r)/2;
    if (qr<=c)
        return getMin(2*v,l,c,ql,qr);
    else if (ql>c)
        return getMin(2*v+1,c+1,r,ql,qr);
    return min(getMin(2*v,l,c,ql,c), getMin(2*v+1,c+1,r,c+1,qr));
}

void run()
{
    int n;
    cin>>n;
    N = n;
    rep(i,0,n)
    {
        scanf("%d",A+i);
        //A[i] = rand() % 4;
    }
    for (int i = n-1;i>=0;i--)
    {
        if (mp.find(A[i]) == mp.end())
            NextSame[i] = n;
        else
            NextSame[i] = mp[A[i]];
        mp[A[i]] = i;
    }
    build(1,0,n-1);
    rep(i,0,n+1)
    {
        From[i] = -1;
        Val[i] = pii(-1, -1);
    }
    for (int i = n-4;i>=0;i--)
    {
        D[i] = D[i+1];
        From[i] = i+1;
        int nxta = i;
        rep(t,0,2)
        {
            int pra = nxta;
            nxta = NextSame[nxta];
            if (nxta == n) break;
            if (pra+1<=nxta-1)
            {
                pred = nxta+1;
                int ind = getMin(1,0,n-1,pra+1, nxta-1);
                if (ind < n)
                {
                    if (D[i] < D[ind+1] + 4)
                    {
                       // cout<<i<<' '<<t<<' '<<nxta<<endl;
                        D[i] = D[ind+1] + 4;
                        From[i] = ind+1;
                        Val[i]=pii(A[i], A[ind]);
                    }
                }
            }
        }
        if (nxta != n)
            nxta = NextSame[nxta];
        if (nxta != n)
        {
            if (D[i] < D[nxta+1] + 4)
            {
                D[i] = D[nxta+1] + 4;
                From[i] = nxta+1;
                Val[i] = pii(A[i], A[i]);
            }
        }
    }
    cout<<D[0]<<endl;
    int v = 0;
    while (v != -1)
    {
        if (Val[v].first != -1)
        rep(t,0,2)
        {
            printf("%d %d ",Val[v].first, Val[v].second);
        }
        v = From[v];
    }
    puts("");
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