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

const int M=500000;
const int N=501000;

ll dp[10],pd[10],s;
int cnt[N],ord[N],x,cnt0[10],cnt1[10],n;

bool check(ll x,int y) {
	VI z; z.pb(0); z.pb(y); z.pb(x%y); z.pb(2*x%y);
	sort(all(z)); z.erase(unique(all(z)),z.end());
	ll cs=0;
	rep(i,0,SZ(z)-1) cnt0[i]=cnt1[i]=0;
	for (int val=0;val<=M;val+=y) {
		cs+=(ll)(cnt[min(val+y,M+1)]-cnt[val])*(val/y);
		rep(i,0,SZ(z)-1) {
			// val+z[i], val+z[i+1]-1
			int pl=val+z[i],pr=val+z[i+1]-1;
			int zz=cnt[min(pr+1,M+1)]-cnt[min(pl,M+1)];
			if (pl>=x) {
				cnt0[i]+=zz;
			}
			if (pl>=2*x) {
				cnt1[i]+=zz;
			}
		}
	}
	dp[0]=0; dp[1]=dp[2]=1ll<<60;
	rep(i,0,SZ(z)-1) {
		int pl=z[i],pr=z[i+1]-1;
		ll rg=(1ll<<40)*y+pl;
		ll rd1=(rg/y)-(rg-x)/y;
		ll rd2=(rg/y)-(rg-2*x)/y;
		cnt0[i]=min(cnt0[i],2);
		cnt1[i]=min(cnt1[i],1);
		rep(j,1,3) pd[j]=dp[j];
		rep(j,1,cnt0[i]+1) rep(k,j,3) dp[k]=min(dp[k],pd[k-j]+j*rd1);
		rep(j,1,3) pd[j]=dp[j];
		rep(j,1,cnt1[i]+1) rep(k,2*j,3) dp[k]=min(dp[k],pd[k-2*j]+j*rd2);
	}
	return cs-dp[2]>=x;
}

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&x),cnt[x+1]++,s+=x;
	rep(i,1,M+2) cnt[i]+=cnt[i-1];
	ll ans=0;
	rep(i,1,M+1) ord[i]=i;
	random_shuffle(ord+1,ord+M+1,rnd);
	rep(i,1,M+1) {
		int y=ord[i];
		if (y==1) continue;
		ll px=max((ans+y-1)/y,2ll);
		if (!check(px,y)) continue;
		ll l=px,r=s/y+1;
		while (l+1<r) {
			ll md=(l+r)>>1;
			if (check(md,y)) l=md; else r=md;
		}
		ans=max(ans,l*y);
	}
	printf("%lld\n",ans);
}