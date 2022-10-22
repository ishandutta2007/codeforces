#include<bits/stdc++.h>
using namespace std;
long long int n;
long long int m;
long long int x,d;
long long int s=0;
long long int arith(long long int g) {
	long long int  h=g-1;
	return d*h*(h+1)/2;
}
int main()
{
	scanf("%lld %lld",&n,&m);
	for(int i=0;i<m;i++) {
		scanf("%lld %lld",&x,&d);
		s+=n*x;
		if(d>=0) s+=arith(n);
		else {
			if(n%2==1) s+=2*arith((n+1)/2);
			else s+=arith(n/2)+arith(n/2+1);
		}
	}
	double sol=s;
	double rn=n;
	sol=sol/rn;
	printf("%.9lf",sol);
	return 0;
}