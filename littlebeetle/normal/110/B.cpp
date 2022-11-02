#include<cstdio>
int n,i;
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++)
		printf("%c",97+i%4);
}