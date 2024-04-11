#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,n) for (int i=a;i<n;i++)
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=530;
int f,b,p[N],c[N],k;
ll a[N],base[N],_c[N],_md[N],res[N],_a[N];
ll n;
void mul(ll *a,ll *b) {
	rep(i,0,k+k) _c[i]=0;
	rep(i,0,k) if (a[i]) rep(j,0,k) _c[i+j]=(_c[i+j]+a[i]*b[j])%mod;
	for (int i=k+k-1;i>=k;i--) if (_c[i])
		rep(j,0,k) _c[i-k+j]=(_c[i-k+j]+_c[i]*_md[j])%mod;
	rep(i,0,k) a[i]=_c[i];
}
void powmod(ll *a,ll b) {
	rep(i,0,k) res[i]=0;
	res[0]=1;
	for (;b;b>>=1) {
		if (b&1) mul(res,a);
		mul(a,a);
	}
	rep(i,0,k) a[i]=res[i];
}
int main() {
	scanf("%d%d%lld",&f,&b,&n);
	rep(i,0,f) scanf("%d",p+i);
	rep(i,0,b) scanf("%d",c+i),k=max(k,c[i]);
	rep(i,0,b) _md[k-c[i]]++;
	rep(i,0,f) {
		rep(j,0,k) a[j]=0; a[1]=1;
		if (k==1) a[0]=_md[0];
		powmod(a,p[i]);
		rep(j,0,k) base[j]=(base[j]+a[j])%mod;
	}
	powmod(base,n);
	rep(j,0,k) a[j]=0; a[k-1]=1;
	mul(base,_md);
	printf("%lld\n",base[0]*powmod(_md[0],mod-2)%mod);
}