# include <iostream>
# include <cstdio>
# include <cmath>
# include <algorithm>
# define PI 3.14159265
using namespace std;

int n;
double a[100010];
double ans=0,x,y;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lf%lf",&x,&y);
		a[i]=atan2(y,x);
	}
	sort(a,a+n);
	for(int i=1;i<n;i++)
		if(a[i]-a[i-1]>ans)ans=a[i]-a[i-1];
	if(a[0]-a[n-1]+2*PI>ans)ans=a[0]-a[n-1]+2*PI;
	printf("%lf",360-ans*180/PI);
}