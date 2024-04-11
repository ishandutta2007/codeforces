#include<cstdio>
const int N=300002;
typedef long long ll;
ll n,x,i,a[N],s[N],f[N],g[N],ans,p;
ll max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	scanf("%I64d%I64d",&n,&x);
	for(i=1;i<=n;i++)
		scanf("%I64d",a+i),s[i]=s[i-1]+a[i];
	for(i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
		if(f[i]<0)
			f[i]=0;
	}
	for(i=n;i;i--){
		g[i]=g[i+1]+a[i];
		if(g[i]<0)
			g[i]=0;
	}
	for(i=1;i<=n;i++){
		p=max(p,-s[i]*x+f[i]);
		ans=max(ans,s[i]*x+g[i+1]+p);
	}
	printf("%I64d",ans);
	return 0;
}