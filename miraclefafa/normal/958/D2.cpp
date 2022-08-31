#include <bits/stdc++.h>
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
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head
 
inline int getint() {
	int ret=0;bool ok=0,neg=0;
	for(;;) {
		int c=getchar();
		if(c>='0'&&c<='9')ret=(ret<<3)+ret+ret+c-'0',ok=1;
		else if(ok)return neg?-ret:ret;
		else if(c=='-')neg=1;
	}
}
 
int m,d,n;
ll base[10][10],a[10];
map<ll,int> hs;
int main() {
	m=getint(); d=getint();
	rep(zz,0,m) {
		int c=getint();
		rep(j,0,d) rep(k,0,d) base[j][k]=0;
		rep(z,0,c) {
			rep(k,0,d) {
				a[k]=getint();
				if (a[k]<0) a[k]+=mod;
			}
			rep(j,0,d) {
				if (!a[j]) continue;
				if (base[j][j]) {
					ll w=mod-a[j];
					rep(k,j,d) a[k]=(a[k]+w*base[j][k])%mod;
				} else {
					ll w=powmod(a[j],mod-2);
					rep(k,j,d) base[j][k]=a[k]*w%mod;
					break;
				}
			}
		}
		rep(j,0,d) if (base[j][j]) {
			rep(i,0,j) if (base[i][j]) {
				ll w=mod-base[i][j];
				rep(k,j,d) {
					base[i][k]=(base[i][k]+w*base[j][k])%mod;
				}
			}
		}
		ll p=0;
		rep(j,0,d) {
			rep(k,0,d) p=p*13331+base[j][k];
		}
		if (!hs.count(p)) hs[p]=++n;
		printf("%d ",hs[p]);
	}
}