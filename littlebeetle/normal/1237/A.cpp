#include<cstdio>
int n,i,a,opt;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a%2==0)
			printf("%d\n",a/2);
		else{
			if(opt==0){
				opt=1;
				if(a>0)
					printf("%d\n",a/2);
				else
					printf("%d\n",-((-a+1)/2));
			}
			else{
				opt=0;
				if(a>0)
					printf("%d\n",(a+1)/2);
				else
					printf("%d\n",-((-a)/2));				
			}
		}
	}
//	while(1);
}