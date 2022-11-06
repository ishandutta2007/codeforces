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
const ll MAXN=1008;
typedef pair<ll, ll> point;
point v[MAXN];
long long ccw(point a, point b, point c) {
	b.first -= a.first; b.second -= a.second;
	c.first -= a.first; c.second -= a.second;
	return b.first * (long long)c.second - c.first * (long long)b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	ll n; scanf("%I64d",&n);
	for (ll i=0;i<n+1;i++) {
		ll x,y;
		scanf("%I64d %I64d",&x,&y);
		v[i]=MP(x,y);
	}
	ll ans=0;
	for (ll i=0;i<n;i++) {
		point a=v[i];
		point b=v[(i+1)%n];
		point c=v[(i+2)%n];
		if (ccw(a,b,c)>0) ans++;
	}
	printf("%I64d\n",ans);
}