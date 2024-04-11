#include<stdio.h>
int n;
bool isprime(int x){
	for(int i=2; i*i<=x; i++)
		if(x%i==0)
			return false;
	return true;
}
int main(){
	scanf("%d",&n);
	printf("%d\n",n<=2?1:2);
	for(int i=2; i<=n+1; i++)
		printf("%d%c",isprime(i)?1:2,i<=n?' ':'\n');
	return 0;
}