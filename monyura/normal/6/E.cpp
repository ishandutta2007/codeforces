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

const int size = 100100;
int A[size];
int D[2][4*size];
void build(int v, int l, int r)
{
    if (l==r)
    {
        D[0][v] = D[1][v] = A[l];
        return;
    }
    int c = (l+r)/2;
    build(2*v,l,c);
    build(2*v+1,c+1,r);
    D[0][v] = min(D[0][2*v], D[0][2*v+1]);
    D[1][v] = max(D[1][2*v], D[1][2*v+1]);
}

int get(int v, int l, int r ,int ql, int qr, int id)
{
    if (l == ql && r == qr)
        return D[id][v];
    int c  = (l+r)/2;
    if (qr<=c)
        return get(2*v,l,c,ql,qr,id);
    else if (ql>c)
        return get(2*v+1,c+1,r,ql,qr,id);
    if (id == 0)
        return min(get(2*v,l,c,ql,c,id), get(2*v+1,c+1,r,c+1,qr,id));
    return max(get(2*v,l,c,ql,c,id), get(2*v+1,c+1,r,c+1,qr,id));
}

void run()
{
    int n,k;
    cin>>n>>k;
    rep(i,0,n)
        scanf("%d",A+i);
    build(1,0,n-1);
    vector<pii> res;
    int mx, mn;
    int r = -1;
    int longest = 0;
    rep(i,0,n)
    {
        r = max(r, i);
        mn = get(1,0,n-1,i,r,0);
        mx = get(1,0,n-1,i,r,1);
        while (r < n)
        {
            mx = max(mx, A[r]);
            mn = min(mn, A[r]);
            if (mx - mn > k)
                break;
            ++r;
        }
        --r;
        res.push_back(pii(i,r));
        longest = max(longest, r - i + 1);
    }
    int m = 0;
    rep(i,0,res.size())
        if (res[i].second - res[i].first + 1 == longest)
            res[m++] = res[i];
    cout<<longest<<' '<<m<<endl;
    rep(i,0,m)
        printf("%d %d\n",res[i].first+1,res[i].second+1);
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