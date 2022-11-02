#include<cstdio>
int T,a,b;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&a,&b);
		if(a>=4)
			printf("YES\n");
		else{
			if(a==3||a==2){
				if(b<=3)
					printf("YES\n");
				else
					printf("NO\n");
			}
			if(a==1){
				if(b==1)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
}