#include<cstdio>
#include<cctype>
char s[101];
int l;
main(){
	while(~(s[++l]=getchar()))s[l]=tolower(s[l]);
	while(!isalpha(s[l]))--l;
	for(int i=1;i<=l;++i)
		switch(s[i]){
			case 'a':case 'e':case 'i':case 'o':case 'u':case 'y':break;
			default:putchar('.');putchar(s[i]);
		}
}