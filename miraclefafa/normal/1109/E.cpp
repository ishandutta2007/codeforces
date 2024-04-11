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
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef pair<ll,ll> PLL;
namespace Factor {
	const int N=1010000;
	ll C,fac[10010],n,mut,a[1001000];
	int T,cnt,i,l,prime[N],p[N],psize,_cnt;
	ll _e[100],_pr[100];
	vector<ll> d;
	inline ll mul(ll a,ll b,ll p) {
		if (p<=1000000000) return a*b%p;
		else if (p<=1000000000000ll) return (((a*(b>>20)%p)<<20)+(a*(b&((1<<20)-1))))%p;
		else {
			ll d=(ll)floor(a*(long double)b/p+0.5);
			ll ret=(a*b-d*p)%p;
			if (ret<0) ret+=p;
			return ret;
		}
	}
	void prime_table(){
		int i,j,tot,t1;
		for (i=1;i<=psize;i++) p[i]=i;
		for (i=2,tot=0;i<=psize;i++){
			if (p[i]==i) prime[++tot]=i;
			for (j=1;j<=tot && (t1=prime[j]*i)<=psize;j++){
				p[t1]=prime[j];
				if (i%prime[j]==0) break;
			}
		}
	}
	void init(int ps) {
		psize=ps;
		prime_table();
	}
	ll powl(ll a,ll n,ll p) {
		ll ans=1;
		for (;n;n>>=1) {
			if (n&1) ans=mul(ans,a,p);
			a=mul(a,a,p);
		}
		return ans;
	}
	bool witness(ll a,ll n) {
		int t=0;
		ll u=n-1;
		for (;~u&1;u>>=1) t++;
		ll x=powl(a,u,n),_x=0;
		for (;t;t--) {
			_x=mul(x,x,n);
			if (_x==1 && x!=1 && x!=n-1) return 1;
			x=_x;
		}
		return _x!=1;
	}
	bool miller(ll n) {
		if (n<2) return 0;
		if (n<=psize) return p[n]==n;
		if (~n&1) return 0;
		for (int j=0;j<=7;j++) if (witness(rand()%(n-1)+1,n)) return 0;
		return 1;
	}
	ll gcd(ll a,ll b) {
		ll ret=1;
		while (a!=0) {
			if ((~a&1) && (~b&1)) ret<<=1,a>>=1,b>>=1;
			else if (~a&1) a>>=1; else if (~b&1) b>>=1;
			else {
				if (a<b) swap(a,b);
				a-=b;
			}
		}
		return ret*b;
	}
	ll rho(ll n) {
		for (;;) {
			ll X=rand()%n,Y,Z,T=1,*lY=a,*lX=lY;
			int tmp=20;
			C=rand()%10+3;
			X=mul(X,X,n)+C;*(lY++)=X;lX++;
			Y=mul(X,X,n)+C;*(lY++)=Y;
			for(;X!=Y;) {
				ll t=X-Y+n;
				Z=mul(T,t,n);
				if(Z==0) return gcd(T,n);
				tmp--;
				if (tmp==0) {
					tmp=20;
					Z=gcd(Z,n);
					if (Z!=1 && Z!=n) return Z;
				}
				T=Z;
				Y=*(lY++)=mul(Y,Y,n)+C;
				Y=*(lY++)=mul(Y,Y,n)+C;
				X=*(lX++);
			}
		}
	}
	void _factor(ll n) {
		for (int i=0;i<cnt;i++) {
			if (n%fac[i]==0) n/=fac[i],fac[cnt++]=fac[i];}
		if (n<=psize) {
			for (;n!=1;n/=p[n]) fac[cnt++]=p[n];
			return;
		}
		if (miller(n)) fac[cnt++]=n;
		else {
			ll x=rho(n);
			_factor(x);_factor(n/x);
		}
	}
	void dfs(ll x,int dep) {
		if (dep==_cnt) d.pb(x);
		else {
			dfs(x,dep+1);
			for (int i=1;i<=_e[dep];i++) dfs(x*=_pr[dep],dep+1);
		}
	}
	void norm() {
		sort(fac,fac+cnt);
		_cnt=0;
		rep(i,0,cnt) if (i==0||fac[i]!=fac[i-1]) _pr[_cnt]=fac[i],_e[_cnt++]=1;
			else _e[_cnt-1]++;
	}
	vector<ll> getd() {
		d.clear();
		dfs(1,0);
		return d;
	}
	vector<ll> factor(ll n) {
		cnt=0;
		_factor(n);
		norm();
		return getd();
	}
	vector<PLL> factorG(ll n) {
		cnt=0;
		_factor(n);
		norm();
		vector<PLL> d;
		rep(i,0,_cnt) d.pb(mp(_pr[i],_e[i]));
		return d;
	}
	bool is_primitive(ll a,ll p) {
		assert(miller(p));
		vector<PLL> D=factorG(p-1);
		rep(i,0,SZ(D)) if (powl(a,(p-1)/D[i].fi,p)==1) return 0;
		return 1;
	}
}

ll mul(ll a,ll b,ll m) {
	return a*b%m;
}

ll Inv(ll q,ll m) {
	if (q==0) return 0;
	assert(q>=0);
	ll a1=m,b1=0,a2=q,b2=1,a3,b3,t;
	while (a2!=1) {	t=a1/a2,a3=a1-t*a2,b3=b1-mul(t,b2,m),
		a1=a2,a2=a3,b1=b2,b2=b3;if (b2<0) b2+=m;}
	return b2;
}
ll merge(ll a,ll b,ll c,ll d) { // x=a (mod b) x=c (mod d)
	c-=a;
	ll dd=gcd(b,d);
	if (c%dd!=0) return -1;
	b/=dd; c/=dd; d/=dd;
	ll t=mul(c,Inv(b,d),d);
	if (t<0) t+=d;
	return b*t*dd+a;
}

const int N=101000;
int n,m,p,e,a[N],q[N][5];
ll pw[40];

typedef pair<int,int> st;
struct node {
	int fga;
	int fgm;
	st s;
}nd[4*N];

ll queryp(int c) {
	if (c>e) return 0;
	else return pw[c];
}

st operator + (const st &a,const st &b) {
	int mv=min(a.fi,b.fi);
	int wv=(a.se*queryp(a.fi-mv)+b.se*queryp(b.fi-mv))%pw[e];
	return mp(mv,wv);
}
void upd(int p) {
	nd[p].s=nd[p+p].s+nd[p+p+1].s;
}
void setfm(int p,ll v) {
	nd[p].fgm=nd[p].fgm*v%pw[e];
	nd[p].s.se=nd[p].s.se*v%pw[e];
}
void setfa(int p,int v) {
	nd[p].fga+=v;
	nd[p].s.fi+=v;
}

void build(int p,int l,int r) {
	nd[p].fga=0;
	nd[p].fgm=1;
	if (l==r) {
		int x=a[l],y=0;
		while (x%pw[1]==0) x/=pw[1],y++;
		x=x%pw[e];
		nd[p].s=mp(y,x);
	} else {
		int md=(l+r)>>1;
		build(p+p,l,md);
		build(p+p+1,md+1,r);
		upd(p);
	}
}
void push(int p) {
	if (nd[p].fga) {
		setfa(p+p,nd[p].fga);
		setfa(p+p+1,nd[p].fga);
		nd[p].fga=0;
	}
	if (nd[p].fgm!=1) {
		setfm(p+p,nd[p].fgm);
		setfm(p+p+1,nd[p].fgm);
		nd[p].fgm=1;
	}
}
st query(int p,int l,int r,int tl,int tr) {
	if (tl==l&&tr==r) return nd[p].s;
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) return query(p+p,l,md,tl,tr);
		else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
		else return query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr);
	}
}
void modifym(int p,int l,int r,int tl,int tr,int v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) return setfm(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modifym(p+p,l,md,tl,tr,v);
		else if (tl>md) modifym(p+p+1,md+1,r,tl,tr,v);
		else modifym(p+p,l,md,tl,md,v),modifym(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}
void modifya(int p,int l,int r,int tl,int tr,int v) {
	if (tl>tr) return;
	if (tl==l&&tr==r) return setfa(p,v);
	else {
		push(p);
		int md=(l+r)>>1;
		if (tr<=md) modifya(p+p,l,md,tl,tr,v);
		else if (tl>md) modifya(p+p+1,md+1,r,tl,tr,v);
		else modifya(p+p,l,md,tl,md,v),modifya(p+p+1,md+1,r,md+1,tr,v);
		upd(p);
	}
}

ll ans[N];
int Q;
int main() {
	scanf("%d%d",&n,&m);
//	n=100000; m=1<<29;
	Factor::init(100000);
	vector<PLL> d=Factor::factorG(m);
	rep(i,1,n+1) {
		scanf("%d",a+i);
//		a[i]=rand()%100000+1;
	}
	scanf("%d",&Q);
//	Q=100000;
	rep(i,0,Q) {
		scanf("%d%d%d",&q[i][0],&q[i][1],&q[i][2]);
//		q[i][0]=3; q[i][1]=rand()%n+1, q[i][2]=rand()%n+1;
//		if (q[i][1]>q[i][2]) swap(q[i][1],q[i][2]);
		if (q[i][0]==1) scanf("%d",&q[i][3]);
	}
	ll pre=1;
	for (auto pp:d) {
		p=pp.fi; e=pp.se;
		pw[0]=1;
		rep(j,0,e) pw[j+1]=pw[j]*p;
		build(1,1,n);
		rep(j,0,Q) {
			if (q[j][0]==1) {
				int l=q[j][1],r=q[j][2],x=q[j][3],y=0;
				while (x%p==0) x/=p,y++;
				modifym(1,1,n,l,r,x);
				modifya(1,1,n,l,r,y);
			} else if (q[j][0]==2) {
				int l=q[j][1],r=q[j][1],x=q[j][2],y=0;
				while (x%p==0) x/=p,y++;
				modifym(1,1,n,l,r,powmod(x,(p-1)*pw[e-1]-1,pw[e]));
				modifya(1,1,n,l,r,-y);
			} else {
				int l=q[j][1],r=q[j][2];
				auto w=query(1,1,n,l,r);
				ll c=w.se;
				c=c*powmod(p,w.fi,pw[e])%pw[e];
				ans[j]=merge(ans[j],pre,c,pw[e]);
			}
		}
		pre=pre*pw[e];
	}
	rep(j,0,Q) if (q[j][0]==3) printf("%lld\n",ans[j]);
}