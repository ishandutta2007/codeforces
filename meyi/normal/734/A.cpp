#include<cstdio>
int a,b,c;
main(){
	while(~(c=getchar()))
		switch(c){
			case 'A':++a;break;
			case 'D':++b;break;
		}
	puts(a>b?"Anton":b>a?"Danik":"Friendship");
}