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
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

struct segcover {
	map<PII,int> sg;
	int L_,R_;
	void init(int L,int R) {
		sg[{L-1,L-1}]=-1;
		sg[{R+1,R+1}]=-1;
		L_=L-1; R_=R+1;
	}
	void add(int l,int r,int id,function<void(int,int,int)>delseg=[](int l,int r,int id) {},
		function<void(int,int,int)> addseg=[](int l,int r,int id) {}) {
		auto split=[&](int p) {
			auto pl=--sg.lower_bound({p,L_});
			if (pl->fi.se>p) {
				int l=pl->fi.fi,r=pl->fi.se,id=pl->se;
				sg.erase(pl);
				sg[{l,p}]=id;
				sg[{p,r}]=id;
			}
		};
		split(l); split(r);
		auto pl=sg.lower_bound({l,L_});
		while (1) {
			auto pr=pl; ++pr;
			if (pl->fi.fi>=r) break;
			delseg(pl->fi.fi,pl->fi.se,pl->se);
			sg.erase(pl);
			pl=pr;
		}
		addseg(l,r,id);
		sg[{l,r}]=id;
	}
};

segcover seg;
const int N=301000;
int n,k,l[N],r[N],cnt[N];
ll ans;
vector<array<int,4>> op[N];

int main() {
	scanf("%d%d",&n,&k);
	seg.init(-1,1000000001);
	rep(i,1,n+1) {
		scanf("%d%d",l+i,r+i);
		seg.add(l[i],r[i],i,[&](int l,int r,int id) { op[i].pb({l,r,id,-1}); },
			[&](int l,int r,int id) {op[i].pb({l,r,id,1}); });
	}
	int l=0,r=1e9+1;
	while (l+1<r) {
		int md=(l+r)>>1;
		rep(i,1,n+1) cnt[i]=0;
		int L=1;
		ll val=0,tots=0,len2=0,tl=0,len=0;
		rep(R,1,n+1) {
			for (auto x:op[R]) {
				if (x[2]>=L) len-=cnt[x[2]];
				else len2-=(ll)cnt[x[2]]*x[2];
				if (x[3]==1) cnt[x[2]]+=x[1]-x[0],tl+=x[1]-x[0];
				else cnt[x[2]]-=x[1]-x[0],tl-=x[1]-x[0];
				if (x[2]>=L) len+=cnt[x[2]];
				else len2+=(ll)cnt[x[2]]*x[2];
			}
			while (len>=md) {
				len-=cnt[L];
				len2+=(ll)cnt[L]*L;
				L++;
			}
			tots+=len*(L-1)+len2;
			val+=L-1;
			//printf("%d %lld %lld %lld %lld\n",md,val,tots,len,len2);
		}
		//printf("%d %lld %lld\n",md,val,tots);
		if (val>=k) l=md,ans=tots-(val-k)*l;
		else r=md;
	}
	printf("%lld\n",ans);
}