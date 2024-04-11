#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct point{
    point(){}
    point(int x,int y):x(x),y(y){}
    int x,y;
}p[310];
int N;
double ans;

inline double ab(double x){return x>0?x:-x;}

int ccw(point a,point b){return a.x*b.y-a.y*b.x;}

void solve(int x,int y)
{
    double a = (double)(p[y].y-p[x].y);
    double b = (double)(p[x].x-p[y].x);
    double c = (double)(p[x].y*(p[y].x-p[x].x)-p[x].x*(p[y].y-p[x].y));
    int i;
    double d1=0.0,d2=0.0;
    bool f1=0,f2=0;
    for(i=1;i<=N;i++){
        if(i==x || i==y)continue;
        double d = ab(a*p[i].x+b*p[i].y+c)/sqrt(a*a+b*b);
        int cw = ccw(point(p[x].x-p[y].x,p[x].y-p[y].y),point(p[x].x-p[i].x,p[x].y-p[i].y));
        if(cw==0){f1=1;f2=1;continue;}
        if(cw>0){f1=1;d1=max(d1,d);}
        else{f2=1;d2=max(d2,d);}
    }
    if(f1&&f2){
        ans=max(ans,sqrt((p[x].x-p[y].x)*(p[x].x-p[y].x)+(p[x].y-p[y].y)*(p[x].y-p[y].y))*(d1+d2)/2.0);
    }
}

int main()
{
    scanf("%d",&N);
    int i,j;
    for(i=1;i<=N;i++)scanf("%d%d",&p[i].x,&p[i].y);
    for(i=1;i<=N;i++){
        for(j=i+1;j<=N;j++){
            solve(i,j);
        }
    }
    printf("%f",ans);
    return 0;
}