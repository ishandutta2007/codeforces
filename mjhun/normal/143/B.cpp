#include <bits/stdc++.h>
using namespace std;

char s[128],t[128];
int ns,nt;

int main(){
	bool neg=false;
	char c=getchar();
	if(c=='-')neg=true,c=getchar();
	while(c>='0'&&c<='9')s[ns++]=c,c=getchar();
	if(c=='.'){
		c=getchar();
		while(c>='0'&&c<='9')t[nt++]=c,c=getchar();
	}
	while(nt<2)t[nt++]='0';
	t[2]=0;
	if(neg)putchar('(');
	putchar('$');
	for(int i=0;i<ns;++i){
		if(i&&(ns-i)%3==0)putchar(',');
		putchar(s[i]);
	}
	printf(".%s",t);
	if(neg)putchar(')');
	puts("");
	return 0;
}