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

const int O=100010,N=501000;
int n,x,y,f[N],g[N],p[N],q[N];
vector<PII> v[4];
ll gao(vector<PII> v) {
	sort(all(v));
	rep(i,0,4*O+1) f[i]=4*O+1,g[i]=-1,p[i]=0,q[i]=4*O+1;
	rep(i,0,SZ(v)) {
		f[v[i].fi]=min(f[v[i].fi],v[i].se);
		g[v[i].fi]=max(f[v[i].fi],v[i].se);
	}
	int pre1=4*O+1,pre2=-1;
	rep(i,1,4*O+1) {
		pre1=min(pre1,f[i]);
		pre2=max(pre2,g[i]);
		p[i]=max(pre1,p[i]);
		q[i]=min(pre2,q[i]);
	}
	pre1=4*O+1; pre2=-1;
	per(i,1,4*O+1) {
		pre1=min(pre1,f[i]);
		pre2=max(pre2,g[i]);
		p[i]=max(pre1,p[i]);
		q[i]=min(pre2,q[i]);
	}
	ll ret=0;
	rep(i,1,4*O+1) if (i%2==1) {
		if (p[i]<q[i]) {
			ret+=(q[i]-p[i])/2;
		}
	}
	return ret;
}
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d",&x,&y);
		int d=(x+y)&1; if (d<0) d+=2;
		v[d].pb(mp(x+y+2*O+d,x-y+2*O+d));
	}
	printf("%lld\n",gao(v[0])+gao(v[1]));
}