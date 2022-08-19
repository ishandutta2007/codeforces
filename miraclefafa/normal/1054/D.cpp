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
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

map<int,int> cs;
int n,k,x;
int main() {
	scanf("%d%d",&n,&k);
	cs[0]++;
	int p=0;
	rep(i,1,n+1) {
		scanf("%d",&x);
		p=p^x;
		p=min(p,p^((1<<k)-1));
		cs[p]++;
	}
	auto C=[](ll x) {
		return x*(x-1)/2;
	};
	ll ans=C(n+1);
	for (auto pp:cs) {
		ll x=pp.se;
//		printf("%lld\n",x);
		ans=ans-C(x/2)-C(x-x/2);
	}
	printf("%lld\n",ans);
}