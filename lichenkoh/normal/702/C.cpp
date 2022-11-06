#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll UNDEF = -1;
template<typename T> inline bool chkmax(T &a, T b) { return a < b ? a = b, true : false; }
template<typename T> inline bool chkmin(T &a, T b) { return a > b ? a = b, true : false; }
const ll MAXN=1e5+4;
const ll INF=1e11;
ll va[MAXN];
vector<ll> a,b,c;
int main() {
	ios_base::sync_with_stdio(false);
	ll n,m; scanf("%I64d %I64d",&n,&m);
	for (ll i=1;i<=n;i++) {
		ll x; scanf("%I64d",&x); a.PB(x);
	}
	for (ll i=0;i<m;i++) {
		ll x; scanf("%I64d",&x); b.PB(x);
	}
	b.PB(-INF); b.PB(INF);
	sort(b.begin(),b.end());
	c=b;
	reverse(c.begin(),c.end());
	ll bsz=b.size();
	ll ans=0;
	for (auto &w:a) {
		ll c1,c2;
		{
			ll imin=0,imax=bsz;
			while(imin<imax) {
				ll imid=(imin+imax)/2;
				if (b[imid]<w)imin=imid+1;
				else imax=imid;
			}
			c1=abs(b[imin]-w);
		}
		{
			ll imin=0,imax=bsz;
			while(imin<imax) {
				ll imid=(imin+imax)/2;
				if (c[imid]>w)imin=imid+1;
				else imax=imid;
			}
			c2=abs(c[imin]-w);
		}
		chkmax(ans,min(c1,c2));
	}
	printf("%I64d\n",ans);
}