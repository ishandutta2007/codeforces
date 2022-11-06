#include <bits/stdc++.h>
#include <cstring>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define endl "\n"
const ll UNDEF = -1;
const ll INF=2e9;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
bool btw(ll a, ll b, ll c) {
	return (a<=b&&b<=c)||(a>=b&&b>=c);
}
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	ll n; string s; cin>>n>>s;
	ll px=0,py=0;
	ll cx=0,cy=0;
	ll ans=0;
	vector<pll> st;
	for (ll i=0;i<n;i++) {
		char c=s[i];
		ll dx=0,dy=0;
		if (c=='U') dy=1;
		if (c=='D') dy=-1;
		if (c=='L') dx=-1;
		if (c=='R') dx=1;
		ll ocx=cx,ocy=cy;
		cx+=dx;cy+=dy;
		if (btw(px,ocx,cx)&&btw(py,ocy,cy)) {
			// OK
		}
		else {
			px=ocx;py=ocy;
			st.PB(MP(px,py));
			//printf("%lld %lld\n",px,py);
			ans++;
		}
	}
	if (cx!=px||cy!=py) st.PB(MP(cx,cy));
	printf("%lld\n",(ll)st.size());
}