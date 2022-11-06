#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=1e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll mn=5e5+4;
ll p[mn];
char s[mn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n; scanf("%lld",&n);
	for (ll i=0;i<n;i++) scanf("%lld",p+i);
	scanf("%s",s);
	scanf("%s",s);
	ll inita=0,initb=0;
	for (ll i=0;i<n;i++) {
		if (s[i]=='A') inita+=p[i];
		else initb+=p[i];
	}
	ll a=inita,b=initb;
	ll final=b;
	for (ll i=0;i<n;i++) {
		if (s[i]=='B') {b-=p[i]; a+=p[i];}
		else {a-=p[i]; b+=p[i];}
		chkmax(final,b);
	}
	a=inita,b=initb;
	for (ll i=n-1;i>=0;i--) {
		if (s[i]=='B') {b-=p[i]; a+=p[i];}
		else {a-=p[i]; b+=p[i];}
		chkmax(final,b);
	}
	printf("%lld\n",final);
}