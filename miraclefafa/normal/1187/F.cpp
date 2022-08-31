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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,l[N],r[N];
ll isz[N],dif[N],ans;

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",l+i);
	rep(i,1,n+1) scanf("%d",r+i);
	++n;
	l[n]=0, r[n]=0;
	rep(i,1,n+1) isz[i]=powmod(r[i]-l[i]+1,mod-2);
	ll ans=0;
	rep(i,1,n) {
		int pl=max(l[i],l[i+1]),pr=min(r[i],r[i+1]);
		if (pl<=pr) dif[i]=(pr-pl+1)*isz[i]%mod*isz[i+1]%mod;
		dif[i]=(mod+1-dif[i])%mod;
		ans=(ans+dif[i])%mod;
	}
	ans=ans*ans%mod;
	rep(i,1,n) {
		ans=(ans-dif[i]*dif[i]+dif[i])%mod;
	}
	rep(i,1,n-1) {
		ans=(ans-2*dif[i]*dif[i+1])%mod;
		ll df=dif[i]+dif[i+1]-1;
		int pl=max(max(l[i],l[i+1]),l[i+2]);
		int pr=min(min(r[i],r[i+1]),r[i+2]);
		if (pl<=pr) df=(df+(pr-pl+1)*isz[i]%mod*isz[i+1]%mod*isz[i+2])%mod;
		ans=(ans+df*2)%mod;
	}
	if (ans<0) ans+=mod;
	printf("%lld\n",ans);
}