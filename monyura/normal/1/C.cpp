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

struct point
{
    double x,y;
    point(double x0 = 0, double y0 = 0)
    {
        x = x0;
        y = y0;
    }
    point operator+(const point &b ) const
    {
        return point(x + b.x, y + b.y);
    }
    point operator-(const point &b ) const
    {
        return point(x - b.x, y - b.y);
    }
    double operator*(const point &b) const
    {
        return x * b.x + y * b.y;
    }
    point operator*(const double b) const
    {
        return point(x * b, y * b);
    }
    double operator^(const point &b) const
    {
        return x * b.y - y * b.x;
    }
    point rotate(double angle) const
    {
        double c = cos(angle);
        double s = sin(angle);
        return point(x *c  - y * s , x * s + y * c);
    }
};

void buildCenPerp(point p1, point p2, double &a, double &b, double &c)
{
    point mid = (p1+p2)*0.5;
    point d = p2-p1;
    a = d.x;
    b = d.y;
    c = -(d * mid);
}

point lineInter(double a0, double b0, double c0, double a1, double b1, double c1)
{
    double delta = a0*b1 - a1*b0;
    double delta1 = -c0*b1 - (-c1*b0);
    double delta2 = a0*(-c1) - (a1 * (-c0));
    return point(delta1/delta, delta2/delta);
}
const double PI = acos(-1.0);
const double eps = 1e-3;

void build(int n)
{
    point centr(5,6);
    double rad = 3;
    point A[100];
    A[0] = centr + point(0,rad);
    double angle = 2*PI/n;
    rep(i,1,n)
    {
        point diff = A[i-1] - centr;
        diff = diff.rotate(angle);
        A[i] = centr + diff;
    }
    rep(i,0,n)
    {
        cout<<A[i].x<< ' '<<A[i].y<<endl;
    }
}

void run()
{
//    build(12);
    point P[3];
    rep(i,0,3)
        scanf("%lf%lf",&P[i].x, &P[i].y);
    double A[2],B[2],C[2];
    rep(i,0,2)
        buildCenPerp(P[i], P[i+1], A[i], B[i], C[i]);
    point centr = lineInter(A[0], B[0], C[0], A[1], B[1], C[1]);
    point Circ[101];
    rep(n,3,101)
    {
        Circ[0] = P[0];
        double angle = 2*PI/n;
        int ok[3]={1,0,0};
        rep(j,1,n)
        {
            point diff = Circ[j-1] - centr;
            diff = diff.rotate(angle);
            Circ[j] = centr + diff;
            rep(t,1,3)
            if (fabs(Circ[j].x - P[t].x)<eps && fabs(Circ[j].y - P[t].y) < eps)
                ok[t] = 1;
        }
        if (*min_element(ok,ok+3) == 1)
        {
            double sum = 0;
            Circ[n] = Circ[0];
            rep(i,0,n)
                sum += Circ[i] ^ Circ[i+1];
            sum /= 2.0;
           // printf("%d ",n);
            printf("%.13lf\n", sum);
            return;
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