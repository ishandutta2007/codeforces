#include<cstdio>
const int N=100002;
int n,i,a[N],sum;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]==0)
			sum++;
	}
	if(n==1){
		if(sum==0)
			printf("YES");
		else
			printf("NO");
	}
	else{
		if(sum==1)
			printf("YES");
		else
			printf("NO");
		}
}