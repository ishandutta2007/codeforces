#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long LL;
const double eps=1e-12;
struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
    friend bool operator<(const Point &p,const Point &q)
    {
        return p.x<q.x;
    }
}P[2010],A[2010];
typedef Point Vector;
Vector operator+(const Vector &p,const Vector &q){return Vector(p.x+q.x,p.y+q.y);}
Vector operator-(const Vector &p,const Vector &q){return Vector(p.x-q.x,p.y-q.y);}
int Cross(const Vector &p,const Vector &q){return p.x*q.y-p.y*q.x;}
int Dot(const Vector &p,const Vector &q){return p.x*q.x+p.y*q.y;}
int quad(const Point &p)
{
    if(p.y<0&&p.x<=0) return 1;
    if(p.y<=0&&p.x>0) return 2;
    if(p.y>0&&p.x>=0) return 3;
    if(p.y>=0&&p.x<0) return 4;
}
bool cmp(const Point &p,const Point &q)
{
    int x=quad(p),y=quad(q);
    if(x<y) return true;
    if(x>y) return false;
    return Cross(p,q)>0;
}
int n,tot;
LL ans,Minus;
int main()
{
    scanf("%d",&n);
    if(n<3) {puts("0");return 0;}
    for(int i=1;i<=n;i++) scanf("%d%d",&P[i].x,&P[i].y);
    ans=(n*(n-1)/2LL)*(LL)(n-2)/3LL;
    for(int i=1;i<=n;i++)
    {
        tot=0;
        for(int j=1;j<=n;j++)
            if(i!=j) A[++tot]=P[j]-P[i];
        sort(A+1,A+tot+1,cmp);
        int L=1,R;
        while(L<=tot)
        {
            R=L;
            while(R+1<=tot&&Cross(A[R+1],A[L])==0&&Dot(A[R+1],A[L])>=0) R++;
            Minus+=(R-L+1)*(R-L)/2LL;
            L=R+1;
        }
    }
    ans-=Minus/2LL;
    printf("%I64d\n",ans);
    return 0;
}