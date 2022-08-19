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

struct item {
	ll a,b,c;
	item() {}
	item(ll a,ll b,ll c):a(a),b(b),c(c){}
};
vector<item> pnt;
int n,a,b,c,p0;
map<pair<ll,ll>,int> hs;
ll ans;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%d%d",&a,&b,&c);
		if (c==0) p0++;
		else {
			pnt.pb(item(a,b,c));
		}
	}
	ans=p0*(p0-1ll)/2*(n-p0);
	rep(i,0,SZ(pnt)) {
		hs.clear();
		item z2=pnt[i];
		rep(j,i+1,SZ(pnt)) {
			item z3=pnt[j];
			ll a=z3.c*(z2.a*z3.a+z2.b*z3.b);
			ll b=z3.c*(z2.b*z3.a-z2.a*z3.b);
			ll c=z2.c*(z3.a*z3.a+z3.b*z3.b);
//			printf("%lld %lld %lld\n",a,b,c);
			a=c-a; b=-b;
			ll d=__gcd(a,b);
			a/=d; b/=d;
			if (b<0) b*=-1,a*=-1;
			else if (b==0) {
				if (a<0) a*=-1;
			}
			ans+=hs[mp(a,b)];
			hs[mp(a,b)]++;
		}
	}
	printf("%lld\n",ans);
}