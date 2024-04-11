#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=301000;
int n,a[N],m;
ll inv[N],ret[N],ans;
pair<ll,ll> pf[N];
int main() {
	scanf("%d",&n);
	for (int i=0;i<n;i++) {
		scanf("%d",a+i);
		m+=a[i];
	}
	pf[m-1]=mp(1,0);
	inv[1]=1;
	for (int i=2;i<=max(n,m)-1;i++) inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for (int i=m-1;i>=1;i--) {
		ll d=(m-i)*inv[i]%mod*inv[n-1]%mod;
		pf[i-1].fi=d*pf[i].fi%mod;
		pf[i-1].se=(d*pf[i].se+1)%mod;
	}
	ll w=(mod-pf[0].se)*powmod(pf[0].fi,mod-2)%mod;
	for (int i=m-1;i>=0;i--) {
		ll d=(w*pf[i].fi+pf[i].se)%mod;
		ret[i]=(ret[i+1]+mod-d)%mod;
	}
	rep(i,0,n) ans=(ans+ret[a[i]])%mod;
	ans=(ans-(n-1)*ret[0])%mod;
	if (ans<0) ans+=mod;
	printf("%lld\n",ans);

}