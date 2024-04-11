#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=5010;
int n;
struct Point
{
	LL x,y;
	Point(){}
	Point(LL _x,LL _y):x(_x),y(_y){}
	friend bool operator<(const Point &p,const Point &q)
	{
		return (p.x==q.x)?(p.y<q.y):(p.x<q.x);
	}
}P[MAXN],S[MAXN],P1,P2,P3;
int top;
typedef Point Vector;
Vector operator+(const Vector &p,const Vector &q){return Vector(p.x+q.x,p.y+q.y);}
Vector operator-(const Vector &p,const Vector &q){return Vector(p.x-q.x,p.y-q.y);}
LL Cross(const Vector &p,const Vector &q){return p.x*q.y-p.y*q.x;}
LL Area2(const Point &p,const Point &q,const Point &r){return abs(Cross(r-p,q-p));}
void Print(const Point &p){printf("%I64d %I64d\n",p.x,p.y);}
void ConvexHull()
{
	sort(P+1,P+n+1);
	for(int i=1;i<=n;i++)
	{
		while(top>1&&Cross(P[i]-S[top],P[i]-S[top-1])<0) top--;
		S[++top]=P[i];
	}
	int x=top;
	for(int i=n-1;i>=1;i--)
	{
		while(top>x&&Cross(P[i]-S[top],P[i]-S[top-1])<0) top--;
		S[++top]=P[i];
	}
}
int main()
{
	scanf("%d%*I64d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d%I64d",&P[i].x,&P[i].y);
	ConvexHull();
	for(int i=1;i<=top;i++) S[top+i]=S[i];
	for(int i=1;i<=top;i++)
	{
		int k=i+1;
		for(int j=i+1;j<i+top-1;j++)
		{
			while(k<=j) k++;
			while(k<i+top-1&&Area2(S[k+1],S[i],S[j])>Area2(S[k],S[i],S[j])) k++;
			if(Area2(S[i],S[j],S[k])>Area2(P1,P2,P3)) P1=S[i],P2=S[j],P3=S[k];
		}
	}
	Print(P1+P2-P3);
	Print(P2+P3-P1);
	Print(P1+P3-P2);
	return 0;
}