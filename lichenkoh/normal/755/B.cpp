#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
#define fst first
const ll UNDEF = -1;
const ll INF=1e18;
template<typename T> inline bool chkmax(T &aa, T bb) { return aa < bb ? aa = bb, true : false; }
template<typename T> inline bool chkmin(T &aa, T bb) { return aa > bb ? aa = bb, true : false; }
template<class T> T extgcd(T a, T b, T& x, T& y) { for (T u = y = 1, v = x = 0; a;) { T q = b / a; swap(x -= q * u, u); swap(y -= q * v, v); swap(b -= q * a, a); } return b; }
template<class T> T mod_inv(T a, T m) { T x, y; extgcd(a, m, x, y); return (m + x % m) % m; }
ll mod_pow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
const ll mn=1e3+4;
string a[mn],b[mn];
int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll n,m; cin>>n>>m;
	for (ll i=0;i<n;i++) {cin>>a[i];}
	for (ll j=0;j<m;j++) cin>>b[j];
	set<string> s;
	for (ll i=0;i<n;i++) {
		s.insert(a[i]);
	}
	ll inter=0;
	for (ll j=0;j<m;j++) {
		if (s.find(b[j])!=s.end()) inter++;
	}
	ll A=n-inter,B=m-inter,C=inter;
	ll turn=0;
	while(1) {
		if (C>0) C--;
		else {
			if (turn==0) {
				if (A==0) {
					printf("NO\n");
					return 0;
				}
				A--;
			}
			else {
				if (B==0) {
					printf("YES\n");
					return 0;
				}
				B--;
			}
		}
		turn^=1; 
	}
}