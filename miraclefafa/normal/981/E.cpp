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

typedef bitset<10002> state;
const int N=10100;
int n,q,l,r,c,ans;
state tmp[N*4],cur,ret;
VI nd[N*4];
void modify(int p,int l,int r,int tl,int tr,int v) {
	if (tl==l&&tr==r) nd[p].pb(v);
	else {
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
	}
}
void solve(int p,int l,int r) {
	tmp[p]=cur;
	for (auto l:nd[p]) cur|=cur<<l;
	if (l==r) {
		ret|=cur;
	} else {
		int md=(l+r)>>1;
		solve(p+p,l,md);
		solve(p+p+1,md+1,r);
	}
	cur=tmp[p];
}
int main() {
	scanf("%d%d",&n,&q);
	rep(i,0,q) {
		scanf("%d%d%d",&l,&r,&c);
		modify(1,1,n,l,r,c);
	}
	cur[0]=1;
	solve(1,1,n);

	rep(i,1,n+1) if (ret[i]) ans++;
	printf("%d\n",ans);
	rep(i,1,n+1) if (ret[i]) printf("%d ",i);
}