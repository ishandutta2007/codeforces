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

const ll MOD=998244353;

ll add(ll x, ll y){
	x+=y;
	if(x>=MOD)x-=MOD;
	return x;
}

struct STree { // example: range sum with range addition
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=add(st[2*k],st[2*k+1]); // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]=add(st[k],(e-s)*lazy[k]%MOD); // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=add(lazy[2*k],lazy[k]);
			lazy[2*k+1]=add(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=add(lazy[k],v); // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=add(st[2*k],st[2*k+1]); // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return add(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main(){FIN;
	ll n; cin>>n;
	vector<ll> x(n),y(n),s(n);
	fore(i,0,n){
		cin>>x[i]>>y[i]>>s[i];
	}
	vector<pair<ll,ll>> v;
	vector<ll> ux(n),uy(n);
	fore(i,0,n){
		v.pb({x[i],i});
		v.pb({y[i],-i-1});
	}
	sort(ALL(v));
	fore(i,0,SZ(v)){
		if(v[i].snd>=0){
			ux[v[i].snd]=i;
		}else{
			uy[-v[i].snd-1]=i;
		}
	}
	ll res=(x[n-1]+1)%MOD;
	STree st(2*n);
	fore(i,0,n){
		if(s[i]){
			st.upd(ux[i],ux[i]+1,1);
		}
	}
	/*
	for(auto i:v)cout<<i.fst<<" "<<i.snd<<"\n";
	fore(i,0,n)cout<<ux[i]<<" "; 
	cout<<"\n";
	fore(i,0,n)cout<<uy[i]<<" "; 
	cout<<"\n";
	*/
	for(ll i=SZ(v)-1;i>=0;i--){
		if(v[i].snd>=0){
			auto c=st.query(i,i+1);
			//cout<<c<<"\n";
			//cout<<x[v[i].snd]-y[v[i].snd]<<"\n";
			res=add(res,c*(x[v[i].snd]-y[v[i].snd])%MOD);
			st.upd(uy[v[i].snd],ux[v[i].snd],c);
		}
	}
	cout<<res<<"\n";
	
	return 0;
}