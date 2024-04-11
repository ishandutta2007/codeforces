#include<cstdio>
const int N=200002;
int n,i,a[N],f[N],g[N],ans=N;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),f[i]=f[i-1]+(a[i]<0);
	for(i=n;i;i--)
		g[i]=g[i+1]+(a[i]>0);
	for(i=1;i<n;i++)
		ans=min(ans,n-f[i]-g[i+1]);
	printf("%d",ans);
}