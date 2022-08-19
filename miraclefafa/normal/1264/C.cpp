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
const ll mod=998244353 ;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;

int n,q,p,u;
set<int> hs;
ll f[N],mf[N],imf[N],smf[N],ans;

ll query(int l,int r) {
	return (smf[l]-smf[r+1])*imf[r+1]%mod;
}

int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) {
		scanf("%d",&p);
		f[i]=100*powmod(p,mod-2)%mod;
	}
	mf[n+1]=1;
	imf[n+1]=1;
	per(i,1,n+1) {
		mf[i]=f[i]*mf[i+1]%mod;
		imf[i]=powmod(mf[i],mod-2);
		smf[i]=(smf[i+1]+mf[i])%mod;
	}
	hs.insert(1);
	hs.insert(n+1);
	ans=query(1,n);
	rep(i,0,q) {
		scanf("%d",&u);
		if (hs.count(u)) {
			auto it=hs.find(u);
			auto pit=it,qit=it;
			pit--; qit++;
			ans-=query(*pit,*it-1);
			ans-=query(*it,*qit-1);
			ans+=query(*pit,*qit-1);
			hs.erase(u);
		} else {
			hs.insert(u);
			auto it=hs.find(u);
			auto pit=it,qit=it;
			pit--; qit++;
			ans+=query(*pit,*it-1);
			ans+=query(*it,*qit-1);
			ans-=query(*pit,*qit-1);
		}
		ans%=mod;
		if (ans<0) ans+=mod;
		printf("%lld\n",ans);
	}
}