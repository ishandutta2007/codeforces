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
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

int _;
ll a,b;
int main() {
	for (scanf("%d",&_);_;_--) {
		scanf("%lld%lld",&a,&b);
		ll t=pow(a*b,1./3);
		while (t*t*t<a*b) ++t;
		while (t*t*t>a*b) --t;
		if (a*b!=t*t*t) {
			puts("No");
			continue;
		} else {
			ll w=__gcd(a,b),c=a*b;
			rep(i,0,3) {
				ll d=__gcd(c,w);
				c/=d;
			}
			if (c!=1) puts("No");
			else puts("Yes");
		}
	}
}