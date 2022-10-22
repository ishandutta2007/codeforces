#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=3605,mod=998244353;
int n,m,k;
int a[MAXN],b[MAXN];
ll fac[MAXN],inv[MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int f[MAXN][MAXN],g[MAXN][MAXN],ans;
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++)
		a[i]=1;
	for(int i=1; i<=m; i++)
		b[i]=1;
	while(k--){
		int x1,y1,x2,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		a[x1]=a[x2]=0;
		b[y1]=b[y2]=0;
	}
	for(int i=1; i<=n; i++)
		*a+=a[i];
	for(int i=1; i<=m; i++)
		*b+=b[i];
	fac[0]=inv[0]=1;
	for(int i=1; i<=max(n,m); i++)
		inv[i]=Fstpw(fac[i]=fac[i-1]*i%mod,mod-2);
	f[0][0]=f[1][0]=1;
	for(int i=2; i<=n; i++){
		memcpy(f[i],f[i-1],sizeof(f[i]));
		if(a[i-1]&&a[i]){
			for(int j=1; j<=n; j++)
				f[i][j]=(f[i][j]+f[i-2][j-1])%mod;
		}
	}
	g[0][0]=g[1][0]=1;
	for(int i=2; i<=m; i++){
		memcpy(g[i],g[i-1],sizeof(g[i]));
		if(b[i-1]&&b[i]){
			for(int j=1; j<=n; j++)
				g[i][j]=(g[i][j]+g[i-2][j-1])%mod;
		}
	}
	for(int i=0; i<=min(*a,*b/2); i++)
		for(int j=0; j<=min(*b,*a/2); j++)
			if(*a>=i+j*2&&*b>=i*2+j) ans=(ans+1ll*f[n][j]*g[m][i]%mod*fac[*a-j*2]%mod*inv[*a-j*2-i]%mod*fac[*b-i*2]%mod*inv[*b-i*2-j])%mod;
	printf("%d\n",ans);
	return 0;
}