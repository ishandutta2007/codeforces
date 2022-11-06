#include <cstdio>
#include <cmath>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<double, double> point;
double dist(point& a,point& b){
    auto sqr = [](double x){return x*x; };
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
point d[3];
double s[3];
double a[3];
double c2(double a,double b,double c){
    return acos((a*a+b*b-c*c)/(2*a*b));
}
int main()
{
    int i,j;
    for(i=0;i<3;++i) scanf("%lf%lf",&d[i].x,&d[i].y);
    for(i=0;i<3;++i) s[i]=dist(d[i],d[(i+1)%3]);
    for(i=0;i<3;++i) a[i]=2*c2(s[i],s[(i+1)%3],s[(i+2)%3]);
    double ca, r=s[2]/sin(a[0]/2)/2;
    for(i=3;i<=100;++i){
        ca=2*3.14159265358979323/i;
        for(j=0;j<3;++j){
            if(abs(a[j]-ca*round(a[j]/ca))>1e-6) break;
        }
        if(j==3){
            printf("%.9f\n",i*r*r*sin(ca)/2);
            break;
        }
    }
    return 0;
}