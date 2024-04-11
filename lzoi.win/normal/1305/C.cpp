#include<cstdio>
const int MAXN=1005;
int n,m,a[MAXN];
int ans=1;
int main(){
	scanf("%d%d",&n,&m);
	if(n>m){
		puts("0");
		return 0;
	}
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<=n; j++)
			if(a[i]>a[j]) ans=1ll*ans*(a[i]-a[j])%m;
			else ans=1ll*ans*(a[j]-a[i])%m;
	printf("%d\n",ans);
	return 0;
}