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

struct point
{
    ll x,y;
    point(ll x0 = 0, ll y0 = 0)
    {
        x = x0;
        y = y0;
    }
    point operator*(const ll a) const
    {
        return point(a * x, a * y);
    }
    point operator+(const point &a) const
    {
        return point(x + a.x, y + a.y);
    }
    point operator-(const point &a) const
    {
        return point(x - a.x, y - a.y);
    }
    ll operator^(const point &a) const
    {
        return x * a.y - y * a.x;
    }
    double norm() const
    {
        return sqrt(x*x + y*y);
    }
};

int sign(ll a)
{
    if (a == 0)
        return 0;
    return a  < 0 ? -1 : 1;
}

int checkProj(ll a, ll b, ll c, ll d)
{
    ll sta = min(a, b), enda = max(a, b);
    ll stc = min(c, d), endc = max(c, d);
    return sign(min(enda, endc) - max(sta, stc));
}

bool intersect(const point &a, const point &b, const point &c, const point &d)
{
    ll pr1 = sign((b-a)^(c-a));
    ll pr2 = sign((b-a)^(d-a));
    ll pr3 = sign((d-c)^(b-c));
    ll pr4 = sign((d-c)^(a-c));
    if (pr1==0 && pr2 == 0 && pr3 == 0 && pr4 == 0)
    {
        int s1 = checkProj(a.x, b.x, c.x, d.x);
        int s2 = checkProj(a.y, b.y, c.y, d.y);
        return  s1>=0 && s2>=0 && (s1!=0 || s2!=0);
    }
    ll s1 = pr1 * pr2;
    ll s2 = pr3 * pr4;
    return s1 <=0 && s2 <=0 && (s1!=0 || s2!=0);
}

const int mod = 1e9+7;
int D[202][202];

bool Can[201][201] = {0};

int dyn(int a, int b)
{
    if (D[a][b] != -1)
        return D[a][b];
    int &res = D[a][b];
    if (b - a + 1 <= 3)
        return res = 1;
    res = 0;
    if (Can[a+1][b])
    {
        res = (res + dyn(a+1,b)) % mod;
    }
    rep(mid, a+2, b)
    {
        if (Can[a][mid] && Can[mid][b])
        {
            ll p1 = dyn(a, mid);
            ll p2 = dyn(mid, b);
            res = (res + p1*p2) % mod;
        }
    }
    return res;
}

//ll myabs(ll a)
//{
//    return a < 0 ? -a : a;
//}
//
//ll getSquare(const point &a, const point &b, const point &c)
//{
//    return (a.x-b.x)*(a.y+b.y)+(b.x-c.x)*(b.y+c.y)+(c.x-a.x)*(c.y+a.y);
//}

const double PI = acos(-1.0);

bool pointInside(point *P, int n, const point &a)
{
    double sum = 0;
    const double eps = 1e-8;
    rep(i,0,n)
    {
        point da = P[i] * 2 - a;
        point db = P[i+1] * 2 - a;
        double cs = (da.x * db.x + da.y * db.y)/(da.norm() * db.norm());
        if (cs < -1) cs = -1;
        if (cs > 1) cs = 1;
        double v = acos(cs);
        if (sign(da^db) < 0)
            sum += v;
        else
            sum -=v;
    }
    sum = fabs(sum);
    return fabs(sum - 2*PI) < eps;
}

//__int128 initSquare(point *P, int n)
//{
//    __int128 res = 0;
//    rep(i,0,n)
//        res += (P[i].x-P[i+1].x)*(P[i].y+P[i+1].y);
//    return myabs(res);
//}

void run()
{
    memset(D,-1,sizeof(D));
    point P[202];
    int n;
    cin>>n;
    rep(i,0,n)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        P[i] = point(x, y);
    }
    P[n] = P[0];
    //__int128 sq = initSquare(P, n);
    rep(i,0,n)
    rep(j,i+1,n)
    {
        bool ok = true;
        rep(k,0,n)
        if (intersect(P[i], P[j], P[k], P[k+1]))
            ok = false;
        if (ok)
        {
            if (!pointInside(P, n, P[i] + P[j]))
                ok = false;
        }
        if (ok)
        {
           // cout<<i<<' '<<j<<endl;
            Can[i][j] = Can[j][i] = 1;
        }
    }
    rep(i,0,n)
        Can[i][(i+1)%n] = Can[(i+1)%n][i] = 1;
    int res = dyn(0, n-1);
    cout<<res<<endl;
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