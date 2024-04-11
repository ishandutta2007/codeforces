#include<stdio.h>
#define int64 long long int
int64 calc(int64 x){
	int64 res=x;
	while(x){
		res -= x%10;
		x/=10;
	}
	return res;
}
int main(){
	int64 n,s;
	scanf("%I64d%I64d",&n,&s);
	int64 lo = 1, hi = n+1;
	while(lo!=hi){
		int64 mi = (lo+hi)/2;
		if(calc(mi) < s)
			lo = mi+1;
		else
			hi = mi;
	}
	printf("%I64d\n",n-lo+1);
	return 0;
}