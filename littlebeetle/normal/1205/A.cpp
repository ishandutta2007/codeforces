#include<cstdio>
const int N=1000002;
int n,i,a[N],k,cnt;
bool usd[N];
int main(){
	scanf("%d",&n);
	if(n%2==0){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(i=1;i<=n;i++){
		k=i*2-1;
		if(i%2==0)
			k++;
		a[++cnt]=k;
		usd[k]=1;
	}
	for(i=1;i<=2*n;i++)
		if(!usd[i])
			a[++cnt]=i;
	for(i=1;i<=cnt;i++)
		printf("%d ",a[i]);
	return 0;
}