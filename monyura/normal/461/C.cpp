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
typedef pair<double, double> pdd;


const int SZ = 100100;
int V[SZ] = {0};
ll Fen[SZ] = {0};
void addFen(int pos, int val)
{
    V[pos] += val;
    ++pos;
    for (int i = pos; i < SZ; i+= i&-i)
        Fen[i] += val;
}

ll getFen(int pos)
{
    ++pos;
    ll res = 0;
    for (int i = pos; i > 0; i -= i &-i)
        res += Fen[i];
    return res;
}

int getInd(int offset, int len, bool rev, int ind)
{
    return rev ? offset + len - 1 - ind: offset + ind;
}

void run()
{
    int n,q;
    cin>>n>>q;
    rep(i,0,n)
        addFen(i, 1);
    int offset = 0;
    int currLen = n;
    bool rev = false;
    int A[SZ] = {0};
    rep(T,0,q)
    {
        int t;
        scanf("%d", &t);
        if (t == 1)
        {
            int p;
            scanf("%d",&p);
            int left = currLen - p;
            if (p <= left)
            {
                if (!rev)
                {
                    rep(i,0,p)
                        A[i] = V[offset + i];
                    reverse(A, A+p);
                    rep(i,0,p)
                        addFen(offset + p + i, A[i]);
                    offset += p;
                }
                else
                {
                    rep(i,0,p)
                        A[i] = V[offset + currLen - p + i];
                    rep(i,0,p)
                        addFen(offset + currLen - 1 - p - i, A[i]);
                }
            }
            else
            {
                p = left;
                if (!rev)
                {
                    rep(i,0,p)
                        A[i] = V[offset + currLen - p + i];
                    rep(i,0,p)
                        addFen(offset + currLen - 1 - p - i, A[i]);
                }
                else
                {
                    rep(i,0,p)
                        A[i] = V[offset + i];
                    reverse(A, A+p);
                    rep(i,0,p)
                        addFen(offset + p + i, A[i]);
                    offset += p;
                }
                rev = !rev;
            }
            currLen -= p;
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            --r;
            int ql = getInd(offset, currLen, rev, l);
            int qr = getInd(offset, currLen, rev, r);
            if (ql > qr)
                swap(ql, qr);
            int res = (int)(getFen(qr) - getFen(ql-1));
            printf("%d\n", res);
        }
    }
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