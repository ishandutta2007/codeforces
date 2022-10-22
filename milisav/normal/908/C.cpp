#include <bits/stdc++.h>
using namespace std;
int n,r;
double t;
double eps=1e-10;
int x[2000];
double d,h,g;
double c[2000];
double a[2000];
int main()
{
	scanf("%d %d",&n,&r);
	t=r;
	for(int i=0;i<n;i++) scanf("%d",&x[i]);
	for(int i=0;i<=1000;i++) c[i]=t;
	t=t*(double(2));
	for(int i=0;i<n;i++)
	{
		a[i]=c[x[i]];
		h=a[i];
		for(int j=-2*r;j<=2*r;j++)
		{
			d=j;
			if(x[i]+j>=0 && x[i]+j<=1000)
			{
				g=h+sqrt(t*t-d*d);
				//cout<<g<<endl;
				if(g>c[x[i]+j]) c[x[i]+j]=g;
			}
		}
		printf("%.8lf ",a[i]);
	}
	return 0;
}