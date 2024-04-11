#include<cstdio>
int n,i,s=1<<30;
int main(){
	scanf("%d",&n);
	for(i=1;i*i<=n;i++)
	if(i+(n+i-1)/i<s)
		s=i+(n+i-1)/i;
	printf("%d",s);
	return 0;
}