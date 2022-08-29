#include <iostream>
#include <cstring> 
#include <cmath> 
using namespace std;

struct Point
{
    int x,y;
    Point()
    {
        x=0;
        y=0;
    }
    bool isL(Point _)
    {
        return (y==_.y && x<_.x);
    }
    bool isR(Point _)
    {
        return y==_.y && x>_.x;
    }
    
    bool isT(Point _)
    {
        return x==_.x && y<_.y;
    }
    
    bool isD(Point _)
    {
        return x==_.x && y>_.y;
    }
    void read()
    {
        scanf("%d%d",&x,&y);
    }
};
Point p[505];
void main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        p[i].read();
    int res=0;
    for (int i=0;i<n;i++)
    {
        int l=0,r=0,t=0,d=0;
        for (int j=0;j<n;j++)
        {
            if (p[i].isL(p[j]))
                l=1;
            else if (p[i].isR(p[j]))
                r=1;
            else if (p[i].isT(p[j]))
                t=1;
            else if (p[i].isD(p[j]))
                d=1;
        }
        if (l && r && t && d)
            res++;
    }
    printf("%d",res);
    
}