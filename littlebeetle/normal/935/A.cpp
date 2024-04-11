#include<cstdio>
int n,s,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++)
		if((n-i)%i==0)
			s++;
	printf("%d",s);
}