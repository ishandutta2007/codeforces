#include<cstdio>
int T,n,i;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=360;i++)
			if(n*i%180==0&&(n*i/180)<=i-2){
				printf("%d\n",i);
				break;
			}
	}
}