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

ll t,n,a,b,k;
int main() {
	scanf("%lld%lld%lld%lld%lld",&t,&n,&a,&b,&k);
	if (k>n) {
		puts("0");
		return 0;
	}
	ll l=0,r=t+1;
	while (l+1<r) {
		ll md=(l+r)>>1;
		if (min(md*k,min(md,a)*((n+1)/2)+min(md,b)*(n/2))==md*k) l=md; else r=md;
	}
	printf("%lld\n",l);
}