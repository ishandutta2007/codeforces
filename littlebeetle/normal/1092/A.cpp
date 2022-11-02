#include<cstdio>
int T,n,k,i;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++)
			printf("%c",97+i%k);
		printf("\n");
	}
	return 0;
}