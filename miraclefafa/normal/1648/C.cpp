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

const int N=201000;
int n,m,s[N],t[N],c[N],cnt[N];
ll fac[N],fnv[N],inv[N];
void add(int x,int s) {
	for (;x<=200000;x+=x&-x) c[x]+=s;
}
int query(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=c[x];
	return s;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) {
		scanf("%d",s+i),cnt[s[i]]++;
		add(s[i],1);
	}
	rep(i,1,m+1) scanf("%d",t+i);
	fac[0]=fnv[0]=1;
	rep(i,1,n+1) {
		fac[i]=fac[i-1]*i%mod;
		inv[i]=powmod(i,mod-2);
		fnv[i]=fnv[i-1]*inv[i]%mod;
	}
	ll way=fac[n];
	rep(i,1,200000+1) {
		way=way*fnv[cnt[i]]%mod;
	}
	ll ans=0;
	bool ls=0;
	rep(i,1,n+1) {
		ans=(ans+way*inv[n-i+1]%mod*query(i<=m?(t[i]-1):0))%mod;
		int v=i<=m?t[i]:0;
		if (cnt[v]==0) { ls=1; break; }
		way=way*inv[n-i+1]%mod*cnt[v]%mod;
		//printf("%d %lld %lld\n",i,way,ans);
		--cnt[v];
		add(v,-1);
	}
	if (n<m&&!ls) ans=(ans+1)%mod;
	printf("%lld\n",ans);
}