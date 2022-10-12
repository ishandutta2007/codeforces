#include<stdio.h>
int main(){
	int L,R,X,Y,K;
	scanf("%d%d%d%d%d",&L,&R,&X,&Y,&K);
	for(long long int i=X; i<=Y; i++)
		if(L <= i * K && i * K <= R){
			puts("YES");
			return 0;
		}
	puts("NO");
	return 0;
}