#include<cstdio>
int x;
int main(){
	scanf("%d",&x);
	while(x){
		if(x%10==1){
			x/=10;
			continue;
		}
		if(x%100==14){
			x/=100;
			continue;
		}
		if(x%1000==144){
			x/=1000;
			continue;
		}
		printf("NO");
		return 0;
	}
	printf("YES");
}