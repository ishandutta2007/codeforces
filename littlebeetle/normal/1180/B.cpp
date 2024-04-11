#include<cstdio>
const int N=100002;
int n,i,k,a[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>=0)
			a[i]=-a[i]-1;
	}
	if(n%2==0){
		for(i=1;i<=n;i++)
			printf("%d ",a[i]);
		return 0;
	}
	k=0;
	for(i=1;i<=n;i++)
		if(a[i]<a[k])
			k=i;
	a[k]=-a[k]-1;
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}