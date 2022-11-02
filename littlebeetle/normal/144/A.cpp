#include<cstdio>
const int N=100002;
int n,i,a[N],x,y;
int main(){
	scanf("%d",&n);
	a[y=n+1]=1<<30;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>a[x])x=i;
		if(a[i]<=a[y])y=i;
	}
	if(x<y)
		printf("%d",x-1+n-y);
	else
		printf("%d",x-1+n-y-1);
}