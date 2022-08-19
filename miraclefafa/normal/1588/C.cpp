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

int n,_;
void solve() {
	scanf("%d",&n);
	map<ll,int> r;
	ll k=1,b=0,ans=0;
	rep(i,1,n+1) {
		int x;
		scanf("%d",&x);
		k=-k; b=x-b;
		ll f0=(-b)/k,f1=(x-b)/k;
		if (f0>f1) swap(f0,f1);
		while (!r.empty()&&r.begin()->fi<f0) r.erase(r.begin());
		while (!r.empty()&&(--r.end())->fi>f1) r.erase(--r.end());
		ans=(ans+r[-b/k]);
		if (x==0) ans++;
		r[(x-b)/k]++;
		/*for (auto x:r) if (x.se) printf("%lld %d\n",k*x.fi+b,x.se);
		printf("%lld\n",ans);
		puts("----");*/
	}
	printf("%lld\n",ans);
}

int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}