#include<cstdio>
const int N=200002;
int n,i,a[N],b,s,f[N],d[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),f[i]=1,d[a[i]]=i;
	for(i=1;i<=n;i++){
		scanf("%d",&b);
		b=d[b];s=0;
		while(f[b])
			f[b--]=0,s++;
		printf("%d ",s);
	}
}