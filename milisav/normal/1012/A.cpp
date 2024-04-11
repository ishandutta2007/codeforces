#include<bits/stdc++.h>
using namespace std;
int n;
int a[300000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<2*n;i++) scanf("%d",&a[i]);
	sort(a,a+2*n);
	long long int x,y,p,t;
	x=a[n-1]-a[0];
	y=a[2*n-1]-a[n];
	t=a[2*n-1]-a[0];
	p=x*y;
	for(int i=n-1;i<2*n;i++) p=min(p,t*(a[i]-a[i-(n-1)]));
	printf("%lld",p);
	return 0;
}