#include<cstdio>
const int MAXN=5005,Mod=998244353;
int n,a[MAXN],cnt[MAXN];
int f[MAXN][MAXN],ans;
int inv[MAXN];
int main(){
	//freopen("3863.in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),++cnt[a[i]];
	inv[1]=1;
	for(int i=2; i<=n; i++)
		inv[i]=1ll*(Mod-Mod/i)*inv[Mod%i]%Mod;
	f[0][0]=1;
	for(int i=1; i<n; i++){
		int s=f[i-1][0];
		for(int j=1;j<=n;j++){
			f[i][j]=1ll*s*cnt[j]%Mod*inv[n-i+1]%Mod;
			s=(s+f[i-1][j])%Mod;
			if(cnt[j]) ans=(ans+f[i][j]*(cnt[j]-1ll)%Mod*inv[n-i])%Mod;
		}
	}
	printf("%d\n",ans);
	return 0;
}