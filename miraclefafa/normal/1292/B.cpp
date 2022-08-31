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

vector<pair<ll,ll>> v;
ll px,py,ax,ay,bx,by,sx,sy,t;
const ll M=10000000000000000ll;
int ans;
int main() {
	scanf("%lld%lld%lld%lld%lld%lld",&px,&py,&ax,&ay,&bx,&by);
	v.pb(mp(px,py));
	while (1) {
		px=px*ax+bx;
		py=py*ay+by;
		if (px<=2*M&&py<=2*M) v.pb(mp(px,py));
		else break;
	}
	scanf("%lld%lld%lld",&sx,&sy,&t);
	ans=0;
	rep(sp,0,SZ(v)) rep(s1,0,SZ(v)) rep(s2,0,SZ(v)) {
		if (abs(sx-v[sp].fi)+abs(sy-v[sp].se)+abs(v[s1].fi-v[sp].fi)+abs(v[s1].se-v[sp].se)
			+abs(v[s1].fi-v[s2].fi)+abs(v[s1].se-v[s2].se)<=t) {
			ans=max(ans,abs(s2-s1)+1);
		}
	}
	printf("%d\n",ans);
}