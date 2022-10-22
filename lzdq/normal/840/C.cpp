#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=305,mod=1e9+7;
int n,a[MAXN],pre[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
int b[MAXN],f[MAXN],g[MAXN][MAXN],h[MAXN],m;
ll fac[MAXN];
int ans;
int main(){
	//freopen("square.in","r",stdin);
	//freopen("ex.in","r",stdin);
	//freopen("square.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),pre[i]=i;
	for(int i=1; i<=n; i++)
		for(int j=1; j<i; j++){
			ll t=sqrt(1ll*a[i]*a[j])+0.5;
			if(t*t==1ll*a[i]*a[j]) pre[fnd(i)]=fnd(j);
		}
	for(int i=1; i<=n; i++)
		++b[fnd(i)];
	g[0][0]=1;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
			g[i][j]=(g[i-1][j-1]+g[i-1][j]*(i+j-1ll))%mod;
	/*
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++)
			printf("%d ",g[i][j]);
		puts("");
	}
	*/
	f[0]=1;
	for(int i=1; i<=n; i++){
		int t=b[i];
		if(!t) continue;
		memset(h,0,sizeof(h));
		for(int j=0; j<=m; j++)
			for(int k=0; k<=t; k++)
				h[j+k]=(h[j+k]+1ll*f[j]*g[t][k])%mod;
		memcpy(f,h,sizeof(h));
		m+=t;
	}
	fac[0]=1;
	for(int i=1; i<=n; i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=0; i<n; i++)
		ans=(ans+fac[n-i]*f[n-i]%mod*(i&1?mod-1:1))%mod;
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}