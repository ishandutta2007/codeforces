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

const int N=(1<<21)+10;
int n,a[N],g[N],ans;
PII f[N];

void upd(PII &a,int b) {
	if (b>a.fi) a=mp(b,a.fi);
	else if (b>a.se) a=mp(a.fi,b);
}
int main() {
	scanf("%d",&n);
	rep(i,0,(1<<21)) f[i]=mp(-1,-1);
	rep(i,0,n) {
		scanf("%d",a+i);
		upd(f[a[i]],i);
	}
	/*rep(j,0,(1<<21)) if (f[j].se!=-1) {
		printf("%d %d\n",j,f[j].se);
	}*/

	// ffff
	rep(i,0,21) rep(j,0,(1<<21)) if (j&(1<<i)) {
		upd(f[j-(1<<i)],f[j].fi);
		upd(f[j-(1<<i)],f[j].se);
	}
	rep(j,0,(1<<21)) g[j]=f[j].se;
	rep(i,0,21) rep(j,0,(1<<21)) if (j&(1<<i)) {
		g[j-(1<<i)]=max(g[j-(1<<i)],g[j]);
	}
	rep(i,0,n) {
		int msk=0;
		if (g[0]<=i) continue;
		per(j,0,21) {
			int w=(a[i]>>j)&1;
			if (w==1) continue;
			if (g[msk|(1<<j)]>i) {
				msk|=(1<<j);
			}
		}
//		printf("%d %d\n",i,msk|a[i]);
		ans=max(ans,msk|a[i]);
	}
	printf("%d\n",ans);
}