#include<cstdio>
#include<iostream>
#include<iomanip>

using namespace std;

const double ZERO=1e-12;

inline double getabs(double x)
{
	return (x>=0)?x:-x;
}

inline double det(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}

inline bool line(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return getabs(det(x1-x2,y1-y2,x2-x3,y2-y3))<ZERO;
}

inline bool check(double x1,double y1,double x2,double y2,double x3,double y3)
{
	double a1=y1-y2,b1=y2-y3,c1=2*x2-(x1+2*x2+x3)/2;
	double a2=x2-x1,b2=x3-x2,c2=2*y2-(y1+2*y2+y3)/2;
	double u=(c1*b2-c2*b1)/(a1*b2-a2*b1);
	double px2=(x1+x2)/2+u*(y1-y2),py2=(y1+y2)/2+u*(x2-x1);
	double px1=2*x1-px2,py1=2*y1-py2;
	double px3=2*x2-px2,py3=2*y2-py2;
	double px4=2*x3-px3,py4=2*y3-py3;
	if (line(px1,py1,px2,py2,px3,py3)) return false;
	if (line(px1,py1,px2,py2,px4,py4)) return false;
	if (line(px1,py1,px3,py3,px4,py4)) return false;
	if (line(px2,py2,px3,py3,px4,py4)) return false;
	bool p1=det(px2-px1,py2-py1,px3-px2,py3-py2)>0;
	bool p2=det(px3-px2,py3-py2,px4-px3,py4-py3)>0;
	bool p3=det(px4-px3,py4-py3,px1-px4,py1-py4)>0;
	bool p4=det(px1-px4,py1-py4,px2-px1,py2-py1)>0;
	if (p1==p2&&p2==p3&&p3==p4)
	{
		cout<<"YES"<<endl;
		cout<<setprecision(9)<<fixed<<px1<<" "<<py1<<" "<<px2<<" "<<py2<<" "<<px3<<" "<<py3<<" "<<px4<<" "<<py4<<endl;
		return true;
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while (T--)
	{
		double x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		if (line(x1,y1,x2,y2,x3,y3))
		{
			cout<<"NO"<<endl<<endl;
			continue;
		}
		if (check(x1,y1,x2,y2,x3,y3)) continue;
		if (check(x1,y1,x3,y3,x2,y2)) continue;
		if (check(x2,y2,x1,y1,x3,y3)) continue;
		if (check(x2,y2,x3,y3,x1,y1)) continue;
		if (check(x3,y3,x1,y1,x2,y2)) continue;
		if (check(x3,y3,x2,y2,x1,y1)) continue;
		cout<<"NO"<<endl<<endl;
	}
	return 0;
}