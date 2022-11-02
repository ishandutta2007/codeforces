//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const double eps=1e-9;

struct Point
{
    double x,y;
    void read()
    {
        scanf("%lf%lf",&x,&y);
    }
}   men1,men2,men3,wall1,wall2,mirror1,mirror2;

inline Point operator-(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
inline double operator*(Point a,Point b){return b.x*a.y-a.x*b.y;}

bool dengyu(double a,double b)
{
    if (abs(a-b)<eps)   return true;return false;
}
bool jiao(Point s1,Point e1,Point s2,Point e2,bool bo)
{
    Point tmp1,tmp2;
    if (bo)
    {
        tmp1=e1-s1;
        tmp2=e2-s2;
        if (tmp1*tmp2==0)   return false;
    }
    tmp1=e1-s1;
    tmp2=s2-s1;
    Point tmp3=e2-s1;
    double S1=tmp1*tmp2;
    double S2=tmp1*tmp3;
    if (S1*S2>0)    return false;
    if (dengyu(S1,0) && !dengyu(S2,0))
    {
        if ((tmp2.x<=tmp1.x && tmp2.x>=0)||(tmp2.x<=0 && tmp2.x>=tmp1.x))   return true;
        return false;
    }
    if (dengyu(S2,0) && !dengyu(S1,0))
    {
        if ((tmp3.x<=tmp1.x && tmp3.x>=0)||(tmp3.x<=0 && tmp3.x>=tmp1.x))   return true;
        return false;
    }
    if (dengyu(S1,0) && dengyu(S2,0))
    {
        if (tmp1.x>0)
        {
            if (tmp2.x<=tmp1.x && tmp2.x>=0)    return true;
            if (tmp3.x<=tmp1.x && tmp3.x>=0)    return true;
            if ((tmp2.x>tmp1.x && tmp3.x<0)||(tmp3.x>tmp1.x && tmp2.x<0))   return true;
            return false;
        }   else
        {
            if (tmp2.x<=0 && tmp2.x>=tmp1.x)    return true;
            if (tmp3.x<=0 && tmp3.x>=tmp1.x)    return true;
            if ((tmp2.x>0 && tmp3.x<tmp1.x)||(tmp3.x>0 && tmp2.x<tmp1.x))   return true;
            return false;
        }
    }
    tmp1=e2-s2;
    tmp2=s1-s2;
    tmp3=e1-s2;
    S1=tmp1*tmp2;
    S2=tmp1*tmp3;
    if (S1*S2>0)    return false;
    if (dengyu(S1,0) && !dengyu(S2,0))
    {
        if ((tmp2.x<=tmp1.x && tmp2.x>=0)||(tmp2.x<=0 && tmp2.x>=tmp1.x))   return true;
        return false;
    }
    if (dengyu(S2,0) && !dengyu(S1,0))
    {
        if ((tmp3.x<=tmp1.x && tmp3.x>=0)||(tmp3.x<=0 && tmp3.x>=tmp1.x))   return true;
        return false;
    }
    if (dengyu(S1,0) && dengyu(S2,0))
    {
        if (tmp1.x>0)
        {
            if (tmp2.x<=tmp1.x && tmp2.x>=0)    return true;
            if (tmp3.x<=tmp1.x && tmp3.x>=0)    return true;
            if ((tmp2.x>tmp1.x && tmp3.x<0)||(tmp3.x>tmp1.x && tmp2.x<0))   return true;
            return false;
        }   else
        {
            if (tmp2.x<=0 && tmp2.x>=tmp1.x)    return true;
            if (tmp3.x<=0 && tmp3.x>=tmp1.x)    return true;
            if ((tmp2.x>0 && tmp3.x<tmp1.x)||(tmp3.x>0 && tmp2.x<tmp1.x))   return true;
            return false;
        }
    }
    return true;
}

Point change(Point x,Point s,Point e)
{
    double a=e.y-s.y,b=s.x-e.x,c=e.x*s.y-s.x*e.y;
    double k=-2*(a*x.x+b*x.y+c)/(a*a+b*b);
    double xx=x.x+k*a;
    double yy=x.y+k*b;
    return (Point){xx,yy};
}
Point Cross(Point s1,Point e1,Point s2,Point e2)
{
    double a=e1.y-s1.y,b=s1.x-e1.x,c=e1.x*s1.y-s1.x*e1.y;
    double d=e2.y-s2.y,e=s2.x-e2.x,f=e2.x*s2.y-s2.x*e2.y;
    double x=(c*e-b*f)/(d*b-a*e);
    double y=(c*d-a*f)/(a*e-b*d);
    return (Point){x,y};
}
int main()
{
    men1.read();
    men2.read();
    wall1.read();
    wall2.read();
    mirror1.read();
    mirror2.read();
    if (!jiao(men1,men2,mirror1,mirror2,true) && !jiao(men1,men2,wall1,wall2,false))
    {
        printf("YES\n");
        return 0;
    }
    men3=change(men1,mirror1,mirror2);
    if (jiao(men3,men2,mirror1,mirror2,true))
    {
        Point q=Cross(men2,men3,mirror1,mirror2);
        if (!jiao(men1,q,wall1,wall2,false) && !jiao(men2,q,wall1,wall2,false))
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}