#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
ll f[N],g[N];
char s[N];
int l[N],n,k,ds;
ll comb(int a,int b) {
	if (b>a||b<0) return 0;
	else return f[a]*g[b]%mod*g[a-b]%mod;
}
int main() {
	f[0]=1; g[0]=1;
	rep(i,1,100001) {
		f[i]=f[i-1]*i%mod;
		g[i]=powmod(f[i],mod-2);
	}
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	rep(i,1,n+1) l[i]=s[i]-'0';
	rep(i,1,n+1) ds+=l[i];
	ll b=0,e=0,as=0,pw=1;
	if (k==0) {
		ll s=0;
		rep(i,1,n+1) s=(s*10+l[i])%mod;
		printf("%I64d\n",s);
	} else if (k==1) {
		ll s=0;
		rep(i,1,n) {
			b=(b*10+l[i])%mod;
			e=(e+l[n+1-i]*pw)%mod;
			s=(s+b+e)%mod;
			pw=pw*10%mod;
		}
		printf("%I64d\n",s);
	} else  {
		ll s=0;
		rep(i,1,n+1) {
			b=(b*10+l[i])%mod;
			as=((as-e)*10+ds)%mod;
			e=(e+l[n+1-i]*pw)%mod;
			pw=pw*10%mod;
			ds=ds-l[i];
			s=(s+(as-b-e)%mod*comb(n-i-2,k-2))%mod;
			s=(s+(b+e)%mod*comb(n-i-1,k-1))%mod;
		}
		if (s<0) s+=mod;
		printf("%I64d\n",s);
	}
}