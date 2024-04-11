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
ll a,b;
vector<ll> vans;
bool dfs(ll x) {
	if (x>b) return false;
	if (x==b) {
		vans.PB(x);
		return true;
	}
	if (dfs(2*x)) {
		vans.PB(x);
		return true;
	}
	if (dfs(10*x+1)) {
		vans.PB(x);
		return true;
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	scanf("%lld%lld",&a,&b);
	dfs(a);
	if (vans.size()) {
		printf("YES\n%lld\n",(ll)vans.size());
		reverse(vans.begin(),vans.end());
		for (auto &w:vans) {
			printf("%lld ",w);
		}
		printf("\n");
	}
	else printf("NO\n");
}