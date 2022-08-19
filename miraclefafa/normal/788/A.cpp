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
int n,a[N];
ll b[N],r;
ll gao() {
	ll x=0,ret=0;
//	rep(i,1,n) printf("%lld ",b[i]); puts("");
	rep(i,1,n) {
		x+=b[i];
		ret=max(ret,x);
		if (x<0) x=0;
	}
	return ret;
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",a+i);
	rep(i,1,n) {
		b[i]=a[i]-a[i+1];
		if (b[i]<0) b[i]*=-1;
		if (i%2==0) b[i]*=-1;
	}
	r=gao();
	rep(i,1,n) b[i]*=-1;
	r=max(r,gao());
	printf("%lld\n",r);
}