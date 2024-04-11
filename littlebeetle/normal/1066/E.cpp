#include<cstdio>
const int N=200002,M=998244353;
int n,m,a[N],b[N],f[N],s[N],i;
long long ans;
int main(){
	scanf("%d%d",&n,&m);
	for(i=n-1;i>=0;i--)
		scanf("%1d",a+i);
	for(i=m-1;i>=0;i--)
		scanf("%1d",b+i);
	for(f[0]=1,i=1;i<n;i++)
		f[i]=f[i-1]*2%M;
	for(i=m;i>=0;i--)
		s[i]=s[i+1]+b[i],
		ans=(ans+1ll*s[i]*a[i]*f[i])%M;
	printf("%lld",ans);
		
}