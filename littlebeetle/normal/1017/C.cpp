#include<cstdio>
int n,i,j,k;
int main(){
	scanf("%d",&n);
	while(k*k<n)k++;
		j=n/k;
	for(i=0;i<k*j;i++)
		printf("%d ",(i/k+1)*k-i%k);
	for(i=n;i>k*j;i--)
		printf("%d ",i);
}
//