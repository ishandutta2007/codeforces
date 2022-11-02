#include<cstdio>
int T,a,b,c,d,k,x,y;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
		x=(a+c-1)/c;
		y=(b+d-1)/d;
		if(x+y<=k)
			printf("%d %d\n",x,k-x);
		else
			printf("-1\n");
	}
}