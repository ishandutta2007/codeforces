#include <bits\stdc++.h>
using namespace std;
struct inter
{
	int v;
	double d;
};
double epsilon=1e-20;
bool operator < (inter x,inter y)
{
	return y.d-x.d>epsilon || (x.d-y.d<epsilon && x.v<y.v);
}
double x[300000];
double y[300000];
double vx[300000];
double vy[300000];
int n;
int u=0;
int k=0;
double t;
inter a[600000];
int main()
{
	double xi1,xi2,yi1,yi2;
	scanf("%d",&n);
	scanf("%lf %lf %lf %lf",&xi1,&yi1,&xi2,&yi2);
	bool m=true;
	for(int i=0;i<n;i++)
	{
		scanf("%lf %lf %lf %lf",&x[i],&y[i],&vx[i],&vy[i]);
		if(fabs(vx[i])<epsilon)
		{
			if(xi1-x[i]>-epsilon) m=false;
			if(x[i]-xi2>-epsilon) m=false;
		}
		else
		{
			if(vx[i]<-epsilon) swap(xi1,xi2);
			t=(xi1-x[i])/vx[i];
			if(t<-epsilon) a[k].d=0;
			else a[k].d=t;
			a[k].v=1;
			k++;
			t=(xi2-x[i])/vx[i];
			if(t<-epsilon) m=false;
			else
			{
				a[k].d=t;
				a[k].v=-1;
				k++;
			}
			if(vx[i]<-epsilon) swap(xi1,xi2);
			u++;
		}
		if(fabs(vy[i])<epsilon)
		{
			if(yi1-y[i]>-epsilon) m=false;
			if(y[i]-yi2>-epsilon) m=false;
		}
		else
		{
			if(vy[i]<-epsilon) swap(yi1,yi2);
			t=(yi1-y[i])/vy[i];
			//cout<<yi1<<" "<<y[i]<<" "<<vy[i]<<" "<<t<<endl;
			if(t<-epsilon) a[k].d=0;
			else a[k].d=t;
			a[k].v=1;
			k++;
			t=(yi2-y[i])/vy[i];
			//cout<<y[i]<<" "<<yi2<<" "<<vy[i]<<" "<<t<<endl;
			if(t<-epsilon) m=false;
			else
			{
				a[k].d=t;
				a[k].v=-1;
				k++;
			}
			if(vy[i]<-epsilon) swap(yi1,yi2);
			u++;
		}
	}
	if(!m)
	{
		printf("-1");
		return 0;
	}
	sort(a,a+k);
	//cout<<u<<endl;
	if(u==0)
	{
		printf("%.8lf",0);
		return 0;
	}
	int b=0;
	for(int i=0;i<k;i++)
	{
		//cout<<a[i].v<<" "<<a[i].d<<endl;
		b+=a[i].v;
		if(b==u)
		{
			printf("%.8lf",a[i].d);
			return 0;
		}
	}
	printf("-1");
	return 0;
}