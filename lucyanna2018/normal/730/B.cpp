#include<stdio.h>
char s[9];
int n,T;
int small[99],large[99];
int main(){
	int _;
	for(scanf("%d",&_); _--;){
		scanf("%d",&n);
		T = 0;
		for(int i=1; i<=n/2; i++){
			printf("? %d %d\n",i*2-1,i*2);
			fflush(stdout);
			scanf("%s",s);
			if(*s == '>'){
				large[T] = i*2-1;
				small[T] = i*2;
			}else{
				large[T] = i*2;
				small[T] = i*2-1;
			}
			T++;
		}
		if(n%2){
			small[T] = large[T] = n;
			T++;
		}
		int x = small[0];
		for(int i=1; i<T; i++){
			printf("? %d %d\n",x,small[i]);
			fflush(stdout);
			scanf("%s",s);
			if(*s == '>')
				x = small[i];
		}
		int y = large[0];
		for(int i=1; i<T; i++){
			printf("? %d %d\n",y,large[i]);
			fflush(stdout);
			scanf("%s",s);
			if(*s == '<')
				y = large[i];
		}
		printf("! %d %d\n",x,y);
		fflush(stdout);
	}
	return 0;
}