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

const int N=401000;
struct F {
	ll a,b;
};

bool operator < (F a,F b) {
	return a.a*b.b>a.b*b.a;
}
bool operator == (F a,F b) {
	return a.a*b.b==a.b*b.a;
}

struct node {
	int fg,mx;
}nd[4*N];
void upd(int p) {
	nd[p].mx=min(nd[p+p].mx,nd[p+p+1].mx);
}
void setf(int p,int v) {
	nd[p].fg+=v;
	nd[p].mx+=v;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	nd[p].mx=0;
	if (l==r) {
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void push(int p) {
	if (nd[p].fg) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
void modify(int p,int l,int r,int tl,int tr,int v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) return setf(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modify(p+p,l,md,tl,tr,v);
		else if (tl>md) modify(p+p+1,md+1,r,tl,tr,v);
		else modify(p+p,l,md,tl,md,v),modify(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}


int n,m,a[N],sz[N],s[N];
ll sm[N];
vector<F> sc[N];
void solve() {
	scanf("%d%d",&n,&m);
	vector<F> num;
	rep(i,0,n) {
		scanf("%d",a+i);
		num.pb({a[i],1});
	}
	rep(i,0,m) {
		int k;
		scanf("%d",&k);
		ll ts=0;
		rep(j,0,k) {
			scanf("%d",s+j);
			ts+=s[j];
		}
		sc[i].clear();
		sz[i]=k;
		sm[i]=ts;
		num.pb({ts,k});
		rep(j,0,k) {
			sc[i].pb({ts-s[j],k-1});
			num.pb({ts-s[j],k-1});
		}
	}
	sort(all(num));
	num.erase(unique(all(num)),num.end());
	int X=SZ(num);
	build(1,1,X);
	rep(i,0,n) {
		int pos=lower_bound(all(num),(F){a[i],1})-num.begin()+1;
		modify(1,1,X,pos,X,1);
	}
	rep(i,0,m) {
		int pos=lower_bound(all(num),(F){sm[i],sz[i]})-num.begin()+1;
		modify(1,1,X,pos,X,-1);
	}
	rep(i,0,m) {
		int pos=lower_bound(all(num),(F){sm[i],sz[i]})-num.begin()+1;
		modify(1,1,X,pos,X,1);

		for (auto p:sc[i]) {
			int pos2=lower_bound(all(num),p)-num.begin()+1;
			modify(1,1,X,pos2,X,-1);
			if (nd[1].mx<0) putchar('0'); else putchar('1');
			modify(1,1,X,pos2,X,1);
		}
		modify(1,1,X,pos,X,-1);

	}
	puts("");
}

int _;
int main() {
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}