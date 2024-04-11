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

int k;
ll x;
int main() {
	scanf("%d",&k);
	ll q=(mod-1)/2,d=2;
	rep(i,0,k) {
		scanf("%lld",&x);
		q=powmod(q,x);
		d=powmod(d,x);
	}
	d=d*powmod(2,mod-2)%mod;
	q=(q*2+1)%mod*powmod(3,mod-2)%mod;
	ll p=q*d%mod;
	printf("%lld/%lld\n",p,d);
}