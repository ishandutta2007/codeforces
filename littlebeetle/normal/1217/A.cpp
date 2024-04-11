#include<cstdio>
int T,a,b,c,x,y;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&a,&b,&c);
		if(a+c<b){
			printf("0\n");
			continue;
		}
		if(a>b+c){
			printf("%d\n",c+1);
			continue;
		}
		y=a+b+c>>1;
		x=a+b+c-y;
		if(x>y)
			printf("%d\n",c-(x-a)+1);
		else
			printf("%d\n",c-(x-a));
	}
}