#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const double eps=1e-10;
int dcmp(double x)
{
    if(fabs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point
{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    void Read(){scanf("%lf%lf",&x,&y);}
}P1,P2,M1,M2,W1,W2,P1_R,P2_R;
typedef Point Vector;
Vector operator+(const Vector &p,const Vector &q){return Vector(p.x+q.x,p.y+q.y);}
Vector operator-(const Vector &p,const Vector &q){return Vector(p.x-q.x,p.y-q.y);}
Vector operator*(const Vector &p,double k){return Vector(p.x*k,p.y*k);}
Vector operator/(const Vector &p,double k){return Vector(p.x/k,p.y/k);}
double Dot(const Vector &p,const Vector &q){return p.x*q.x+p.y*q.y;}
double Cross(const Vector &p,const Vector &q){return p.x*q.y-p.y*q.x;}
double Length(const Vector &p){return sqrt(p.x*p.x+p.y*p.y);}
bool PointOnSegment(const Point &p,const Point &a1,const Point &a2)
{
    return dcmp(Cross(a1-p,a2-p))==0&&dcmp(Dot(a1-p,a2-p))<0;
}
bool SegmentIntersection(const Point &a1,const Point &a2,const Point &b1,const Point &b2)
{
    if(PointOnSegment(a1,b1,b2)) return true;
    if(PointOnSegment(a2,b1,b2)) return true;
    if(PointOnSegment(b1,a1,a2)) return true;
    if(PointOnSegment(b2,a1,a2)) return true;
    double c1=Cross(b1-a1,a2-a1),c2=Cross(b2-a1,a2-a1);
    double c3=Cross(a1-b1,b2-b1),c4=Cross(a2-b1,b2-b1);
    return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
int main()
{
    P1.Read(),P2.Read();
    W1.Read(),W2.Read();
    M1.Read(),M2.Read();
    int same_half_plane=dcmp(Cross(P1-M1,M2-M1))*dcmp(Cross(P2-M1,M2-M1));
    if(same_half_plane<0)
    {
        bool ans=true;
        ans&=(!SegmentIntersection(P1,P2,W1,W2));
        ans&=(!SegmentIntersection(P1,P2,M1,M2));
        if(ans) puts("YES");
        else puts("NO");
        return 0;
    }
    double Len=Dot(M2-M1,P2-M1)/Length(M2-M1);
    P2_R=(M2-M1)/Length(M2-M1)*Len;
    P2_R=P2_R-(P2-M1-P2_R)+M1;
    Len=Dot(M2-M1,P1-M1)/Length(M2-M1);
    P1_R=(M2-M1)/Length(M2-M1)*Len;
    P1_R=P1_R-(P1-M1-P1_R)+M1;
    bool ans=false;
    ans|=(!SegmentIntersection(P1,P2,W1,W2));
    ans|=((!SegmentIntersection(P1,P2_R,W1,W2))&&(!SegmentIntersection(P1_R,P2,W1,W2))&&(SegmentIntersection(P1,P2_R,M1,M2)));
    if(ans) puts("YES");
    else puts("NO");
    return 0;
}