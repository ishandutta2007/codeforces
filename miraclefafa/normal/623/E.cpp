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

const int N=301000;
ll ret[N],coef[N],tmp[N],fnv[N],n;
int k,K;
void mult(ll *x,ll y) {
	ll c=1;
	rep(i,0,K+1) {
		x[i]=x[i]*c%mod;
		c=c*y%mod;
	}
}
void multt(ll *x,ll y) {
	rep(i,0,K+1) x[i]=x[i]*y%mod;
}

ll buffer[N],buffer_pos,size=32768;

void multiply(int size,ll a[],ll b[],ll r[]) {
	if (size<=16) {
		for (int i=0;i<size+size;i++) r[i]=0;
		for (int i=0;i<size;i++) if (a[i]) for (int j=0;j<size;j++) {
			r[i+j]+=a[i]*b[j];
			if (r[i+j]>=8000000000000000000ll) r[i+j]%=mod;
		}
		for (int i=0;i<size+size;i++) r[i]%=mod;
		return;
	}
	int s=size/2;
	multiply(s,a,b,r);
	multiply(s,a+s,b+s,r+size);
	ll *a2=buffer+buffer_pos; buffer_pos+=s;
	ll *b2=buffer+buffer_pos; buffer_pos+=s;
	ll *r2=buffer+buffer_pos; buffer_pos+=size;
	for (int i=0;i<s;i++) { a2[i]=a[i]+a[i+s]; if (a2[i]>=mod) a2[i]-=mod; }
	for (int i=0;i<s;i++) { b2[i]=b[i]+b[i+s]; if (b2[i]>=mod) b2[i]-=mod; }
	multiply(s,a2,b2,r2);
	for (int i=0;i<size;i++) r2[i]-=r[i]+r[i+size];
	for (int i=0;i<size;i++) { r[i+s]+=r2[i]; r[i+s]%=mod; if (r[i+s]<0) r[i+s]+=mod; }
	buffer_pos-=(s+s+size);
}
void mul(ll *a,ll *b) {
	ll *r=buffer+buffer_pos;
	buffer_pos+=size+size;
	multiply(size,a,b,r);
	for (int i=0;i<size;i++) a[i]=r[i];
	buffer_pos-=size+size;	
}
void poww(int n) {
	if (n==1) {
		rep(i,0,K+1) ret[i]=coef[i];
	} else if (n%2==1) {
		poww(n-1);
		mult(ret,2);
		multt(ret,powmod(2,n-1));
		mul(ret,coef);
	} else {
		poww(n/2);
		rep(i,0,K+1) tmp[i]=ret[i];
		mult(tmp,powmod(2,n/2));
		multt(tmp,powmod(2,(n/2)*(n/2)));
		mul(ret,tmp);
	}
}
int main() {
	scanf("%I64d%d",&n,&k);
	if (n>k) {
		puts("0");
		return 0;
	}
	fnv[0]=1;
	K=k-n;
	while (size/2>K+1) size/=2;
	rep(i,1,k+1) fnv[i]=fnv[i-1]*powmod(i,mod-2)%mod;
	rep(i,0,K+1) coef[i]=fnv[i+1];
	ret[0]=1;
	poww(n);
	ll ans=0;
	rep(i,n,k+1) {
		ans=(ans+ret[i-n]*fnv[k-i])%mod;
	}
	rep(i,1,k+1) ans=ans*i%mod;
	printf("%I64d\n",ans);
}