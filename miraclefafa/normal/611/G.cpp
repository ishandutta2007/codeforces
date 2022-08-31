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
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1001000;
ll x[N],y[N],s[N],sx[N],sy[N],ans,ss[N];
int n;
ll area(int i,int j) {
	return s[j-1]-s[i-1]-(x[j]*y[i]-x[i]*y[j]);
}
int main() {
	scanf("%d",&n);
	rep(i,1,n+1) {
		scanf("%lld%lld",x+i,y+i);
		x[i+n]=x[i]; y[i+n]=y[i];
	}
	x[n+n+1]=x[n+1]; y[n+n+1]=y[n+1];
	rep(i,1,n+n+1) s[i]=x[i+1]*y[i]-x[i]*y[i+1];
	rep(i,1,n+n+1) sx[i]=(sx[i-1]+x[i])%mod,sy[i]=(sy[i-1]+y[i])%mod;
	rep(i,1,n+n+1) {
		s[i]+=s[i-1];
		if (i<=n) ss[i]=(ss[i-1]+s[i])%mod;
		else ss[i]=((ss[i-1]+s[n])%mod+s[i-n])%mod;
	}
	int r=1;
//	ll c=0;
//	rep(i,1,n+1) rep(j,i+2,i+n-1) c+=max(area(i,j)-area(j,i+n),area(j,i+n)-area(i,j));
//	printf("%lld\n",c);
	rep(i,1,n+1) {
		while (r<i+n&&area(i,r)<=area(r,i+n)) ++r;
		ans=(ans+(s[i-1]%mod*2+s[n])%mod*(r-i-2))%mod;
		ans=(ans-2*(ss[r-2]-ss[i]))%mod;
		ans=(ans-(x[i]+x[i+n])%mod*(sy[r-1]-sy[i+1]))%mod;
		ans=(ans+(y[i]+y[i+n])%mod*(sx[r-1]-sx[i+1]))%mod;

		ans=(ans-(s[i-1]%mod*2+s[n])%mod*(i+n-1-r))%mod;
		ans=(ans+2*(ss[i+n-3]-ss[r-2]))%mod;
		ans=(ans+(x[i]+x[i+n])%mod*(sy[i+n-2]-sy[r-1]))%mod;
		ans=(ans-(y[i]+y[i+n])%mod*(sx[i+n-2]-sx[r-1]))%mod;

	}
	if (ans%2==0) ans/=2; else ans=(ans+mod)/2;
	if (ans<0) ans+=mod;
	printf("%lld\n",ans);
}