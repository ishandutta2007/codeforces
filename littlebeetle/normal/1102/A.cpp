#include<cstdio>
int n;
long long s;
int main(){
	scanf("%d",&n);
	s=1ll*n*(n+1)/2;
	printf("%d",(int)(s%2));
	return 0;
}