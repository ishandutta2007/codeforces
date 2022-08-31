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

const int N=101000;
ll fac[N],fnv[N];
int f,w,h;
ll comb(ll x,ll y) {
	if (x<0||y<0||y>x) return 0;
	return fac[x]*fnv[y]%mod*fnv[x-y]%mod;
}
int main() {
	fac[0]=fnv[0]=1;
	rep(i,1,100001) fac[i]=fac[i-1]*i%mod,fnv[i]=powmod(fac[i],mod-2);
	scanf("%d%d%d",&f,&w,&h);
	if (f==0) {
		if (w<=h) puts("0");
		else puts("1");
		return 0;
	}
	if (w==0) {
		puts("1");
		return 0;
	}
	ll r1=0,r2=0;
	rep(i,1,100001) {
		// w -> i 
		ll t1=comb(w-1,i-1),t2=comb(w-(ll)h*i-1,i-1);
		ll t3=2*comb(f-1,i-1)+comb(f-1,i-2)+comb(f-1,i);
//		if (i<=10) printf("%lld %lld %lld\n",t1,t2,t3);
		r1=(r1+t1*t3)%mod; r2=(r2+t2*t3)%mod;
	}
	r2=r2*powmod(r1,mod-2)%mod;
	printf("%lld\n",r2);
}