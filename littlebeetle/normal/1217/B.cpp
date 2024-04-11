#include<cstdio>
int T,n,x,a,b,d,h;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&x);
		a=b=0;
		while(n--){
			scanf("%d%d",&d,&h);
			if(d-h>a)
				a=d-h;
			if(d>b)
				b=d;
		}
		if(a==0&&x>b){
			printf("-1\n");
			continue;
		}
		if(x<=b){
			printf("1\n");
			continue;			
		}
		x-=b;
		printf("%d\n",(x+a-1)/a+1);
	}
}