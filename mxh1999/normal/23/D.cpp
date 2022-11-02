//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

double eps=1e-10;
struct Point
{
    double x,y;
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
    bool operator==(const Point &rhs)   const
    {
        return (rhs.x==x && rhs.y==y);
    }
}   p[4];
Point operator+(Point a,Point b)
{
    return (Point){a.x+b.x,a.y+b.y};
}
Point operator-(Point a,Point b)
{
    return (Point){a.x-b.x,a.y-b.y};
}
Point operator*(double a,Point t)
{
    return (Point){a*t.x,a*t.y};
}
double operator*(Point a,Point b)
{
    return b.x*a.y-a.x*b.y;
}
inline double sqr(double t){return t*t;}
double abs(double a)
{
    return a>0?a:-a;
}
bool dengyu(double a,double b)
{
    return abs(a-b)<eps;
}
bool jiao(Point s1,Point e1,Point s2,Point e2)
{
    Point tmp1,tmp2;
    tmp1=e1-s1;
    tmp2=e2-s2;
    if (tmp1*tmp2==0)   return false;
    tmp1=e1-s1;
    tmp2=s2-s1;
    Point tmp3=e2-s1;
    double S1=tmp1*tmp2;
    double S2=tmp1*tmp3;
    if (S1*S2>0)    return false;
    if (dengyu(S1,0) || dengyu(S2,0))   return true;
    tmp1=e2-s2;
    tmp2=s1-s2;
    tmp3=e1-s2;
    S1=tmp1*tmp2;
    S2=tmp1*tmp3;
    if (S1*S2>0)    return false;
    if (dengyu(S1,0) || dengyu(S2,0))   return true;
    return true;
}
bool ok(Point A,Point B,Point C)
{
    if ((B.x-A.x)*(C.y-A.y)-(C.x-A.x)*(B.y-A.y)==0) return false;
    double a=2*B.x-2*A.x,b=2*B.y-2*A.y,c=sqr(B.x)-sqr(A.x)+sqr(B.y)-sqr(A.y);
    double d=2*B.x-2*C.x,e=2*B.y-2*C.y,f=sqr(B.x)-sqr(C.x)+sqr(B.y)-sqr(C.y);
    double g=2*B.x,h=2*B.y;
    double y1=(a*(d*g+e*h-f)-c*d)/(a*e-b*d);
    double x1=(b*(d*g+e*h-f)-c*e)/(b*d-a*e);
    double y2=h-y1;
    double x2=g-x1;
    Point s1=(Point){x1,y1},s2=(Point){x2,y2};
    Point s3=2*C-s2,s4=2*A-s1;
    Point tmp1=s2-s1,tmp2=s3-s2,tmp3=s4-s3,tmp4=s1-s4;
    if (jiao(s1,s2,s3,s4) || jiao(s2,s3,s4,s1)) return false;
    double S1=tmp1*tmp2,S2=tmp2*tmp3,S3=tmp3*tmp4,S4=tmp4*tmp1;
    if (dengyu(S1,0))   return false;
    if (dengyu(S2,0))   return false;
    if (dengyu(S3,0))   return false;
    if (dengyu(S4,0))   return false;
    if ((S1>0 && S2>0 && S3>0 && S4>0) || (S1<0 && S2<0 && S3<0 && S4<0))
    {
        printf("YES\n");
        printf("%.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf %.9lf\n",s1.x,s1.y,s2.x,s2.y,s3.x,s3.y,s4.x,s4.y);
        return true;
    }
    return false;
}
int main()
{
    int test;
    scanf("%d",&test);
    while (test--)
    {
        p[1].read();
        p[2].read();
        p[3].read();
        if (p[1]==p[2] || p[2]==p[3] || p[1]==p[3]) {printf("NO\n");printf("\n");continue;}
        if (ok(p[1],p[2],p[3])) continue;
        if (ok(p[2],p[1],p[3])) continue;
        if (ok(p[1],p[3],p[2])) continue;
        printf("NO\n");
        printf("\n");
    }
}