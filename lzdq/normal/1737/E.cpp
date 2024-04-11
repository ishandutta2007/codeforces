#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e6+5,mod=1e9+7;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
ll pw[MAXN],ipw[MAXN];
int n,f[21],s[MAXN][21],ans[MAXN];
int main(){
	//freopen("in1.txt","r",stdin);
	n=1e6;
	pw[0]=ipw[0]=1;
	for(int i=1; i<=n; i++){
		pw[i]=pw[i-1]*2%mod;
		ipw[i]=ipw[i-1]*(mod+1)/2%mod;
	}
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		memset(s[n+1],0,sizeof(s[n+1]));
		for(int i=n; i; i--){
			ans[i]=0;
			if(i==n) f[0]=1;
			else f[0]=pw[n-i-1];
			if(i*2<=n){
				for(int j=1; j<=20; j++)
					f[j]=s[i*2][j-1]*ipw[i]%mod;
			}else{
				for(int j=1; j<=20; j++)
					f[j]=0;
			}
			ans[i]=0;
			for(int j=0; j<=20; j++){
				if(j&1) ans[i]=(ans[i]-f[j]+mod)%mod;
				else ans[i]=(ans[i]+f[j])%mod;
				s[i][j]=(s[i+1][j]+f[j]*pw[i/2])%mod;
			}
			ans[i]=ans[i]*pw[i/2]%mod;
			ans[i]=ans[i]*ipw[n-1]%mod;
		}
		for(int i=1; i<=n; i++)
			printf("%d\n",ans[i]);
	}
	return 0;
}