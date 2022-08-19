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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=101000;
int n,m;
VI x[N],y[N];
ll ans=0;
ll calc(VI x) {
	sort(all(x));
	ll ans=0;
	rep(i,0,SZ(x)) {
		ans+=-1ll*x[i]*(SZ(x)-1-2*i);
	}
	return ans;
}
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) rep(j,0,m) {
		int c;
		scanf("%d",&c);
		x[c].pb(i);
		y[c].pb(j);
	}
	rep(i,1,100001) ans+=calc(x[i])+calc(y[i]);
	printf("%lld\n",ans);
}