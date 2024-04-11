#include<cstdio>
char c;
int s,t;
main(){
	while(~(c=getchar()))
		switch(c){
			case '-':++s;break;
			case 'o':++t;break;
		}
	puts(!t||s%t==0?"YES":"NO");
}