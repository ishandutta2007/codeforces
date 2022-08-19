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
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef long double db;
const int N=401000;
int n,m,L;
db l[N],r[N],len[N],sp[N],f[N],cs[N],ct[N];
int ord[N];
struct node {
	db fg,s;
}nd[4*N];
void upd(int p) {
	nd[p].s=min(nd[p+p].s,nd[p+p+1].s);
}
void setf(int p,db v) {
	nd[p].fg+=v;
	nd[p].s-=v;
}
void build(int p,int l,int r) {
	nd[p].fg=0;
	if (l==r) {
		nd[p].s=f[l];
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void push(int p) {
	if (nd[p].fg>0) {
		setf(p+p,nd[p].fg);
		setf(p+p+1,nd[p].fg);
		nd[p].fg=0;
	}
}
db query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].s;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return min(query(p+p,l,md,tl,md),query(p+p+1,md+1,r,md+1,tr));
	}
}
void modify(int p,int l,int r,int tl,int tr,db v) {
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

int main() {
	scanf("%d%d",&n,&L);
	int px=0;
	auto add=[&](int x,int y,db s) {
		len[m]=y-x;
		sp[m]=s;
		++m;
	};
	rep(i,0,n) {
		int x,y;
		double s;
		scanf("%d%d%lf",&x,&y,&s);
		if (x>px) add(px,x,1);
		add(x,y,s+1);
		px=y;
	}
	if (px<L) add(px,L,1);
	db ans=0,sr=0;
	rep(i,0,m) {
		if (sp[i]==1) r[i]=len[i]; else r[i]=len[i]/(sp[i]-1)*sp[i];
		l[i]=len[i]/(sp[i]+1)*sp[i];
		ct[i]=1/sp[i];
		cs[i]=r[i]-l[i];
		sr+=r[i]-len[i];
		f[i]=sr;
		ans+=ct[i]*r[i];
		ord[i]=i;
		//printf("%d %.10Lf %.10Lf %.10Lf %.10Lf %.10Lf\n",i,l[i],r[i],ct[i],cs[i],f[i]);
	}
	build(1,0,m-1);
	sort(ord,ord+m,[&](int a,int b) {
		return ct[a]>ct[b];
	});
	rep(i,0,m) {
		int x=ord[i];
		db val=min(query(1,0,m-1,x,m-1),cs[x]);
		//printf("gg %d %.10Lf\n",x,val);
		r[x]-=val;
		ans-=val*ct[x];
		modify(1,0,m-1,x,m-1,val);
	}
	//rep(i,0,m) printf("%.10Lf\n",r[i]);
	printf("%.10f\n",(double)ans);
}