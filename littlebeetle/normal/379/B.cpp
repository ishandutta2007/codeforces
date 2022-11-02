#include<cstdio>
const int N=100002;
int n,i,a[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++){
		while(a[i]--)
			printf("PRL");
		printf("R");
	}
	while(a[i]--)
		printf("PLR");
}