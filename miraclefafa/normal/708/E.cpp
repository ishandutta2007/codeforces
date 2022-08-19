#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
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
// head

const int M=101000,N=1600;
int n,m,a,b,k;
ll fac[M],fnv[M],pr[M],spr[M],p;
ll lp[N][N],rp[N][N];
ll comb(int x,int y) {
	if (y<0||y>x) return 0;
	return fac[x]*fnv[y]%mod*fnv[x-y]%mod;
}
int main() {
	scanf("%d%d",&n,&m);
	scanf("%d%d",&a,&b);
	scanf("%d",&k);
	p=a*powmod(b,mod-2)%mod;
	fac[0]=1;
	rep(i,1,k+1) fac[i]=fac[i-1]*i%mod;
	rep(i,0,k+1) fnv[i]=powmod(fac[i],mod-2);
	rep(i,0,m+1) if (i<=k) {
		pr[i]=comb(k,i)*powmod(p,i)%mod*powmod(1-p,k-i)%mod;
		if (pr[i]<0) pr[i]+=mod;
	}
	spr[0]=pr[0];
	rep(i,1,m+1) spr[i]=(spr[i-1]+pr[i])%mod;
	per(l,1,m+1) {
		rp[1][l]=pr[l-1]*spr[m-l]%mod;
		rp[1][l]=(rp[1][l]+rp[1][l+1])%mod;
	}
	rep(r,1,m+1) {
		lp[1][r]=spr[r-1]*pr[m-r]%mod;
		lp[1][r]=(lp[1][r]+lp[1][r-1])%mod;
	}
	rep(i,2,n+1) {
		ll prob=lp[i-1][m];
		ll vr=0;
		per(l,1,m+1) {
			vr=(vr+pr[m-l]*rp[i-1][l+1])%mod;
			ll pp=((prob-lp[i-1][l-1])*spr[m-l]-vr)%mod*pr[l-1]%mod;
			if (pp<0) pp+=mod;
			rp[i][l]=(pp+rp[i][l+1])%mod;
		}
		ll vl=0;
		rep(r,1,m+1) {
			vl=(vl+pr[r-1]*lp[i-1][r-1])%mod;
			ll pp=((prob-rp[i-1][r+1])*spr[r-1]-vl)%mod*pr[m-r]%mod;
			if (pp<0) pp+=mod;
			lp[i][r]=(pp+lp[i][r-1])%mod;
		}
	}
	printf("%lld\n",lp[n][m]);
}