#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int a,b,c;
	bool operator<(line x)const{return x.b!=0&&(b==0||a*x.b>x.a*b);}// sort by k
	void positive()
	{
		if(b<0)a=-a,b=-b,c=-c;
	}
}l[N];
struct point
{
	double x,y;
	point(double a=0.0,double b=0.0){x=a;y=b;}
	point(line a,line b)// intersection
	{
		int det=a.a*b.b-a.b*b.a,det1=a.b*b.c-a.c*b.b,det2=a.c*b.a-a.a*b.c;
		x=det1/(double)det;
		y=det2/(double)det;
	}
	point operator+(point b){return point(x+b.x,y+b.y);}
	double operator*(point b){return x*b.y-y*b.x;}
};
int n;
double tot,ans;
double area(point *p,int n)
{
	double ans=0.0;
	F(i,0,n)ans+=p[i]*p[(i+1)%n];
	return ans/=2.0;
}
int main()
{
	read(n);
	F(i,0,n)read(l[i].a),read(l[i].b),read(l[i].c);
	F(i,0,n)l[i].positive();
	sort(l,l+n);
	tot=(double)n*(n-1)*(n-2)/6.0;
	F(i,0,n)
	{
		point sum;
		F(j,i+1,n)
		{
			point p(l[i],l[j]);
			ans+=sum*p;
			sum=sum+p;
		}
		F(j,0,i)
		{
			point p(l[i],l[j]);
			ans+=sum*p;
			sum=sum+p;
		}
	}
	printf("%lf\n",ans/tot/2.0);
	return 0;
}