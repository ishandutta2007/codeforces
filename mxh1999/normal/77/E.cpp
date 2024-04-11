#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;

int R,r,n;
int test;
double x,r1,y;

int main()
{
    scanf("%d",&test);
    while (test--)
    {
        scanf("%d%d%d",&R,&r,&n);
        x=R+r;
        r1=R-r;
        y=r1*2*n;
        double ans=(4*R*r*r1)/(x*x+y*y-r1*r1);
        printf("%.10lf\n",ans);
    }
    return 0;
}