#include<stdio.h>
const int L = 20000;
bool solve(){
	int A = 0,t,x;
	char s[9];
	for(scanf("%d",&t); t--;){
		scanf("%d%s",&x,s);
		if(A == 0){
			if(*s != 'S')return false;
			A += x;
		}else
		if(A == L){
			if(*s != 'N')return false;
			A -= x;
		}else{
			if(*s == 'S') A += x;else
			if(*s == 'N') A -= x;
		}
		if(A < 0 || A > L)
			return false;
	}
	return A == 0;
}
int main(){
	puts(solve()?"YES":"NO");
	return 0;
}