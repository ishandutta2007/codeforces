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

const int N=401000;
int c[N],dp[N],n,ans;
PII p[N];
VI evt;
int query(int x) { int s=0; for (;x;x-=x&-x) s=max(s,c[x]); return s;}
void upd(int x,int s) { for (;x<=2*n;x+=x&-x) c[x]=max(c[x],s); }
int main() {
	scanf("%d",&n);
	rep(i,0,n) scanf("%d%d",&p[i].fi,&p[i].se);
	sort(p,p+n);
	ans=0;
	rep(i,0,n) evt.pb(p[i].fi-p[i].se),evt.pb(p[i].fi+p[i].se);
	sort(all(evt));
	rep(i,0,n) {
		dp[i]=query(lower_bound(all(evt),p[i].fi-p[i].se)-evt.begin()+1)+1;
		upd(lower_bound(all(evt),p[i].fi+p[i].se)-evt.begin()+1,dp[i]);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}