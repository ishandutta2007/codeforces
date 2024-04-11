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
const ll mod2=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

VI pos[10];
int cnt;
ll pw[15],s[15];
ll cnt2,n;
int ans;
int query(int fixpre,ll val) {
	ll ans=0;
	rep(d,0,7) {
		ll offset=(val-fixpre*pw[d])%mod2;
		if (offset<0) offset+=mod2;
		int p=lower_bound(all(pos[d]),mod2-offset)-pos[d].begin();
		ans=(ans+s[d]+offset*SZ(pos[d])-mod2*(SZ(pos[d])-p))%mod;
		/*0...p-1 x+offset
		p...len-1 x+offset-mod
		(offset+pos[d])%mod*/
	}
	return ans;
}

void dfs(int val,int d) {
	int x=(cnt-val+mod2)%mod2;
	pos[d].pb(x); cnt++;
	s[d]+=x;
	if (d==6) return;
	rep(i,0,10) dfs(val*10+i,d+1);
}

void dfs2(ll val) {
	if (val*1000000+999999<=n&&val*10000000>n) {
		ans=(ans+query(val,cnt2+1))%mod;
		cnt2+=cnt;
	} else {
		cnt2++;
		ans=(ans+((cnt2-val)%mod2+mod2)%mod2)%mod;
		rep(i,val?0:1,10) {
			if (val*10+i<=n) dfs2(val*10+i);
		}
	}
}

int main() {
	dfs(0,0);
	rep(i,0,7) sort(all(pos[i]));
	pw[0]=1;
	rep(i,1,13) pw[i]=pw[i-1]*10;
	scanf("%lld",&n);
	cnt2=-1;
	dfs2(0);
	//printf("%lld\n",cnt2);
	printf("%d\n",ans);
}