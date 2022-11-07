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

struct STree { // example: range sum with range addition
	vector<ll> st,lazy;ll n;
	STree(ll n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(ll k, ll s, ll e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
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
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		ll m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll a, ll b, ll v){upd(1,0,n,a,b,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll> v(n);
		fore(i,0,n)cin>>v[i];
		STree st(n);
		fore(i,0,n)st.upd(i,i+1,v[i]);
		vector<ll> res;
		while(n){
			if(st.query(n-1,n)==n)res.pb(1);
			else res.pb(0);
			auto q=st.query(0,n);
			assert(q%n==0);
			ll c=q/n;
			st.upd(n-c,n,-1);
			n--;
		}
		reverse(ALL(res));
		for(auto i:res)cout<<i<<" ";
		cout<<"\n";//
	}
	
	return 0;
}