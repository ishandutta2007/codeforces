#include<cstdio>
const int N=200002;
int n,k,i,a[N];
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%1d",a+i);
	if(n==1){
		if(k)
			printf("0");
		else
			printf("%d",a[1]);
		return 0;
	}
	if(a[1]>1&&k)
		a[1]=1,k--;
	for(i=2;i<=n&&k;i++){
		if(a[i])
			a[i]=0,k--;
	}
	for(i=1;i<=n;i++)
		printf("%d",a[i]);
//	while(1);
}