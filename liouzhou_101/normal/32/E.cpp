#include<cstdio>
#include<iostream>

using namespace std;

long double xv,yv,xp,yp,xw1,yw1,xw2,yw2,xm1,ym1,xm2,ym2;

long double det(long double x1,long double y1,long double x2,long double y2)
{
	return x1*y2-x2*y1;
}

bool parallel(long double ax1,long double ay1,long double ax2,long double ay2,long double bx1,long double by1,long double bx2,long double by2)
{
	return det(ax1-ax2,ay1-ay2,bx1-bx2,by1-by2)==0;
}

bool between(long double px,long double py,long double x1,long double y1,long double x2,long double y2)
{
	if ((px-x1)*(px-x2)+(py-y1)*(py-y2)>0)
		return false;
	else
		return true;
}

void get_equation(long double x1,long double y1,long double x2,long double y2,long double &A,long double &B,long double &C)
{
	A=y1-y2;
	B=x2-x1;
	C=A*x1+B*y1;
}

void solve_equation(long double a,long double b,long double c,long double d,long double e,long double f,long double &x,long double &y)
{
	x=(c*e-b*f)/(a*e-b*d);
	y=(c*d-a*f)/(b*d-a*e);
}

bool intersect(long double ax1,long double ay1,long double ax2,long double ay2,long double bx1,long double by1,long double bx2,long double by2,long double &px,long double &py)
{
	if (parallel(ax1,ay1,ax2,ay2,bx1,by1,bx2,by2))
	{
		if (!parallel(ax1,ay1,bx1,by1,ax1,ay1,bx2,by2))
			return false;
		if (between(ax1,ay1,bx1,by1,bx2,by2)||between(ax2,ay2,bx1,by1,bx2,by2)||
			between(bx1,by1,ax1,ay1,ax2,ay2)||between(bx2,by2,ax1,ay1,ax2,ay2))
			return true;
		else
			return false;
	}
	else
	{
		long double aA,aB,aC,bA,bB,bC;
		get_equation(ax1,ay1,ax2,ay2,aA,aB,aC);
		get_equation(bx1,by1,bx2,by2,bA,bB,bC);
		solve_equation(aA,aB,aC,bA,bB,bC,px,py);
		if (between(px,py,ax1,ay1,ax2,ay2)&&between(px,py,bx1,by1,bx2,by2))
			return true;
		else
			return false;
	}
}

void symmetry_point(long double x0,long double y0,long double x1,long double y1,long double x2,long double y2,long double &px,long double &py)
{
	long double A,B,C;
	get_equation(x1,y1,x2,y2,A,B,C);
	long double pA=B,pB=-A,pC=B*x0-A*y0;
	solve_equation(pA,pB,pC,A,B,2*C-A*x0-B*y0,px,py);
}

void work()
{
	long double px,py;
	if (!intersect(xv,yv,xp,yp,xw1,yw1,xw2,yw2,px,py)&&(!intersect(xv,yv,xp,yp,xm1,ym1,xm2,ym2,px,py)||parallel(xv,yv,xp,yp,xm1,ym1,xm2,ym2)))
	{
		puts("YES");
		return;
	}
	if (parallel(xv,yv,xp,yp,xm1,ym1,xm2,ym2)&&intersect(xv,yv,xp,yp,xm1,ym1,xm2,ym2,px,py))
	{
		puts("NO");
		return;
	}
	long double pxv,pyv;
	symmetry_point(xv,yv,xm1,ym1,xm2,ym2,pxv,pyv);
	if (intersect(pxv,pyv,xp,yp,xm1,ym1,xm2,ym2,px,py))
	{
		long double tx,ty;
		if (!intersect(px,py,xv,yv,xw1,yw1,xw2,yw2,tx,ty)&&!intersect(px,py,xp,yp,xw1,yw1,xw2,yw2,tx,ty))
		{
			puts("YES");
			return;
		}
	}
	puts("NO");
}

int main()
{
	cin>>xv>>yv>>xp>>yp>>xw1>>yw1>>xw2>>yw2>>xm1>>ym1>>xm2>>ym2;
	work();
	return 0;
}