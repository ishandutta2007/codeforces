#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MOD 998244353

ll add(ll a, ll b){
	a+=b;
	if(a>=MOD)a-=MOD;
	return a;
}
ll sub(ll a, ll b){
	a-=b;
	if(a<0)a+=MOD;
	return a;
}
ll mul(ll a, ll b){return (a*b)%MOD;}
ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=mul(r,a);
		e>>=1;
		a=mul(a,a);
	}
	return r;
}
ll inv(ll a){return pm(a,MOD-2);}

int n,q;
ll p[200005];

pair<int,pair<ll,ll> > oper(pair<int,pair<ll,ll> > a, pair<int,pair<ll,ll> > b){
	int l0=a.fst;ll p0=a.snd.fst;ll e0=a.snd.snd;
	int l1=b.fst;ll p1=b.snd.fst;ll e1=b.snd.snd;

	int l=l0+l1;
	ll pp=mul(p0,p1);
	ll e=add(e0,mul(p0,add(e1,mul(l0,sub(1,p1)))));
	return mp(l,mp(pp,e));
}

#define NEUT mp(0,mp(1,0))
struct STree {
	vector<pair<int,pair<ll,ll> > > st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void init(int k, int s, int e, ll *a){
		if(s+1==e){
			st[k]=mp(1,mp(a[s],sub(1,a[s])));
			return;
		}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	pair<int,pair<ll,ll> > query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	ll query(int a, int b){
		auto pp=query(1,0,n,a,b);
		int l=pp.fst;ll p=pp.snd.fst;ll e=pp.snd.snd;
		return mul(add(mul(p,l),e),inv(p));
	}
};

set<int> w;

int main(){
	scanf("%d%d",&n,&q);
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		p[i]=mul(t,inv(100));
	}
	STree st(n);
	st.init(p);
	w.insert(0);w.insert(n);
	ll r=st.query(0,n);
	while(q--){
		int x;
		scanf("%d",&x);x--;
		auto it=w.lower_bound(x);
		if(*it==x){
			int b=*(++it);
			--it;
			int a=*(--it);
			r=sub(r,st.query(a,x));
			r=sub(r,st.query(x,b));
			r=add(r,st.query(a,b));
			w.erase(x);
		}
		else {
			int b=*it;
			int a=*(--it);
			r=sub(r,st.query(a,b));
			r=add(r,st.query(a,x));
			r=add(r,st.query(x,b));
			w.insert(x);
		}
		printf("%lld\n",r);
	}
	return 0;
}