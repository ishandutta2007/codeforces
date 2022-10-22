#include<cstdio>
#include<cmath>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
typedef long long ll;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
double dis(double x1,double y1,double x2,double y2)
{return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));}
void line(double x1,double y1,double x2,double y2,double &k,double &b)
{
	k=(y2-y1)/(x2-x1);
	b=(x2*y1-x1*y2)/(x2-x1);
}
int n,h,lx,ly,x[N],y[N],p;
double ans;
bool over(int i)
{
	return (lx-x[p])*(long long)(ly-y[i])-(ly-y[p])*(long long)(lx-x[i])<=0;
}
int main()
{
	read(n,h);
	F(i,0,n)read(x[i],y[i]);
	lx=x[n-1];ly=y[n-1]+h;
	p=n-1;
	ans=dis(x[n-1],y[n-1],x[n-2],y[n-2]);
	for(int i=n-2;~--i;)
	{
		if(over(i+1))
		{
			p=i+1;
			if(over(i))ans+=dis(x[i],y[i],x[i+1],y[i+1]);
		}
		else if(over(i))
		{
			double k1,b1,k2,b2;
			line(x[i],y[i],x[i+1],y[i+1],k1,b1);
			line(x[p],y[p],lx,ly,k2,b2);
			double ix=(b2-b1)/(k1-k2),iy=(k1*b2-k2*b1)/(k1-k2);
			ans+=dis(x[i],y[i],ix,iy);
		}
	}
	printf("%.9lf\n",ans);
	/*
	F(i,0,n)printf("A_%d=(%d,%d)\n",i+1,x[i],y[i]);
	F(i,0,n-1)printf("f_%d=segment(A_%d,A_%d)\n",i+1,i+1,i+2);
	printf("B=(%d,%d)\n",lx,ly);
	*/
	return 0;
}