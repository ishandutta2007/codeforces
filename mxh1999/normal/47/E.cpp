//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

#define maxn 100010
const double g=9.8;
const double eps=1e-9;
int n,m,v;
struct Ques
{
    double angle;
    int id;
}   ques[10010];
struct Wall
{
    double x,y;
}   wall[maxn];
double ans_x[10010],ans_y[10010];

bool cmp(const Ques &a,const Ques &b)   {return a.angle<b.angle;}
bool cmp2(const Wall &a,const Wall &b)  {return a.x<b.x;}

int main()
{
    scanf("%d%d",&n,&v);
    for (int i=1;i<=n;i++)
    {
        scanf("%lf",&ques[i].angle);
        ques[i].id=i;
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
        scanf("%lf%lf",&wall[i].x,&wall[i].y);
    sort(ques+1,ques+n+1,cmp);
    sort(wall+1,wall+m+1,cmp2);
    int h=1;
    for (int i=1;i<=n;i++)
    {
        double v_y=v*sin(ques[i].angle),v_x=v*cos(ques[i].angle);
        while (h<=m)
        {
            double time=wall[h].x/v_x;
            double y=v_y*time-0.5*g*time*time;
            if (y<eps)
            {
                ans_x[ques[i].id]=v_x*(v_y/(0.5*g));
                ans_y[ques[i].id]=0;
                break;
            }   else
            if (y<wall[h].y+eps)
            {
                ans_x[ques[i].id]=wall[h].x;
                ans_y[ques[i].id]=y;
                break;
            }   else
            h++;
        }
    }
    for (int i=1;i<=n;i++)
    if (ans_x[ques[i].id]<eps)
    {
        double v_y=v*sin(ques[i].angle),v_x=v*cos(ques[i].angle);
        ans_x[ques[i].id]=v_x*(v_y/(0.5*g));
        ans_y[ques[i].id]=0;
    }
    for (int i=1;i<=n;i++)  printf("%.9lf %.9lf\n",ans_x[i],ans_y[i]);
    return 0;
}