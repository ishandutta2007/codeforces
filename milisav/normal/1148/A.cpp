#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main() {
	scanf("%lld %lld %lld",&a,&b,&c);
	long long t;
	if(a==b) t=a+b;
	else t=2*min(a,b)+1;
	printf("%lld",t+2*c);
	return 0;
}