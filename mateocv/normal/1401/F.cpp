#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int mk=0;

ll lg(ll n){
	return 31-__builtin_clz(n);
}

#define oper(a,b) a+b
#define NEUT 0
struct STree { // segment tree for min over integers
	vector<ll> st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		a=max(a,s),b=min(b,e);
		ll m=(s+e)/2;
		ll l=lg(k);
		if((1<<(17-l))&mk) return oper(query(2*k,s,m,a-(1<<(17-l)),b-(1<<(17-l))),query(2*k+1,m,e,a+(1<<(17-l)),b+(1<<(17-l))));
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);

STree st(1<<18);

int main(){FIN;
	ll n,q; cin>>n>>q;
	fore(i,0,(1<<n)){
		ll lle; cin>>lle;
		st.upd(i,lle);
	}
	while(q--){
		ll t; cin>>t;
		//fore(i,0,10)cout<<st.query(i,i+1)<<" "; cout<<"\n";
		if(t==1){
			ll x,k; cin>>x>>k; x--;
			st.upd(x^mk,k);
		}else if(t==2){
			ll k; cin>>k;
			mk^=(1<<k)-1;
		}else if(t==3){
			ll k; cin>>k;
			mk^=(1<<k);
		}else if(t==4){
			ll l,r; cin>>l>>r;
			cout<<st.query(l-1,r)<<"\n";
		}
		//fore(i,0,10)cout<<st.query(i,i+1)<<"\n";
	}
	
	return 0;
}