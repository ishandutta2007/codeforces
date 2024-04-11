#include<bits/stdc++.h>
using namespace std;
int t;
long long x,y;
int main() {
	scanf("%d",&t);
	while(t--) {
		scanf("%lld %lld",&x,&y);
		long long n=0;
		if(y<x) n=x+y;
		else {
			if(y<x*3) n=(x+y)/2;
			else n=y/2+y/2/x*x;
		}
		assert(n%x==y%n);
		printf("%lld\n",n);
	}
	return 0;
}