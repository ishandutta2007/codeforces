#include<cstdio>
int n,i,t=1;
int main(){
	scanf("%d",&n);
	while(n>3){
		for(i=1;i<=n-n/2;i++)
			printf("%d ",t);
		n=n/2;
		t*=2;
	}
	if(n==1){
		printf("%d",t);
		return 0;//
	}
	if(n==2){
		printf("%d %d",t,t*2);
		return 0;
	}
	if(n==3){
		printf("%d %d %d",t,t,t*3);
		return 0;
	}
	return 0;
}