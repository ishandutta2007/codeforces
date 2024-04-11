#include<cstdio>
char ch,s[11];
main(){
	scanf("%s %c",s,&ch);
	putchar(s[0]);
	for(register int i=1;s[i];++i)
		if(s[i]<ch)putchar(s[i]);
		else break;
	putchar(ch);
}