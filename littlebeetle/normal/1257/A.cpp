#include<cstdio>
int T,n,x,a,b;
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%d",&n,&x,&a,&b);
		if(a>b)
			swap(a,b);
		if(a-1>=x)
			a-=x,x=0;
		else
			x-=(a-1),a=1;
		if(n-b>=x)
			b+=x;
		else
			b=n;
		printf("%d\n",b-a);
	}
}