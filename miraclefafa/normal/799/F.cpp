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

template<class T>
class info {
public:
	T mx,s1,s2;
	info():mx(0),s1(0),s2(0) {}
	info(T mx,T s1, T s2):mx(mx),s1(s1),s2(s2) {}
	//operator T() const { return s; }
};

template<class T>
class tag {
public:
	T t;
	operator T() const { return t; }
	void clear() { t=0;}
	bool empty() { return t==0; }
};

template<class T>
info<T> operator +(info<T> a,info<T> b) {
	info<T> c{max(a.mx,b.mx),0,0};
	if (c.mx==a.mx) c.s1+=a.s1,c.s2+=a.s2;
	if (c.mx==b.mx) c.s1+=b.s1,c.s2+=b.s2;
	return c;
}

template<class T>
info<T> operator +(info<T> a,tag<T> b) {
	return (info<T>){a.mx+b,a.s1,a.s2};
}

template<class T>
tag<T> operator +(tag<T> a,tag<T> b) {
	return (tag<T>){a.t+b.t};
}

template<class info, class tag,int N>
class segtree {
	public:
	struct node {
		info s;
		tag t;
	}nd[4*N];
	int n;

	void init(int nn) {
		n=nn;
	}
	void upd(int p) {
		nd[p].s=nd[p+p].s+nd[p+p+1].s;
	}
	void setf(int p,tag v) {
		nd[p].s=nd[p].s+v;
		nd[p].t=nd[p].t+v;
	}
	void build(int p,int l,int r,function<void(int,info&)> setpos=[](int pos,info &a) { return; }) {
		nd[p].t.clear();
		if (l==r) {
			setpos(l,nd[p].s);
		} else {
			int md=(l+r)>>1;
			build(p+p,l,md,setpos);
			build(p+p+1,md+1,r,setpos);
			upd(p);
		}
	}
	void build(function<void(int,info&)> setpos=[](int pos,info &a) { return; }) {
		if (n==0) return;
		build(1,1,n,setpos);
	}
	void push(int p) {
		if (!nd[p].t.empty()) {
			setf(p+p,nd[p].t);
			setf(p+p+1,nd[p].t);
			nd[p].t.clear();
		}
	}
	info query(int p,int l,int r,int tl,int tr) {
		if (tl>tr) return info();
		if (tl==l&&tr==r) return nd[p].s;
		else {
			push(p);
			int md=(l+r)>>1;
			if (tr<=md) return query(p+p,l,md,tl,tr);
			else if (tl>md) return query(p+p+1,md+1,r,tl,tr);
			else return query(p+p,l,md,tl,md)+query(p+p+1,md+1,r,md+1,tr);
		}
	}
	info query(int tl,int tr) {
		if (tl>tr||n==0) return info();
		return query(1,1,n,tl,tr);
	}
	void modify(int p,int l,int r,int tl,int tr,tag v) {
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

	void modify(int tl,int tr,tag v) {
		if (tl>tr||n==0) return;
		return modify(1,1,n,tl,tr,v);
	}

	void change(int p,int l,int r,int x,info v) {
		if (l==r) nd[p].s=v;
		else {
			push(p);
			int md=(l+r)>>1;
			if (x<=md) change(p+p,l,md,x,v);
			else change(p+p+1,md+1,r,x,v);
			upd(p);
		}
	}

	void change(int x,tag v) {
		if (n==0) return;
		return change(1,1,n,x,v);
	}
};

const int N=201000;
int n,m,l[N],r[N],cnt[N],s[N];
vector<array<int,3>> evt[N];
ll ans=0;
segtree<info<ll>,tag<ll>,N> T;
int main() {
	scanf("%d%d",&n,&m);
	rep(i,0,n) {
		scanf("%d%d",l+i,r+i);
		s[l[i]]+=1;
		s[r[i]+1]-=1;
	}
	rep(p1,0,2) rep(p2,0,2) {
		rep(i,1,m+1) evt[i].clear();
		auto add=[&](int x1,int y1,int x2,int y2) {
			while ((x2+p2)%2) x2++;
			while ((y2+p2)%2) y2--;
			if (x1>y1||x2>y2)  return;
			evt[x1].pb({(x2+p2)/2,(y2+p2)/2,1});
			evt[y1+1].pb({(x2+p2)/2,(y2+p2)/2,-1});
		};
		rep(j,0,n) {
			add(1,l[j]-1,1,m);
			if ((r[j]-l[j])%2==0) add(r[j]+1,m,1,l[j]-1);
			if (r[j]%2==p2) add(r[j]+1,m,l[j],r[j]);
			add(r[j]+1,m,r[j]+1,m);
			if (p1==l[j]%2) add(l[j],r[j],1,l[j]-1);
			if (p1==p2) add(l[j],r[j],l[j],m);
		}
		int t=(m+p2)/2;
		if (t==0) continue;
		rep(i,1,t+1) cnt[i]=0;
		T.init(t);
		T.build([&](int pos,info<ll> &a) { a={0ll,1ll,2ll*pos-p2}; });
		rep(i,1,m+1) {
			for (auto p:evt[i]) {
				T.modify(p[0],p[1],{p[2]});
			}
			if (i%2==p1) {
				auto ret=T.query(1,(i+p2)/2);
				if (ret.mx==n) ans+=(i+1)*ret.s1-ret.s2;
			}
		}
	}
	int cc=0,len=0;
	rep(i,1,m+1) {
		cc+=s[i];
		if (cc==0) {
			len++;
			ans-=(ll)len*(len+1)/2;
		} else {
			len=0;
		}
	}
	printf("%lld\n",ans);
}