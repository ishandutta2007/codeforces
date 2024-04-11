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

int q,ty,lev;
ll cnt[66],off[66],x,k;
int level(ll x) {
	int lev=0;
	while (x) x/=2,lev++;
	return lev;
}
int main() {
	scanf("%d",&q);
	rep(i,1,62) cnt[i]=1ll<<(i-1);
	rep(i,0,q) {
		scanf("%d",&ty);
		if (ty==1) {
			scanf("%lld%lld",&x,&k);
			lev=level(x);
			k%=cnt[lev];
			if (k<0) k+=cnt[lev];
			off[lev]+=k;
			if (off[lev]>=cnt[lev]) off[lev]-=cnt[lev];
		} else if (ty==2) {
			scanf("%lld%lld",&x,&k);
			lev=level(x);
			k%=cnt[lev];
			if (k<0) k+=cnt[lev];
			rep(l,lev,62) {
				off[l]+=k;
				if (off[l]>=cnt[l]) off[l]-=cnt[l];
				k*=2;
			}
		} else if (ty==3) {
//			rep(i,0,10) printf("%lld ",off[i]); puts("");
			scanf("%lld",&x);
			lev=level(x); x-=(1ll<<(lev-1));
			x=(x+off[lev])%cnt[lev];
			per(i,1,lev+1) {
				ll r=x+cnt[i]-off[i];
				if (r<0) r+=cnt[i];
				if (r>=cnt[i]) r-=cnt[i];
				printf("%lld ",r+(1ll<<(i-1)));
				x/=2;
			}
			puts("");
		}
	}
}