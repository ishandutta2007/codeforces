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

const int N=101000;
int n,k,a[N],cnt[N];
ll dp[N],pd[N];
void solve(int l,int r,int pl,int pr,ll val) {
	// pl+1 ... l-1
	if (l>r) return;
	int m=(l+r)>>1;
	ll nval=val;
	rep(i,l,m+1) nval+=cnt[a[i]]++;
	ll bres=pd[pl]+nval; int bp=pl;
	rep(i,pl+1,pr+1) if (i<m) {
		nval-=--cnt[a[i]];
//		printf("ff %d %d %lld\n",i+1,m,nval);
		if (pd[i]+nval<bres) bres=pd[i]+nval,bp=i;
	} else break;
	rep(i,l,m+1) --cnt[a[i]];
	rep(i,pl+1,pr+1) if (i<m) ++cnt[a[i]]; else break;
	dp[m]=bres;
	solve(l,m-1,pl,bp,val);
	nval=val;
	rep(i,l,m+1) nval+=cnt[a[i]]++;
	rep(i,pl+1,bp+1) nval-=--cnt[a[i]];
	solve(m+1,r,bp,pr,nval);
	// bp+1 ... m
	rep(i,l,m+1) cnt[a[i]]--;
	rep(i,pl+1,bp+1) ++cnt[a[i]];	
}
int main() {
	scanf("%d%d",&n,&k);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n+1) dp[i]=(1ll<<60);
	rep(j,0,k) {
		rep(i,1,n+1) pd[i]=dp[i],dp[i]=0;
		solve(1,n,0,n-1,0);
//		rep(i,1,n+1) printf("%lld ",dp[i]);
//		puts("");
	}
	printf("%lld\n",dp[n]);
}