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

const int N=101000,inf=1<<30;
int n;
ll premx[N],premn[N],sufmx[N],sufmn[N];
ll p,q,r,a[N];
int main() {
	scanf("%d%lld%lld%lld",&n,&p,&q,&r);
	rep(i,1,n+1) scanf("%lld",a+i);
	premx[0]=-inf,premn[0]=inf;
	rep(i,1,n+1) {
		premx[i]=max(premx[i-1],a[i]);
		premn[i]=min(premn[i-1],a[i]);
	}
	sufmx[n+1]=-inf, sufmn[n+1]=inf;
	per(i,1,n+1) {
		sufmx[i]=max(sufmx[i+1],a[i]);
		sufmn[i]=min(sufmn[i+1],a[i]);
	}
	ll ret=-(1ll<<62);
	rep(i,1,n+1) {
		ret=max(ret,max(p*premx[i],p*premn[i])+q*a[i]+max(r*sufmx[i],r*sufmn[i]));
	}
	printf("%lld\n",ret);
}