#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
#include <queue>
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
typedef pair<ll,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=110;
ll inf=(1ll<<60);
priority_queue<PII,vector<PII>,greater<PII> > q;
int n,a[N],g[N];
int W=100000;
ll k;
ll nnext(int a,ll l) {
	if (l>=a) return inf;
	else return (a-1)/((a-1)/l)+1;
}
int main() {
	scanf("%d%lld",&n,&k);
	rep(i,0,n) scanf("%d",a+i);
	ll v=1;
	rep(d,1,W+1) {
		ll cc=0;
		rep(i,0,n) cc+=(a[i]+d-1)/d*d-a[i];
		if (cc<=k) v=d;
	}
	ll sl=0,st=0;
	rep(i,0,n) sl+=(g[i]=(a[i]+W-1)/W),st+=a[i];
	rep(i,0,n) {
		q.push(mp(nnext(a[i],W),i));
	}
	ll l=W;
	while (1) {
		PII it=q.top(); q.pop();
		ll r=it.fi-1; int id=it.se;
//		printf("%lld %d\n",r,id);
		if (l<=r) {
			ll t=min((st+k)/sl,r);
			if (t>=l) v=t;
		}
		l=r+1;
		if (it.fi==inf) break;
		else {
			sl-=g[id];
			sl+=g[id]=(a[id]+l-1)/l;
			q.push(mp(nnext(a[id],l),id));
		}
	}
	printf("%lld\n",v);
}