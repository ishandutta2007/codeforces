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

const int N=10100;
int n;
ll poly[N],q[N],ret[N],k,ans;
int a[N];
int main() {
	scanf("%d%lld",&n,&k);
	poly[0]=1;
	rep(i,0,n) {
		scanf("%d",a+i);
		per(j,0,i+1) poly[j+1]=(poly[j]+poly[j+1])%mod,poly[j]=poly[j]*(mod-a[i])%mod;
	}
	rep(i,0,n) {
		per(j,0,n+1) q[j]=poly[j];
		per(j,1,n+1) {
			ret[j-1]=(ret[j-1]+q[j])%mod;
			q[j-1]=(q[j-1]+q[j]*a[i])%mod;
		}
	}
	ll coef=1;
	rep(i,0,n) {
		coef=coef*(k-i)%mod;
		ans=(ans+powmod(n,mod-2-i)%mod*coef%mod*powmod(i+1,mod-2)%mod*ret[i])%mod;
	}
	ans=ans*powmod(mod-1,n+1)%mod;
	printf("%lld\n",ans);
}