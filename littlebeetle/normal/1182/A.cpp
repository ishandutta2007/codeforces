#include<cstdio>
int n;
int main(){
	scanf("%d",&n);
	printf("%d",n%2?0:1<<(n/2));
}