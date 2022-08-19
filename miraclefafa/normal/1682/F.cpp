#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

const int N=201000;
int n,q;
ll a[N],b[N];
ll s[N],ans[N];
template<class T>
struct BIT {
	T c[N];
	int size;
	void resize(int s) { size = s;}
	T query(int x) { // 1 ... x
		assert(x <= size);
		T s = 0;
		for (; x; x -= x & (-x)) {
			s += c[x];
		}
		return s;
	}

	void modify(int x, T s) { // a[x] += s
		assert(x != 0);
		for (; x <= size; x += x & (-x)) {
			c[x] += s;
		}
	} 
};
BIT<ll> c1,c2;
vector<array<ll,3>> qu[N];

vector<ll> v;
int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) scanf("%lld",a+i);
	rep(i,1,n+1) a[i]=a[i+1]-a[i];
	rep(i,1,n+1) scanf("%lld",b+i),b[i]+=b[i-1];
	v.pb(0);
	rep(i,1,n+1) {
		v.pb(b[i]);
	}
	sort(all(v));
	v.erase(unique(all(v)),v.end());
	int m=SZ(v);
	ll sab=0,sa=0;
	rep(i,0,q) {
		int l,r;
		scanf("%d%d",&l,&r);
		if (b[r]!=b[l-1]) {
			ans[i]=0;
		} else {
			qu[r-1].pb({b[l-1],1,i});
			qu[l-1].pb({b[l-1],-1,i});
			//rep(j,l,r) ans[i]+=a[j]*abs(b[j]-b[l-1]);
		}
		//printf("%lld\n",ans[i]%mod);
	} 
	c1.resize(m); c2.resize(m);
	//rep(i,0,n+1) printf("%lld ",b[i]); puts("");
	rep(i,0,n) {
		int x=lower_bound(all(v),b[i])-v.begin()+1;
		c1.modify(x,b[i]*a[i]%mod);
		c2.modify(x,a[i]);
		sab=(sab+b[i]*a[i])%mod;
		sa=(sa+a[i])%mod;
		for (auto [x,sg,id]:qu[i]) {
			int y=lower_bound(all(v),x)-v.begin()+1;
			ll fab=c1.query(y)%mod;
			ll fa=c2.query(y)%mod;
			//printf("%d %lld %lld\n",i,fab,fa);
			ans[id]+=sg*((sab-fab)-x%mod*(sa-fa)-(fab-x%mod*fa));
		}
	}
	rep(i,0,q) {
		ans[i]%=mod;
		if (ans[i]<0) ans[i]+=mod;
		printf("%lld\n",ans[i]);
	}

}