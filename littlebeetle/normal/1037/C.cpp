#include<cstdio>
const int N=1000020;
char a[N],b[N];
int n,i,j,k,p;
int main(){
	scanf("%d%s%s",&n,a+1,b+1);
	for(i=1;i<n;i++)
		if(a[i]!=b[i]&&a[i+1]!=b[i+1]&&a[i]!=a[i+1])
			a[i]=b[i],a[i+1]=b[i+1],p++;
	for(i=1;i<=n;i++)
		if(a[i]!=b[i])
			p++;
	printf("%d",p);
	//while(1);
}