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
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
typedef pair<ll,ll> pll;
typedef vector<ll> vll;

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll a,b,c; scanf("%lld%lld%lld",&a,&b,&c);
	ll m; scanf("%lld",&m);
	vector<pll> v;
	char t[10];
	for (ll i=0;i<m;i++) {
		ll cost; scanf("%lld %s\n",&cost,t);
		//printf("%s\n",t);/
		ll ty=0;
		if (t[0]=='P') ty=1;
		v.PB(MP(cost,ty));
	}
	sort(v.begin(),v.end());
	ll num=0;
	ll ans=0;
	for (auto &w:v) {
		ll cost=w.first,t=w.second;
		if (t==0) {
			if (a>0) {a--; ans+=cost;num++;}
			else if (c>0) {c--; ans+=cost;num++;}
		}
		else {
			if (b>0) {b--; ans+=cost;num++;}
			else if (c>0) {c--; ans+=cost;num++;}
		}
	}
	printf("%lld %lld\n",num,ans);
}