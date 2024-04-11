#include<cstdio>
const int N=10002;
int n,i,m,k,a[N],b[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	b[++m]=a[1];
	for(i=2;i<=n;i++)
		if(gcd(a[i],b[m])!=1){
			k++;
			b[++m]=1;
			b[++m]=a[i];
		}
		else
			b[++m]=a[i];
	printf("%d\n",k);
	for(i=1;i<=m;i++)
		printf("%d ",b[i]);
}