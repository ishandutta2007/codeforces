#include<cstdio>
#include<algorithm>
#include<cstring>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int MAXN=1<<14|5,mod=1e9+7;
int n,a[20],b[20][20];
int f[MAXN],ppc[MAXN];
unordered_map<int,int> g[MAXN];
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int ans;
int main(){
	//freopen("in2.txt","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i),f[1<<i-1];
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(i!=j) b[i][j]=a[i]*Fstpw(a[i]+a[j],mod-2)%mod;
			else b[i][j]=1;
	g[0][0]=1;
	for(int i=1; i<1<<n; i++){
		g[i][0]=1;
		for(int j=i; j; j=j-1&i){
			int t=j&-j;
			g[i][j]=g[i^t][j^t];
			for(int k=1; k<=n; k++)
				if(t==1<<k-1){
					t=k;
					break;
				}
			for(int k=1; k<=n; k++)
				if(1<<k-1&(i^j)) g[i][j]=1ll*g[i][j]*b[t][k]%mod;
			/*
			g[i][j]=1;
			for(int x=1; x<=n; x++)
				for(int y=1; y<=n; y++)
					if(1<<x-1&j&&1<<y-1&(i^j)) g[i][j]=1ll*g[i][j]*b[x][y]%mod;
					*/
		}
	}
	for(int i=1; i<1<<n; i++){
		f[i]=1;
		for(int j=i-1&i; j; j=j-1&i)
			f[i]=(f[i]-1ll*f[j]*g[i][j]%mod+mod)%mod;
		ppc[i]=ppc[i>>1]+(i&1);
		ans=(ans+1ll*f[i]*g[(1<<n)-1][i]%mod*ppc[i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}