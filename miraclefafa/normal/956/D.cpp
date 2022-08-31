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

const int N=101000;
struct frac{
	ll p,q;
	int e,id;
};
vector<frac> up,down;
int n,w,x,v;
int rk[N],c[N];
ll ret;
int query(int x) {
	int s=0;
	for (;x;x-=x&-x) s+=c[x];
	return s;
}
void upd(int x,int s) {
	for (;x<=n;x+=x&-x) c[x]+=s;
}
bool operator < (frac a, frac b) {
	// a.p/(a.q+a.e*eps) < b.p/(b.q+b.e*eps)
	if (a.p*b.q!=a.q*b.p) {
		return a.p*b.q<b.p*a.q;
	} else {
		return a.p*b.e<b.p*a.e;
	}
}
int main() {
	scanf("%d%d",&n,&w);
	rep(i,0,n) {
		scanf("%d%d",&x,&v);
		if (v<0) {
			up.pb((frac){x,-v+w,1,i});
			down.pb((frac){x,-v-w,-1,i});
		// x + vt = (w+eps) t
		// x + vt = (-w-eps) t
		} else {
			// x + vt = (w+eps) t
			// x + vt = (-w-eps) t
			up.pb((frac){-x,v-w,-1,i});
			down.pb((frac){-x,v+w,1,i});
		}
	}
	sort(all(up));
	sort(all(down));
//	rep(i,0,n) printf("%lld/%lld, %d, %d\n",up[i].p,up[i].q,up[i].e,up[i].id);
	rep(i,0,n) rk[up[i].id]=i+1;
	per(i,0,n) {
		ret+=query(rk[down[i].id]);
		upd(rk[down[i].id]+1,1);
	}
	printf("%lld\n",ret);
}