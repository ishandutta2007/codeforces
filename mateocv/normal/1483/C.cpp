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

vector<pair<pair<ll,ll>,ll>> v;

struct STree { // example: range sum with range addition
	vector<ll> st,lazy;ll n;
	STree(ll n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	void push(ll k, ll s, ll e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(ll k, ll s, ll e, ll a, ll b, ll v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		ll m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return -1e18; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

STree st(300005);

vector<ll> ps;

void push(pair<ll,ll> val){
	ll van=1;
	while(SZ(v)&&v.back().fst.fst>=val.fst){
		auto b=v.back();
		auto r=ps.back();
		v.pop_back();
		ps.pop_back();
		ll l=0;
		if(SZ(ps))l=ps.back();
		st.upd(l,r,-b.fst.snd);
		van+=b.snd;
	}
	ll l=0;
	if(SZ(ps))l=ps.back();
	st.upd(l,l+van,val.snd);
	ps.pb(l+van);
	v.pb({val,van});
}

ll cant=0;

void db(ll n){
	cout<<"db "<<cant++<<":\n";
	fore(i,0,n)cout<<st.query(i,i+1)<<" ";
	cout<<"\n";
	for(auto i:v)cout<<i.fst.fst<<" "<<i.fst.snd<<" "<<i.snd<<"\n";
	for(auto i:ps)cout<<i<<" ";
	cout<<"\n";
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll> h(n+1),b(n+1);
	fore(i,0,n)cin>>h[i+1];
	fore(i,0,n)cin>>b[i+1];
	n++;
	h[0]=n+1;
	b[0]=0;
	st.upd(0,1,b[0]);
	//db(n);
	fore(i,1,n){
		push({h[i],b[i]});
		//db(n);
		st.upd(i,i+1,st.query(0,i));
		//db(n);
	}
	cout<<st.query(n-1,n)<<"\n";
	
	return 0;
}