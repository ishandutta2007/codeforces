#include<cstdio>
#include<algorithm>
#define MAXN 1000
using namespace std;
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int n,d,MOD,f[MAXN+10][11],g[MAXN+10],inv[MAXN+10],ans;
int main()
{
	Read(n),Read(d),Read(MOD);
	if(n<=2){
		puts("1");
		return 0;
	}
	if((n-2)%(d-1)){
		puts("0");
		return 0;
	}
	int i,j,p,q,w;
	inv[0]=inv[1]=1;
	for(i=2;i<=n;i++)
		inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
	for(i=2;i<=n;i++)
		inv[i]=1ll*inv[i]*inv[i-1]%MOD;
	g[1]=f[1][0]=1;
	for(i=1;i<=(n>>1);i++){
		for(j=n-i+1;j>=1;j--)
			for(p=0;p<d;p++)
				if(f[j][p]){
					w=1;
					for(q=1;p+q<=d&&j+q*i<=n;q++){
						w=1ll*w*(g[i]+q-1)%MOD;
						f[j+q*i][p+q]=(f[j+q*i][p+q]+1ll*w*inv[q]%MOD*f[j][p])%MOD;
					}
				}
		g[i+1]=f[i+1][d-1];
	}
	//g[i]=trees(i,d-1,i-1)
	ans=f[n][d];
	if(!(n&1))
		ans=(ans+MOD-(1ll*g[n>>1]*(g[n>>1]-1)/2)%MOD)%MOD;
	printf("%d\n",ans);
}