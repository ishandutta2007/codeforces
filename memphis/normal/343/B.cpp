#include<cstdio>
int l; 
char ch,s[1000001];
int main(){
	while((scanf("%c",&ch)^-1)&&(ch!='\n')) 
		if(l==0||ch!=s[l])s[++l]=ch; else --l;
	if(l==0)puts("Yes");else puts("No");
}