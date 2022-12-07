#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=200010;
const double PI=acos(-1);
struct Point
{
	double x,y;
	Point(){}
	Point(double _x,double _y):x(_x),y(_y){}
}P[MAXN];
typedef Point Vector;
Vector operator+(const Vector &p,const Vector &q){return Vector(p.x+q.x,p.y+q.y);}
Vector operator-(const Vector &p,const Vector &q){return Vector(p.x-q.x,p.y-q.y);}
Vector operator*(const Vector &p,double x){return Vector(p.x*x,p.y*x);}
Vector operator/(const Vector &p,double x){return Vector(p.x/x,p.y/x);}
Vector v;
int n;
double len=500,step=0.01;
int main()
{
	scanf("%d",&n);
	if(n<=4) {puts("No solution");return 0;}
	for(int i=0;i<n-1;i++)
	{
		v=Vector(cos(2*PI*i/n),sin(2*PI*i/n));
		P[i+1]=P[i]+v*len;
		len+=step;
	}
	v=Vector(cos(2*PI*(n-1)/n),sin(2*PI*(n-1)/n));
	P[n]=P[n-1]-v*(P[n-1].y/v.y);
	for(int i=1;i<=n;i++) printf("%.03lf %.03lf\n",P[i].x,P[i].y);
	return 0;
}