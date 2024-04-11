#include<bits/stdc++.h>
using namespace std;
int n;
double m;
double a[2005];
double b[2005];
double epsilon=1e-6;
bool pos(double t)
{
	for(int i=0;i<n;i++) {
		t-=(m+t)/a[i];
		if(t<0) return false;
		t-=(m+t)/(b[i+1]);
		if(t<0) return false;
	}
	return true;
}
int main()
{
	scanf("%d %lf",&n,&m);
	for(int i=0;i<n;i++) scanf("%lf",&a[i]);
	for(int i=0;i<n;i++) scanf("%lf",&b[i]);
	a[n]=a[0];
	b[n]=b[0];
	double l=0,r=2000000001,mid;
	while((r-l)/max(1.00,l)>epsilon) {
		mid=(l+r)/2.00;
		if(pos(mid)) r=mid;
		else l=mid;
	}
	if(l>1000000000) printf("-1");
	else printf("%.7lf",l);
	return 0;
}