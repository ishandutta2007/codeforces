#include<cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
main(){
	for(int i=21;i<51;++i)
		putchar(((min(i,25)+i)%(2+i%3)>0)|48),putchar(10);
}