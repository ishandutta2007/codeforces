#include<cstdio>
int n,i;
char s[100];
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i*(i+1)/2<=n;i++)
		printf("%c",s[i*(i+1)/2]);
}