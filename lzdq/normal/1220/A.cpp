#include<cstdio>
int Sum[2],n;
int main(){
	for(scanf("%d",&n);n;n--){
		char ch;
		while((ch=getchar())!='z'&&ch!='e'&&ch!='r'&&ch!='o'&&ch!='n');
		if(ch=='z') Sum[0]++;
		if(ch=='n') Sum[1]++;
	}
	for(;Sum[1];Sum[1]--){
		putchar('1');
		putchar(' ');
	}
	for(;Sum[0];Sum[0]--){
		putchar('0');
		putchar(' ');
	}
	putchar('\n');
	return 0;
}