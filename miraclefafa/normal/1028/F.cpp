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
typedef pair<ll,ll> PLL;

const int N=101000;
vector<PLL> v[N];
map<ll,int> hs;
int t,cnt,n,cur;
ll x,y;

struct Hash_table {
	static const int V=10000019;
	int fst[V],nxt[V],T;
	bool vis[V];
	int val[V];
	PLL key[V];
	void add(PLL s,int v) {
//		printf("add %lld %lld %d\n",s.fi,s.se,v);
		int S=(s.fi*13333331ll+s.se)%V;
		if (!vis[S]) vis[S]=1,fst[S]=-1;
		for (int j=fst[S];j!=-1;j=nxt[j]) if (key[j]==s) {
			val[j]+=v;
			return;
		}
		nxt[T]=fst[S],fst[S]=T,key[T]=s,val[T]=v;
		T++;
	}
	int query(PLL s) {
		int S=(s.fi*13333331ll+s.se)%V;
		if (!vis[S]) return 0;
		for (int j=fst[S];j!=-1;j=nxt[j]) if (key[j]==s) 
			return val[j];
		return 0;
	}
}ans;


PLL add(PLL a,PLL b) {
	ll d1=a.fi*b.se+a.se*b.fi;
	ll d2=a.se*b.se-a.fi*b.fi;
//	printf("ff %d %d\n",d1,d2);
	ll d=gcd(d1,d2);
	d1/=d; d2/=d;
	if (mp(d1,d2)<mp(0ll,0ll)) d1=-d1,d2=-d2;
//	printf("%lld %lld %lld %lld %lld %lld\n",a.fi,a.se,b.fi,b.se,d1,d2);
	return mp(d1,d2);
}

void add(int id,ll x,ll y) {
	cnt++;
	v[id].pb(mp(x,y));
	for (auto p:v[id]) {
		ans.add(add(p,mp(x,y)),p==mp(x,y)?1:2);
	}
}

void del(int id,ll x,ll y) {
	cnt--;
	for (auto p:v[id]) {
		ans.add(add(p,mp(x,y)),p==mp(x,y)?-1:-2);
	}
	v[id].erase(find(all(v[id]),mp(x,y)));
}


int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%d%lld%lld",&t,&x,&y);
		if (t==1) {
			if (!hs.count(x*x+y*y)) hs[x*x+y*y]=cur++;
			add(hs[x*x+y*y],x,y);
		} else if (t==2) {			
			del(hs[x*x+y*y],x,y);
		} else {
			printf("%d\n",cnt-ans.query(add(mp(x,y),mp(x,y))));
		}
	}
}