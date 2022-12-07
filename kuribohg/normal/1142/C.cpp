#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,st,top;
struct Point
{
    LL x,y;
    Point(){}
    Point(LL x,LL y):x(x),y(y){}
}p[MAXN],Sta[MAXN];
Point operator-(const Point &p,const Point &q)
{
    return Point(p.x-q.x,p.y-q.y);
}
LL Cross(const Point &p,const Point &q)
{
    return p.x*q.y-p.y*q.x;
}
bool operator<(const Point &p,const Point &q)
{
    return p.x==q.x?p.y<q.y:p.x<q.x;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lld%lld",&p[i].x,&p[i].y),p[i].y-=p[i].x*p[i].x;
    sort(p+1,p+n+1);
    st=1;
    while(p[st].x==p[st+1].x) st++;
    for(int i=st;i<=n;i++)
    {
        while(top>=2&&Cross(Sta[top]-Sta[top-1],p[i]-Sta[top])>=0) top--;
        Sta[++top]=p[i];
    }
    printf("%d\n",top-1);
    return 0;
}