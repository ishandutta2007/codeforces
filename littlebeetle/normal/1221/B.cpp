#include<cstdio>
const int N=1002;
int n,i,j;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++)
			printf("%c",i+j&1?'W':'B');
		printf("\n");
	}
}