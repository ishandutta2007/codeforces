#include<cstdio>
int n,m,a,b,x,y,i;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a>x)
			x=a;
	}
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		scanf("%d",&b);
		if(b>y)
			y=b;
	}
	printf("%d %d",x,y);
}