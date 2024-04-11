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
int n,a[N],cnt,ct[N],lim[N];
ll ans;
VI pos[N];
set<PII> hs;
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%d",a+i);
		pos[a[i]].pb(i);
	}
	rep(i,1,n+1) if (SZ(pos[i])%2==1) cnt++;
	if (cnt>1) {
		puts("0");
		return 0;
	}
	cnt=0;
	rep(i,1,n+1) cnt+=(a[i]==a[n+1-i]);
	if (cnt==n) {
		printf("%I64d\n",1ll*n*(n+1)/2);
		return 0;
	}
	// not middle
	int md=n/2;
	int l=1;
	while (a[l]==a[n+1-l]) l++;
	--l;
	int r=1;
	while (a[md+1-r]==a[n-md+r]) r++;
	--r;
	rep(i,l+1,md+1-r) ct[a[i]]++,ct[a[n+1-i]]--;
	cnt=0;
	rep(i,1,n+1) cnt+=(ct[i]!=0);
	if (cnt==0) ans+=2*(l+1ll)*(r+1ll);
	// middle
	md=(n+1)/2;
	rep(i,1,n+1) {
		if (SZ(pos[i])==0) lim[i]=md;
		else lim[i]=min(md,pos[i][SZ(pos[i])/2]);
	}
	rep(i,1,n+1) ct[i]=SZ(pos[i]);
	rep(i,1,n+1) if (ct[i]) {
		hs.insert(mp(lim[i],i));
	}
	rep(i,1,md+1) {
		ans+=hs.begin()->fi-i+1;
		if (a[i]!=a[n+1-i]) break;
		ct[a[i]]-=2;
		if (ct[a[i]]==0) hs.erase(mp(lim[a[i]],a[i]));
	}

//
	rep(i,1,n+1) pos[a[i]].clear();
	reverse(a+1,a+n+1);
	rep(i,1,n+1) pos[a[i]].pb(i);
	hs.clear();
//
	rep(i,1,n+1) {
		if (SZ(pos[i])==0) lim[i]=md;
		else lim[i]=min(md,pos[i][SZ(pos[i])/2]);
	}
	rep(i,1,n+1) ct[i]=SZ(pos[i]);
	rep(i,1,n+1) if (ct[i]) {
		hs.insert(mp(lim[i],i));
	}
	rep(i,1,md+1) {
		ans+=hs.begin()->fi-i;
		if (a[i]!=a[n+1-i]) break;
		ct[a[i]]-=2;
		if (ct[a[i]]==0) hs.erase(mp(lim[a[i]],a[i]));
	}
	printf("%I64d\n",ans);
}