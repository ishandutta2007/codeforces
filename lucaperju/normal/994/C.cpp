#include <iostream>
#include <cmath>
using namespace std;
long long aria (long long x1, long long y1, long long x2, long long y2, long long x3, long long y3)
{
    return(y2-y1)*(x3-x1)-(y3-y1)*(x2-x1);
}
bool verif (long long x1, long long y1, long long x2, long long y2, long long x3, long long y3, long long x4, long long y4, long long x, long long y)
{
    long long s1=0,s2=0;
    s1+=fabs(aria(x1,y1,x2,y2,x3,y3));
    s1+=fabs(aria(x1,y1,x4,y4,x3,y3));
    s2+=fabs(aria(x1,y1,x2,y2,x,y));
    s2+=fabs(aria(x2,y2,x3,y3,x,y));
    s2+=fabs(aria(x3,y3,x4,y4,x,y));
    s2+=fabs(aria(x4,y4,x1,y1,x,y));
    if(s1==s2)
        return true;
    return false;
}
int main()
{
    long long x1,x2,x3,x4,y1,y2,y3,y4,cx1,cx2,cx3,cx4,cy1,cy2,cy3,cy4,ok=0,mx,my;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4>>cx1>>cy1>>cx2>>cy2>>cx3>>cy3>>cx4>>cy4;
    x1+=100;
    x2+=100;
    x3+=100;
    x4+=100;
    y1+=100;
    y2+=100;
    y3+=100;
    y4+=100;
    cx1+=100;
    cx2+=100;
    cx3+=100;
    cx4+=100;
    cy1+=100;
    cy2+=100;
    cy3+=100;
    cy4+=100;
    if(verif(x1,y1,x2,y2,x3,y3,x4,y4,cx1,cy1))
        ok=1;
    if(verif(x1,y1,x2,y2,x3,y3,x4,y4,cx2,cy2))
        ok=1;
    if(verif(x1,y1,x2,y2,x3,y3,x4,y4,cx3,cy3))
        ok=1;
    if(verif(x1,y1,x2,y2,x3,y3,x4,y4,cx4,cy4))
        ok=1;
    ///----
    if(verif(cx1,cy1,cx2,cy2,cx3,cy3,cx4,cy4,x1,y1))
        ok=1;
    if(verif(cx1,cy1,cx2,cy2,cx3,cy3,cx4,cy4,x2,y2))
        ok=1;
    if(verif(cx1,cy1,cx2,cy2,cx3,cy3,cx4,cy4,x3,y3))
        ok=1;
    if(verif(cx1,cy1,cx2,cy2,cx3,cy3,cx4,cy4,x4,y4))
        ok=1;
    ///----
    if(cx1==cx3)
    {
        mx=cx1;
        my=(cy1+cy3)/2;
    }
    else
    if(cy1==cy3)
    {
        my=cy1;
        mx=(cx1+cx3)/2;
    }
    if(verif(x1,y1,x2,y2,x3,y3,x4,y4,mx,my))
        ok=1;
    if(ok==1)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}