#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef pair<double,double> point;
point jiaodian(double a1,double b1,double a2,double b2)
{
    double x=-(b1-b2)/(a1-a2);
    return make_pair(x,a1*x+b1);
}
void jiexishi(double xa,double ya,double xb,double yb,double &a,double &b)
{
    a=(ya-yb)/(xa-xb);
    b=ya-a*xa;
}
point waixin(double xa,double ya,double xb,double yb,double xc,double yc)
{
    double a1,b1,a2,b2;
    jiexishi(xa,ya,xb,yb,a1,b1);
    a1=-1/a1;
    b1=((ya+yb)/2)-a1*((xa+xb)/2);
    jiexishi(xa,ya,xc,yc,a2,b2);
    a2=-1/a2;
    b2=((ya+yc)/2)-a2*((xa+xc)/2);
    return jiaodian(a1,b1,a2,b2);
}
double gcd(double a,double b) { return (b<1e-3)?a:gcd(b,a-floor(a/b+1e-6)*b); }
int main()
{
    double xa,xb,xc,ya,yb,yc,dega,degb,degc,g;
    point p;
    scanf("%lf%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&xc,&yc);
    p=waixin(xa,ya,xb,yb,xc,yc);
    dega=atan2(xa-p.first,ya-p.second);
    degb=atan2(xb-p.first,yb-p.second);
    degc=atan2(xc-p.first,yc-p.second);
    g=gcd(gcd(abs(dega-degb),abs(degb-degc)),acos(-1)*2);
    printf("%.8lf\n",(((xa-p.first)*(xa-p.first))+((ya-p.second)*(ya-p.second)))*(acos(-1)*2/g)*sin(g/2)*cos(g/2));
    return 0;
}