#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long n,k;
long long gcd(long long x,long long y) {
	if(y==0) return x;
	return gcd(y,x%y);
}
long long steps(long long fs,long long se) {
	long long s=fs;
	long long l=se-fs;
	l%=(n*k);
	if(l<=0) l=l+n*k;
	return n*k/gcd(n*k,l);
}
int main()
{
	scanf("%lld %lld",&n,&k);
	scanf("%lld %lld",&a,&b);
	long long x=-1;
	long long y=-1;
	long long t;
	for(long long i=0;i<n;i++) {
		t=steps(1+a,i*k+1+b);
		if(x==-1 || t<x) x=t;
		if(t>y) y=t;
		t=steps(1+a,i*k+k+1-b);
		if(x==-1 || t<x) x=t;
		if(t>y) y=t;
		t=steps(k+1-a,i*k+1+b);
		if(x==-1 || t<x) x=t;
		if(t>y) y=t;
		t=steps(k+1-a,i*k+k+1-b);
		if(x==-1 || t<x) x=t;
		if(t>y) y=t;
	}
	printf("%lld %lld",x,y);
	return 0;
}