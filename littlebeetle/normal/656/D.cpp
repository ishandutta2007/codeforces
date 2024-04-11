#include<cstdio>
int n,p;
int main(){
	scanf("%d",&n);
	while(n){
		if((n&7)==1)
			p++;
		n>>=3;
	}
	printf("%d",p);
}