#include<cstdio>
int q,s;
long long n;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%lld",&n);
		s=0;
		while(n%5==0)
			n=n/5*4,s++;
		while(n%3==0)
			n=n/3*2,s++;
		while(n%2==0)
			n=n/2,s++;
		if(n==1)
			printf("%d\n",s);
		else
			printf("-1\n");
	}
}