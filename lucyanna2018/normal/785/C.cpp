#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int calc(long long int x){
	long long int r = max((long long int)sqrt(x * 2. + .5) - 5, 0LL);
	while(r*(r+1) < 2*x)
		r++;
	return r;
}
int main(){
	scanf("%I64d%I64d",&n,&m);
	if(n <= m){
		printf("%I64d\n",n);
	}else{
		printf("%I64d\n",m + calc(n-m));
	}
	return 0;
}