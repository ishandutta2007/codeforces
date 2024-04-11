#include<cstdio>
#include<algorithm>
#include<cstring>
typedef long long ll;
using namespace std;
const int MAXN=85;
int n,k,mod;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll fac[MAXN],inv[MAXN];
ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int f[MAXN][MAXN],g[MAXN][MAXN],al[MAXN][MAXN],ans;
ll upw(int x,int y){
	ll res=inv[y];
	for(int i=0; i<y; i++)
		res=res*(x+i)%mod;
	return res;
}
ll dwp(int x,int y){
	ll res=1;
	for(int i=0; i<y; i++)
		res=res*(x-i+mod)%mod;
	return res;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d%d",&n,&k,&mod);
	fac[0]=1;
	for(int i=1; i<=80; i++)
		fac[i]=fac[i-1]*i%mod;
	inv[80]=Fstpw(fac[80],mod-2);
	for(int i=80; i; i--)
		inv[i-1]=inv[i]*i%mod;
	for(int i=0; i<=n; i++)
		for(int j=0; j<=k; j++)
			for(int k=0; k<=j; k++){
				al[i][j]=(al[i][j]+C(j,k)*Fstpw(2,i*k)%mod*(j-k&1?mod-1:1))%mod;
				g[i][j]=(g[i][j]+C(j,k)*dwp(Fstpw(2,k)-1,i)%mod*(j-k&1?mod-1:1))%mod;
			}
	for(int i=1; i<=n; i++)
		for(int j=0; j<=k; j++)
			for(int x=0; x<i; x++)
				for(int y=0; y<j; y++){
					if(n&1&&i==n&&x+1==i) continue;
					f[i][j]=(f[i][j]+(al[x][y]-f[x][y]+mod)*C(i,x)%mod*C(j,y)%mod*g[i-x][j-y]%mod*Fstpw(2,y*(i-x)))%mod;
				}
	for(int i=0; i<=k; i++)
		ans=(ans+(al[n][i]-f[n][i]+mod)*C(k,i)%mod+mod)%mod;
	printf("%d\n",ans);
	return 0;
}