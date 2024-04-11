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

int a,b,c,l;
ll ans;
int main() {
	scanf("%d%d%d%d",&a,&b,&c,&l);
	rep(u,1,a+b+c+l+1) {
		int rv=0,rw=0;
		if (2*a-u>0) rv=2*a-u; else rv=(u-1)%2+1;
		if (2*c-u>0) rw=2*c-u; else rw=(u-1)%2+1;
		int e=2*b-rv-rw,d=a+b+c+l-u-rv-rw;
//		fprintf(stderr,"%d %d %d %d %d\n",u,rv,rw,c,d);
		// c<=(p+q)<=d
		if (e<0) e=0;
		if (e>d) continue;
		d/=2; e=(e+1)/2;
		ans+=(d+1ll)*(d+2ll)/2-e*(e+1ll)/2;
	}
	printf("%lld\n",ans);
}