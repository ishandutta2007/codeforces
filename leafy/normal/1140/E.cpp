#include<bits/stdc++.h>
using namespace std;
const int N=200005;
const int mod=998244353;
typedef long long ll;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int n,k;
int a[2][N];
ll f[N],g[N];
inline ll qpow(ll a,ll b){
	ll ans=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) ans=ans*a%mod;
	return ans;
}

inline ll calc(int *b,int len){
	int la=-1;
	ll ans=1;
	for(int i=0;i<len;i++){
		if(b[i]==b[i+1]&&b[i]!=-1) return 0;
		if(b[i]!=-1){
			if(la==-1){
				ans=ans*qpow(k-1,i)%mod;
			}else if(b[la]==b[i]){
				ans=(ans*f[i-la-1])%mod;
			}else {
				ans=(ans*g[i-la-1])%mod;
			}
			la=i;
		}
	}
	if(la==-1) return k*qpow(k-1,len-1)%mod;
	return ans*qpow(k-1,len-la-1)%mod;
}
int main(){
	n=read(),k=read();
	for(int i=0;i<n;i++) a[i&1][i>>1]=read();
	f[0]=0,g[0]=1;
	for(int i=1;i<=n;i++) {
		f[i]=(k-1)*g[i-1]%mod;
		g[i]=(f[i-1]+(k-2)*g[i-1])%mod;
	}
	printf("%lld",calc(a[0],(n+1)>>1)*calc(a[1],n>>1)%mod);
	return 0;
}