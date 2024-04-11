#include<cstdio>
#include<cstring>
char s[100001],t[100001];
main(){
	scanf("%s%s",s,t);
	int x=strlen(s),y=strlen(t);
	printf("%d",strcmp(s,t)?(x>y?x:y):-1);
}