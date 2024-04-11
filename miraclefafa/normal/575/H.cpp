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

const int M=2000000,N=M+10;
ll fac[N],fnv[N];
int n;
ll comb(ll x,ll y) {
	return fac[x]*fnv[y]%mod*fnv[x-y]%mod;
}
int main() {
	fac[0]=1;
	rep(i,1,M+1) fac[i]=fac[i-1]*i%mod;
	fnv[M]=powmod(fac[M],mod-2);
	per(i,0,M) fnv[i]=fnv[i+1]*(i+1)%mod;
	scanf("%d",&n);
	ll ret=powmod(2,n+1)-1;
	ll cur=powmod(2,n);
	rep(i,n+1,2*n+1) {
		cur=(cur-comb(i-1,n))*2%mod;
//		printf("ff %lld %lld\n",cur,comb(i-1,n));
		if (cur<0) cur+=mod;
		ret=(ret+cur)%mod;
	}
	printf("%lld\n",ret);
}