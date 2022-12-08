#include <stdio.h>

bool can(double x, double y, double v)
{
    return x * x + y * y <= v * v;
}

int main()
{
    int x1,y1,x2,y2;
    scanf ("%d %d %d %d",&x1,&y1,&x2,&y2);
    double dx = x1 - x2, dy = y1 - y2;

    int v,t;
    scanf ("%d %d",&v,&t);

    int vx,vy;
    scanf ("%d %d",&vx,&vy);
    double l = 0, r = t; bool p = 0;
    for (int i=0;i<100;i++){
        double m = (l + r) / 2;
        if (can(dx+vx*m,dy+vy*m,v*m)) r = m, p = 1;
        else l = m;
    }
    if (p){
        printf ("%.12lf\n",r); return 0;
    }
    dx += vx * t;
    dy += vy * t;
    scanf ("%d %d",&vx,&vy);
    l = 0, r = 1e18;
    for (int i=0;i<100;i++){
        double m = (l + r) / 2;
        if (can(dx+vx*m,dy+vy*m,v*(m+t))) r = m;
        else l = m;
    }
    printf ("%.12lf\n",r+t);
    return 0;
}