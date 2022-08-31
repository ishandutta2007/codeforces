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
ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=1010000;
PII c[N],lp[N],rp[N];
int n,m,q,x[N],y[N],a[N],lq[N],rq[N],imp[N];
VI vec;
vector<PII> que[N];
PII operator+(const PII& a,const PII &b) {
	if (a.fi>b.fi) return a;
	else if (a.fi<b.fi) return b;
	else return mp(a.fi,(a.se+b.se)%mod);
}
PII query(int x) {
	PII s=mp(0,1);
	for (;x;x-=x&-x) s=s+c[x];
	return s;
}
void modify(int x,PII s) {
	for (;x<=m;x+=x&-x) c[x]=c[x]+s;
}
bool prime(int x) {
	for (int i=2;i*i<=x;i++) if (x%i==0) return 0;
	return 1;
}
int main() {
	scanf("%d%d",&n,&q);
	rep(i,1,n+1) scanf("%d",a+i),vec.pb(a[i]);
	mod=1000000000+rand()%10000;
	while (!prime(mod)) mod=1000000000+rand()%10000;
	rep(i,0,q) {
		scanf("%d%d",x+i,y+i);
//		que[x].pb(mp(y,i));
		vec.pb(y[i]);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)),vec.end());
	rep(i,1,n+1) a[i]=lower_bound(all(vec),a[i])-vec.begin()+1;
	rep(i,0,q) {
		y[i]=lower_bound(all(vec),y[i])-vec.begin()+1;
		que[x[i]].pb(mp(y[i],i));
	}
	m=SZ(vec);
//	vec.clear();
	PII ret=mp(0,1);
	rep(i,1,n+1) {
//		PII p=query(a[i]);
		lp[i]=query(a[i]-1);
		for (auto q:que[i]) {
			int y=q.fi,id=q.se;
			lq[id]=query(y-1).fi;
		}
		modify(a[i],mp(lp[i].fi+1,lp[i].se));
		ret=ret+mp(lp[i].fi+1,lp[i].se);
	}
	rep(i,1,m+1) c[i]=mp(0,0);
	per(i,1,n+1) {
		rp[i]=query(m-a[i]);
		for (auto q:que[i]) {
			int y=q.fi,id=q.se;
			rq[id]=query(m-y).fi;
		}
		modify(m+1-a[i],mp(rp[i].fi+1,rp[i].se));
	}
	rep(i,1,n+1) {
		if (lp[i].fi+1+rp[i].fi==ret.fi&&((ll)lp[i].se*rp[i].se%mod==ret.se)) {
			imp[i]=1;
		}
		//printf("%d %d %d %d %d\n",lp[i].fi,rp[i].fi,lp[i].se,rp[i].se,imp[i]);
	}
	//rep(i,0,q) printf("%d %d\n",lq[i],rq[i]);
	rep(i,0,q) {
		int id=x[i];
		if (!imp[id]) {
			printf("%d\n",max(ret.fi,lq[i]+rq[i]+1));
		} else {
			printf("%d\n",max(ret.fi-1,lq[i]+rq[i]+1));
		}
	}
}