#include<cstdio>
long long k;
long long i,j,x,l,n;
int main(){
	scanf("%I64d",&k);
	for(i=1,j=1;i<=11;i++,j*=10)
		if(j*9*i>=k){
			n=j+(k-1)/i;
			k-=(k-1)/i*i;
			l=i;
			break;
		}
		else
			k-=j*9*i;
	
	l-=k;
	while(l)
		n/=10,l--;
	printf("%I64d",n%10);
}