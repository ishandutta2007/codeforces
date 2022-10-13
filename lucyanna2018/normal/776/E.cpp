#include<stdio.h>
long long int x,y;
long long int fai(long long int x){
	long long int res = 1;
	for(long long int i=2; i*i<=x; i++)
		if(x%i==0){
			x /= i;
			res *= (i-1);
			while(x%i==0){
				x/=i;
				res*=i;
			}
		}
	if(x>1){
		res *= (x-1);
	}
	return res;
}
int main(){
	scanf("%I64d%I64d",&x,&y);
	for(y = (y+1)/2; y>0; y--){
		if(x==1)break;
		x = fai(x);
	}
	printf("%I64d\n",x%1000000007);
	return 0;
}