#include<cstdio>
int n,T;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		if(n<=4)
			printf("%d\n",4-n);
		else
			printf("%d\n",n%2);
	}
}