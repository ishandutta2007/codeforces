#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<ctime>
#include<memory.h>
#include<algorithm>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define fill(m,v) memset(m,v,sizeof(m))
//#define flush {cout.flush();fflush(stdout);}
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
//#define long long long
#include<map>
#include<set>
using namespace std;
#define mod 1000000007
typedef long long lli;
int main()
{
    int a,b,m;
    cin>>a>>b>>m;        
    int vx,vy,vz;
    cin>>vx>>vy>>vz;
    double t=((double) m)/(-vy);
    double ex=vx*t;
    double ez=vz*t;
    cout.precision(10);
    cout<<fixed;
    double ax=ex+(double)a/2,az=ez;

    int rx=0;
    int rz=0;
        while (abs(ax)>2*a)
            if (ax>0) ax-=2*a;
            else
                ax+=2*a;

        while (abs(az)>2*b)
            if (az>0) az-=2*b;
            else
                az+=2*b;
    if (ax<0) ax+=2*a;
    if (az<0) az+=2*b;
    if (ax>=a)
        cout<<2*a-ax;
    else
        cout<<ax;

    cout<<" ";

    if (az>=b)
        cout<<2*b-az;
    else
        cout<<az; 
    return 0;
}