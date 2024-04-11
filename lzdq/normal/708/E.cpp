#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1505,mod=1e9+7;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int n,m,k,p;
int s,q[MAXN],f[MAXN][MAXN][2],g[MAXN];
int s0[MAXN],s1[MAXN],sum[MAXN];
int main(){
	//freopen("in","r",stdin);
	scanf("%d%d",&n,&m);
	int p1,p2;
	scanf("%d%d",&p1,&p2);
	p=p1*Fstpw(p2,mod-2)%mod;
	scanf("%d",&k);
	for(int i=0,j=1; i<m&&j; i++,j=j*Fstpw(i,mod-2)%mod*(k-i+1)%mod)
		q[i]=j*Fstpw(p,i)%mod*Fstpw((1-p+mod)%mod,k-i)%mod;
	for(int l=1; l<=m; l++)
		for(int r=l; r<=m; r++){
			int x=1ll*q[l-1]*q[m-r]%mod;
			s=(s+x)%mod;
			s0[l]=(s0[l]+x)%mod;
			s1[r]=(s1[r]+x)%mod;
		}
	g[0]=1;
	for(int i=0; i<n; i++){
		g[i+1]=1ll*g[i]*s%mod;
		/*
		for(int l=1; l<=m; l++)
			for(int r=l; r<=m; r++){
				ll x=1ll*q[l-1]*q[m-r]%mod;
				f[i+1][l][0]=(f[i+1][l][0]+g[i]*x)%mod;
				f[i+1][r][1]=(f[i+1][r][1]+g[i]*x)%mod;
			}
			*/
		for(int l=1; l<=m; l++)
			f[i+1][l][0]=(f[i+1][l][0]+1ll*g[i]*s0[l])%mod;
		for(int r=1; r<=m; r++)
			f[i+1][r][1]=(f[i+1][r][1]+1ll*g[i]*s1[r])%mod;
		/*
		for(int j=1; j<=m; j++){
			for(int l=1; l<j; l++)
				for(int r=l; r<j; r++){
					ll x=(mod-1ll*q[l-1]*q[m-r]%mod)%mod;
					g[i+1]=(g[i+1]+f[i][j][0]*x)%mod;
					f[i+1][l][0]=(f[i+1][l][0]+f[i][j][0]*x)%mod;
					f[i+1][r][1]=(f[i+1][r][1]+f[i][j][0]*x)%mod;
				}
			for(int l=j+1; l<=m; l++)
				for(int r=l; r<=m; r++){
					ll x=(mod-1ll*q[l-1]*q[m-r]%mod)%mod;
					g[i+1]=(g[i+1]+f[i][j][1]*x)%mod;
					f[i+1][l][0]=(f[i+1][l][0]+f[i][j][1]*x)%mod;
					f[i+1][r][1]=(f[i+1][r][1]+f[i][j][1]*x)%mod;
				}
		}
		*/
		for(int j=1,k=0; j<=m; k=(k-s1[j]+mod)%mod,j++)
			g[i+1]=(g[i+1]+1ll*k*f[i][j][0])%mod;
		sum[m]=0;
		for(int j=m; j; j--)
			sum[j-1]=(sum[j]-f[i][j][0]+mod)%mod;
		for(int j=1; j<=m; j++){
			f[i+1][j][1]=(f[i+1][j][1]+1ll*sum[j]*s1[j])%mod;
			sum[j]=1ll*sum[j]*q[m-j]%mod;
		}
		for(int j=m; j; j--){
			f[i+1][j][0]=(f[i+1][j][0]+1ll*sum[j]*q[j-1])%mod;
			sum[j-1]=(sum[j-1]+sum[j])%mod;
		}
		for(int j=m,k=0; j; k=(k-s0[j]+mod)%mod,j--)
			g[i+1]=(g[i+1]+1ll*k*f[i][j][1])%mod;
		sum[1]=0;
		for(int j=1; j<=m; j++){
			sum[j+1]=(sum[j]-f[i][j][1]+mod)%mod;
			f[i+1][j][0]=(f[i+1][j][0]+1ll*sum[j]*s0[j])%mod;
			sum[j]=1ll*sum[j]*q[j-1]%mod;
		}
		for(int j=1; j<=m; j++){
			f[i+1][j][1]=(f[i+1][j][1]+1ll*sum[j]*q[m-j])%mod;
			sum[j+1]=(sum[j+1]+sum[j])%mod;
		}
	}
	printf("%d\n",g[n]);
	return 0;
}