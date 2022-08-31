#include<cstdio>
#include<cmath>
#include<iostream>

using namespace std;

double Ax,Ay,Az,vx,vy,vz,R;
int n,m;
double ans=1e20;

void check(double x0,double y0,double z0,double r0)
{
	x0=Ax-x0;
	y0=Ay-y0;
	z0=Az-z0;
	r0+=R;
	double A=vx*vx+vy*vy+vz*vz;
	double B=2*(x0*vx+y0*vy+z0*vz);
	double C=x0*x0+y0*y0+z0*z0-r0*r0;
	double s=B*B-4*A*C;
	if (s<0) return;
	s=sqrt(s);
	double t1=(-B+s)/2/A,t2=(-B-s)/2/A;
	if (t1>=0) ans=min(ans,t1);
	if (t2>=0) ans=min(ans,t2);
}

int main()
{
	cin>>Ax>>Ay>>Az>>vx>>vy>>vz>>R;
	cin>>n;
	while (n--)
	{
		double x0,y0,z0,r0;
		cin>>x0>>y0>>z0>>r0>>m;
		check(x0,y0,z0,r0);
		while (m--)
		{
			double tx,ty,tz;
			cin>>tx>>ty>>tz;
			check(x0+tx,y0+ty,z0+tz,0);
		}
	}
	if (ans==1e20)
		puts("-1");
	else
		printf("%.10lf\n",ans);
	return 0;
}