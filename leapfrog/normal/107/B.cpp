#include<bits/stdc++.h>
using namespace std;
int n,m,h,s,a[1005];double r;
int main()
{
	scanf("%d%d%d",&n,&m,&h),s=0;
	for(int i=1;i<=m;i++) scanf("%d",a+i),s+=a[i];
	if(s<n) return puts("-1"),0;else r=1;
	for(int i=0;i<n-1;i++) r*=1.0*(s-a[h]-n+2+i)/(s-n+i+1);
	return printf("%.8lf",1-r),0;
}