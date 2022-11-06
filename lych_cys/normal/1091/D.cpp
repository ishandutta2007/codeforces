#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000
#define infll 1000000000000000000ll
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define mpr make_pair
#define fi first
#define se second
#define pq priority_queue<int>
#define pqll priority_queue<ll>
#define up(x,y) (x<(y)?x=(y):0)
#define dn(x,y) (x>(y)?x=(y):0)
#define ad(x,y) (x=(x+(y))%mod)
#define mod 998244353
using namespace std;

int read(){
	int x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
ll readll(){
	ll x=0; char ch=getchar(); bool flag=0;
	while (ch<'0' || ch>'9'){ if (ch=='-') flag=1; ch=getchar(); }
	while (ch>='0' && ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return flag?-x:x;
}
int f[2000009],fac[2000009];
int main(){
	int n=read(),i;
	for (i=fac[0]=1; i<=n; i++) fac[i]=(ll)fac[i-1]*i%mod;
	for (i=n,f[n+1]=1; i; i--) f[i]=(ll)f[i+1]*i%mod;
	int ans=(ll)n*fac[n]%mod;
	//cerr<<ans<<'\n';
	ans=(ans+mod-(n-1))%mod;
	for (i=1; i<n; i++){
		//cerr<<f[i]<<' '<<f[i+1]<<'\n';
		ans=(ans-(ll)(f[i+1]-f[i+2]+mod)*i%mod+mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}