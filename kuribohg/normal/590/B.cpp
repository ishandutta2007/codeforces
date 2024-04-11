#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
double x1,y1,x2,y2,vm,t,vx,vy,wx,wy;
double l,r,x,y;
int main()
{
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&vm,&t,&vx,&vy,&wx,&wy);
    l=0,r=1e20,x=x2-x1,y=y2-y1;
    for(int T=1;T<=1000000;T++)
    {
        double mid=(l+r)/2.0;
        double X=x,Y=y;
        if(mid>t)
        {
            X-=vx*t;
            Y-=vy*t;
            X-=wx*(mid-t);
            Y-=wy*(mid-t);
        }
        else
        {
            X-=vx*mid;
            Y-=vy*mid;
        }
        if(X*X+Y*Y<vm*vm*mid*mid) r=mid;
        else l=mid;
    }
    printf("%.020lf\n",l);
    return 0;
}