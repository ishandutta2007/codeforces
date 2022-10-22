#include<bits/stdc++.h>
using namespace std;
int a[200000];
int n,m,k;
long long x,y,p,q;
int main() {
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	sort(a,a+n);
	x=m/(k+1);
	y=m-x;
	p=a[n-1];
	q=a[n-2];
	printf("%lld",x*q+y*p);
	return 0;
}