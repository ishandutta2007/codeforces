#include<cstdio>
int n,i,k,s=1;
int main(){
	scanf("%d",&n);
	while(--n)
		k+=4,
		s+=k;
	printf("%d",s);
}