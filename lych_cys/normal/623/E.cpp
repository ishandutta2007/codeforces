#include<bits/stdc++.h>
#define ll long long
#define N 70005
#define mod 1000000007
using namespace std;

ll cnt,g[16]; int n,m,bin[N],inv[N],a[N],b[N],c[N],f[N];
void mul(int *a,int *b,int *c,int n){
	if (n<=8){
		memset(g,0,sizeof(g));
		int i,j;
		for (i=0; i<n; i++)
			for (j=0; j<n; j++) g[i+j]+=(ll)a[i]*b[j];
		for (i=0; i<(n<<1); i++) c[i]=g[i]%mod;
		return;
	}
	int mid=n>>1;
	mul(a,b,c,mid); mul(a+mid,b+mid,c+n,mid);
	int i,x[mid],y[mid],z[n];
	for (i=0; i<mid; i++){
		x[i]=(a[i]+a[i+mid])%mod; y[i]=(b[i]+b[i+mid])%mod;
	}
	mul(x,y,z,mid);
	for (i=0; i<n; i++) z[i]-=c[i]+c[i+n];
	for (i=0; i<n; i++) c[i+mid]=((c[i+mid]+z[i])%mod+mod)%mod;
}
int main(){
	scanf("%lld%d",&cnt,&n);
	if (cnt>n){ puts("0"); return 0; }
	m=1; while (m<=n) m<<=1;
	int i,k,x,y;
	bin[0]=1; for (i=1; i<=cnt; i++) bin[i]=(bin[i-1]<<1)%mod;
	inv[0]=inv[1]=1;
	for (i=2; i<m; i++) inv[i]=mod-(ll)inv[mod%i]*(mod/i)%mod;
	for (i=3; i<m; i++) inv[i]=(ll)inv[i-1]*inv[i]%mod;
	for (i=1; i<m; i++) a[i]=inv[i];
	f[0]=1;
	for (k=1; k<=cnt; k<<=1){
		if (k>1){
			x=1; y=bin[k>>1];
			for (i=0; i<m; i++,x=(ll)x*y%mod) b[i]=(ll)a[i]*x%mod;
			mul(a,b,c,m);
			for (i=0; i<m; i++) a[i]=c[i];
		}
		if (cnt&k){
			x=1; y=bin[cnt&k-1];
			for (i=0; i<m; i++,x=(ll)x*y%mod) b[i]=(ll)a[i]*x%mod;
			mul(f,b,c,m);
			for (i=0; i<m; i++) f[i]=c[i];
		}
	}
	int ans=0;
	for (i=0; i<=n; i++) ans=(ans+(ll)f[i]*inv[n-i])%mod;
	for (i=2; i<=n; i++) ans=(ll)ans*i%mod;
	printf("%d\n",ans);
	return 0;
}