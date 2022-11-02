#include<cstdio>
int n,i,a,s[10002],sum;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		if(a>=1&&a<=n&&!s[a])
		s[a]=1,sum++;
	}
	printf("%d\n",n-sum);
}