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

ll n,l,r;
int ret;
int main() {
	scanf("%lld%lld%lld",&n,&l,&r);
	ll p=n; int lg=0;
	while (p) p/=2,lg++;
	for (ll i=l;i<=r;i++) {
		int j=lg-1; ll p=i;
		while (p%2==0) p/=2,j--;
//		printf("%lld %d\n",i,j);
		ret+=(n>>j)&1;
	}
	printf("%d\n",ret);
}