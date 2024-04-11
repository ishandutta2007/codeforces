#include<cstdio>
const int N=1000002;
int n,x,i,l,a[N];
bool f[N];
int main(){
	scanf("%d%d",&n,&x);
	f[0]=f[x]=1;
	while(1){
		while(f[i]&&i<(1<<n))
			i++;
		if(i==(1<<n))
			break;
		f[i]=f[i^x]=1;
		a[++l]=i;
	}
	for(i=l;i;i--)
		a[i]^=a[i-1];
	printf("%d\n",l);
	for(i=1;i<=l;i++)
		printf("%d ",a[i]);
}