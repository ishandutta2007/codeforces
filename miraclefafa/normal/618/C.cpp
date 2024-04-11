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

const int N=101000;
ll sqr(ll x) { return x*x;}
int n;
PII p[N];
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d%d",&p[i].fi,&p[i].se);
	printf("%d ",1);
	int md=2; ll dis=sqr(p[2].fi-p[1].fi)+sqr(p[2].se-p[1].se);
	rep(i,2,n+1) {
		ll t=sqr(p[i].fi-p[1].fi)+sqr(p[i].se-p[1].se);
		if (t<dis) dis=t,md=i;
	}
	printf("%d ",md);
	ll dx=p[md].fi-p[1].fi,dy=p[md].se-p[1].se;
	int mc=2; if (mc==md) mc++;
	dis=8100000000000000000ll;
	rep(i,2,n+1) {
		ll Dx=p[i].fi-p[1].fi,Dy=p[i].se-p[1].se;
		if (dx*Dy==dy*Dx) continue;
		if (Dx*Dx+Dy*Dy<dis) {
			dis=Dx*Dx+Dy*Dy;
			mc=i;
		}
	}
	printf("%d\n",mc);
}