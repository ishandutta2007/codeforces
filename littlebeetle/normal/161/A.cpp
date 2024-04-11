#include<cstdio>
const int N=100020;
int n,m,x,y,a[N],b[N],p[N],q[N],i,j,k;
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=m;++i)
		scanf("%d",b+i);
	for(i=j=1;i<=n;i++){
		while(j<=m&&a[i]-b[j]>x)
			j++;
		if(j<=m&&a[i]-x<=b[j]&&b[j]<=a[i]+y)
			k++,p[k]=i,q[k]=j,j++;
	}
	printf("%d\n",k);
	for(i=1;i<=k;i++)
		printf("%d %d\n",p[i],q[i]);
	return 0;
}