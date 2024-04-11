#include <bits\stdc++.h>
using namespace std;
int n;
double epsilon=1e-15;
int x[400000];
int y[400000];
double d;
double pi=atan2(-1,0);
double bc(int i,int j,int k)
{
	double x1,x2,x3,y1,y2,y3;
	x1=x[i];
	y1=y[i];
	x2=x[j];
	y2=y[j];
	x3=x[k];
	y3=y[k];
	if(x[i]==x[k])
	{
		return fabs(x2-x1);
	}
	double ki,n1,n2;
	ki=(y3-y1)/(x3-x1);
	n1=y3-x3*ki;
	n2=y2-x2*ki;
	//cout<<ki<<" "<<n1<<" "<<n2<<endl;
	double dn=fabs(n1-n2);
	//cout<<dn<<endl;
	double alfa=atan(ki);
	if(alfa-pi>epsilon) alfa=alfa-pi;
	alfa=pi-alfa;
	//cout<<alfa<<endl;
	//cout<<sin(alfa)<<endl;
	return fabs(dn*cos(alfa));
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	d=bc(0,1,2);
	//cout<<d<<endl;
	int j,k;
	double di;
	for(int i=0;i<n;i++)
	{
		j=i+1;
		if(j==n) j=0;
		k=j+1;
		if(k==n) k=0;
		di=bc(i,j,k);
		if(di-d<epsilon) d=di;
	}
	d=d/double(2.00);
	printf("%.8lf",d);
	return 0;
}