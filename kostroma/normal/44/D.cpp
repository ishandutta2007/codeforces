#include <stdio.h>
#include <math.h>
double a[5000][3],t1,t2,t3,r,R=1000000000;
int main()
{
	int i,j,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%lf%lf%lf",&a[i][0],&a[i][1],&a[i][2]);
	for(i=1;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			t1=sqrt((a[0][0]-a[i][0])*(a[0][0]-a[i][0])+(a[0][1]-a[i][1])*(a[0][1]-a[i][1])+(a[0][2]-a[i][2])*(a[0][2]-a[i][2]));
			t2=sqrt((a[0][0]-a[j][0])*(a[0][0]-a[j][0])+(a[0][1]-a[j][1])*(a[0][1]-a[j][1])+(a[0][2]-a[j][2])*(a[0][2]-a[j][2]));
			t3=sqrt((a[i][0]-a[j][0])*(a[i][0]-a[j][0])+(a[i][1]-a[j][1])*(a[i][1]-a[j][1])+(a[i][2]-a[j][2])*(a[i][2]-a[j][2]));
			r=t1+t2+t3;
			if(r/2<=R)
				{
				R=r/2;
				}
		}
	printf("%.9lf",R);
	return 0;
}