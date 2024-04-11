#include<cstdio>
const int N=1000002;
int n,m,i,j,k,a[N],cnt[N],p[N];
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]<=m)
			cnt[a[i]]++;
	}
	for(i=1;i<=m;i++)
		if(cnt[i])
			for(j=i;j<=m;j+=i)
				p[j]+=cnt[i];
	k=1;
	for(i=2;i<=m;i++)
		if(p[i]>p[k])
			k=i;
	printf("%d %d\n",k,p[k]);
	for(i=1;i<=n;i++)
		if(k%a[i]==0)
			printf("%d ",i);
	//while(1);
}