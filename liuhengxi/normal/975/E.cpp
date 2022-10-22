#include<cstdio>
#include<cmath>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
typedef long double ld;
typedef double db;
#define double ld
using namespace std;
const int N=10005;
const double eps=1e-2,PI=3.141592653589793;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=10*x+(c^48);
	if(neg)x=-x;
}
struct point
{
	double x,y;
	point(double a=0.0,double b=0.0){x=a,y=b;}
	double operator-(point b)
	{
		double xx=x-b.x,yy=y-b.y;
		return sqrt(xx*xx+yy*yy);
	}
	point operator+(point b){return point(x+b.x,y+b.y);}
	point operator*(double b){return point(x*b,y*b);}
	point operator/(double b){return point(x/b,y/b);}
}p[N],c;
struct line
{
	double k,b;
	bool t;
	line(point A,point B)
	{
		t=false;
		if(A.x-B.x>=-eps&&A.x-B.x<=eps)
		{
			t=true;
			b=B.x;
			return;
		}
		k=(A.y-B.y)/(A.x-B.x);
		b=A.y-A.x*k;
	}
	point operator&(line a)
	{
		if(t)return point(b,b*a.k+a.b);
		if(a.t)return point(a.b,a.b*k+b);
		return point((a.b-b)/(k-a.k),(a.b*k-b*a.k)/(k-a.k));
	}
};
int n,q,pin1,pin2;
double totarea,deg1[N],dis[N];
bool o=true;
double area(point A,point B,point C)
{
	return (A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x)/2.0;
}
point centroid(point A,point B,point C)
{
	point D=(B+C)/2.0;
	point E=(C+A)/2.0;
	point F=(A+B)/2.0;
	line a(A,D),b(B,E),c(C,F);
	point M=((a&b)+(b&c)+(c&a))/3.0;
	return M;
}
void calc(int i)
{
	double deg=deg1[i]-deg1[pin2];
	p[i]=point(sin(deg)*dis[i],cos(deg)*dis[i])+c;
}
int main()
{
	read(n);read(q);
	F(i,0,n)read(p[i].x),read(p[i].y);
	F(i,1,n-1)
	{
		double triarea=area(p[0],p[i],p[i+1]);
		totarea+=triarea;
		c=c+centroid(p[0],p[i],p[i+1])*triarea;
	}
	c=c/totarea;
	F(i,0,n)
	{
		deg1[i]=atan2(p[i].x-c.x,p[i].y-c.y);
		dis[i]=p[i]-c;
	}
	pin1=0;pin2=1;
	while(q--)
	{
		int op;read(op);
		if(op==1)
		{
			int f,t;read(f);read(t);--f,--t;
			if(pin2==f)pin1^=pin2^=pin1^=pin2;
			c=p[pin2];c.y-=dis[pin2];
			pin1=t;
			if(pin1!=pin2)calc(pin1);
			o=false;
		}
		else
		{
			int v;read(v);--v;
			if(v!=pin1&&v!=pin2&&!o)calc(v);
			db xx=p[v].x,yy=p[v].y;
			printf("%0.10lf %0.10lf\n",xx,yy);
		}
	}
	return 0;
}