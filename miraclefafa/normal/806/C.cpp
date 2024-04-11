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
typedef vector<long long> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=101000;
int n,cnt[66],c[66];
ll x,a[N];
VI tail;
map<ll,int> hs;
bool check(int x) {
	rep(i,0,61) c[i]=cnt[i];
	c[0]-=x;
	VI tl=tail;
	rep(j,0,x) tl.pb(1);
	int mv=c[0];
	rep(i,0,61) {
		rep(j,mv,c[i]) tl.pb(1ll<<i);
		mv=min(mv,c[i]);
		c[i]=mv;
	}
	sort(all(tl));
	VI hd;
	rep(i,0,61) rep(j,c[i+1],c[i]) hd.pb(1ll<<i);
	sort(all(hd));
	if (SZ(hd)<SZ(tl)) return 0;
	reverse(all(hd)); reverse(all(tl));
	rep(i,0,SZ(tl)) if (2*hd[i]<tl[i]) return 0;
	return 1;
}
int main() {
	scanf("%d",&n);
	rep(i,0,61) hs[1ll<<i]=i;
	rep(i,0,n) {
		scanf("%lld",a+i);
		if (!hs.count(a[i])) tail.pb(a[i]);
		else cnt[hs[a[i]]]++;
	}
	if (!check(0)) {
		puts("-1");
		return 0;
	}
	int l=0,r=cnt[0]+1;
	while (l+1<r) {
		int md=(l+r)>>1;
		if (check(md)) l=md; else r=md;
	}
	rep(i,cnt[0]-l,cnt[0]+1) printf("%d ",i);
}