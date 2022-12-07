#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int n,m;
struct Point
{
	LL x,y;
	Point(){}
	Point(LL _x,LL _y):x(_x),y(_y){}
	friend bool operator<(const Point &p,const Point &q)
	{
		return (p.x==q.x)?(p.y>q.y):(p.x<q.x);
	}
}p[MAXN],P[MAXN],Sta[MAXN];
Point operator+(const Point &p,const Point &q){return Point(p.x+q.x,p.y+q.y);}
Point operator-(const Point &p,const Point &q){return Point(p.x-q.x,p.y-q.y);}
LL Dot(const Point &p,const Point &q){return p.x*q.x+p.y*q.y;}
LL Cross(const Point &p,const Point &q){return p.x*q.y-p.y*q.x;}
int top;
int main()
{
	scanf("%d%d%*d%*d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d%I64d",&p[i].x,&p[i].y);
	for(int i=1;i<=m;i++) scanf("%I64d%I64d",&P[i].x,&P[i].y);
	sort(P+1,P+m+1);
	for(int i=1;i<=m;i++)
	{
		while(top>1&&Cross(P[i]-Sta[top],Sta[top]-Sta[top-1])<=0) top--;
		Sta[++top]=P[i];
	}
	for(int i=top-1;i>=0;i--) Sta[i].y=max(Sta[i].y,Sta[i+1].y);
	for(int i=1;i<=n;i++)
	{
		int sub=lower_bound(Sta,Sta+top+1,p[i])-Sta;
		if(sub==top+1) {puts("Max");return 0;}
		if(Cross(Sta[sub]-Sta[sub-1],p[i]-Sta[sub-1])>=0) {puts("Max");return 0;}
	}
	puts("Min");
	return 0;
}