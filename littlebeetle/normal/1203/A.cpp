#include<cstdio>
const int N=1002;
int q,n,a[N],i;
bool check1(){
	for(i=1;i<=n;i++)
		if((a[i+1]-a[i]+n)%n!=1)
			return 0;
	return 1;
}
bool check2(){
	for(i=1;i<=n;i++)
		if((a[i+1]-a[i]+n)%n!=n-1)
			return 0;
	return 1;
}
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		a[n+1]=a[1];
		if(check1()||check2())
			printf("YES\n");
		else
			printf("NO\n");
	}
}