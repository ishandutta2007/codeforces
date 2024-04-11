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

const int N=101000;
int n,m,u,v,deg[N],q;
VI e[N];
ll ans;

int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,m) {
		scanf("%d%d",&u,&v);
		if (u>v) swap(u,v);
		e[u].pb(v);
		deg[u]++; deg[v]++;
	}

	auto eval=[&](int u) {
		return (ll)SZ(e[u])*(deg[u]-SZ(e[u]));
	};

	rep(i,1,n+1) ans+=eval(i);
	printf("%lld\n",ans);
	scanf("%d",&q);
	rep(i,1,q+1) {
		scanf("%d",&u);
		ans-=eval(u);
		for (auto v:e[u]) {
			ans-=eval(v);
			e[v].pb(u);
			ans+=eval(v);
		}
		e[u].clear();
		printf("%lld\n",ans);
	}
}