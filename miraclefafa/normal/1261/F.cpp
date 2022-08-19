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
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=998244353;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

struct segment {
	ll pl;
	int len;
};
int t,t1,t2;
segment seg[10100],s1[10100],s2[10100];
 
void query(int len,ll l,ll r,ll tl,ll tr) {
	if (l==tl&&r==tr) {
		 seg[t++]=(segment){tl,len};
	} else {
		ll md=(l+r)>>1;
		if (tr<=md) query(len-1,l,md,tl,tr);
		else if (tl>md) query(len-1,md+1,r,tl,tr);
		else query(len-1,l,md,tl,md),query(len-1,md+1,r,md+1,tr);
	}
}

vector<pair<ll,int>> rr;

struct Hash_table {
	static const int V=1000003;
	int fst[V],nxt[V];
	int ctm,ptm[V],T;
	ll val[V];
	ll key[V];
	void init() { T=0; ctm++;}
	void add(ll s,int v) {
		int S=s%V;
		if (ptm[S]!=ctm) ptm[S]=ctm,fst[S]=-1;
		for (int j=fst[S];j!=-1;j=nxt[j]) if (key[j]==s) {
			val[j]+=v;
			return;
		}
		nxt[T]=fst[S],fst[S]=T,key[T]=s,val[T]=v;
		T++;
	}
}hs;
 

struct ss {
	vector<pair<ll,ll>> seg;
	int n;
	pair<ll,ll> p[10100];
	void read() {
		scanf("%d",&n);
		rep(i,0,n) scanf("%lld%lld",&p[i].fi,&p[i].se);
		sort(p,p+n);
		ll l=-1,r=-1;
		rep(i,0,n) {
			if (p[i].fi>r) {
				if (r>0) seg.pb(mp(l,r));
				l=p[i].fi; r=p[i].se;
			} else {
				r=max(r,p[i].se);
			}
		}
		if (r>0) seg.pb(mp(l,r));
		//for (auto ww:seg) printf("zz %lld %lld\n",ww.fi,ww.se);
	}
}p1,p2;

ll ans=0;

ll C2(ll x) {
	x%=mod;
	return x*(x+1)/2%mod;
}

int main() {
	p1.read();
	p2.read();
	for (auto x:p1.seg) for (auto y:p2.seg) {
		hs.init();
		t=0;
		query(60,0,(1ll<<60)-1,x.fi,x.se);
		t1=t;
		rep(i,0,t1) s1[i]=seg[i];
		t=0;
		query(60,0,(1ll<<60)-1,y.fi,y.se);
		t2=t;
		rep(i,0,t2) s2[i]=seg[i];
		rep(i,0,t1) rep(j,0,t2) {
			auto p=s1[i],q=s2[j];
			int fred=max(p.len,q.len);
			ll tl=((p.pl^q.pl)>>fred)<<fred;
			hs.add(tl,1);
			hs.add(tl+(1ll<<fred),-1);
		}
		rep(i,0,hs.T) {
			rr.pb(mp(hs.key[i],hs.val[i]));
		}
	}
	sort(all(rr));
	ll pre=0;
	int cnt=0;
	rep(i,0,SZ(rr)) {
		if (cnt>0) {
			// pre -> rr[i].fi-1
			ans=(ans+C2(rr[i].fi-1)-C2(pre-1))%mod;
		}
		cnt+=rr[i].se;
		assert(cnt>=0);
		//printf("%lld %d %lld\n",rr[i].fi,cnt,ans);
		pre=rr[i].fi;
	}
	if (ans<0) ans+=mod;
	printf("%lld\n",ans);
}