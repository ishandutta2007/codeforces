#include<cstdio>
long long k;
int n=1,l=1,p=10;
int main(){
	scanf("%I64d",&k);
	while(k>l){
		k-=l;
		n++;
		if(n==p)
			l++,p*=10;
	}
	l-=k;
	while(l)
		n/=10,l--;
	printf("%d",n%10);
}