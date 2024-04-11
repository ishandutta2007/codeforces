#include<cstdio>
char ch;
int s;
main(){
	while(~(ch=getchar()))
		if(ch==52||ch==55)
			++s;
	puts(s==4||s==7?"YES":"NO");
}