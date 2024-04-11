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

typedef unsigned int uint;

const int N=10100000;
const ll inf=1ll<<62;
uint b[N];
ll l,r,x,y,z;
int a[N],_,n;

int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%d%lld%lld%lld%lld%lld%u%u",&n,&l,&r,&x,&y,&z,b+1,b+2);
		rep(i,3,n+1) {
			b[i]=b[i-2]*x+b[i-1]*y+z;
		}
		rep(i,1,n+1) {
			a[i]=b[i]%(r-l+1)+l;
//			printf("%d\n",a[i]);
		}
		int umin=2100100100;
		ll ans=inf;
		rep(i,1,n+1) {
			if (a[i]>umin) {
				ans=min(ans,(ll)a[i]*umin);
			}
			umin=min(umin,a[i]);
		}
		umin=-2100100100;
		per(i,1,n+1) {
			if (a[i]<umin) {
				ans=min(ans,(ll)a[i]*umin);
			}
			umin=max(umin,a[i]);
		}
		if (ans!=inf) {
			printf("%lld\n",ans);
		} else {
			puts("IMPOSSIBLE");
		}
	}
}