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

ll pot2[300005],pot3[300005];

pair<ll,ll> operator+(pair<ll,ll> a, pair<ll,ll> b){
	ll res=(a.fst*pot2[a.snd]+b.fst*pot2[b.snd])%MOD;
	return {res,0};
}

void acl(pair<ll,ll> &a, pair<ll,ll> b){
	if(b.fst){
		a=b;
	}else{
		if(a.fst){
			a.snd=a.snd*pot2[b.snd]%MOD;
		}else{
			a.snd+=b.snd;
		}
	}
}

struct STree { // example: range sum with range addition
	vector<pair<ll,ll>> st,lazy;int n;
	STree(int n): st(4*n+5,{0,0}), lazy(4*n+5,{0,0}), n(n) {}
	void push(int k, int s, int e){
		if(lazy[k].fst==0&&lazy[k].snd==0)return; // if neutral, nothing to do
		// update st according to lazy
		if(lazy[k].fst){
			st[k].fst=lazy[k].snd*(e-s)%MOD;
			st[k].snd=0; 
		}else{
			st[k].snd+=lazy[k].snd; 
		}
		if(s+1<e){ // propagate to children
			acl(lazy[2*k],lazy[k]);
			acl(lazy[2*k+1],lazy[k]);
		}
		lazy[k]={0,0}; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, pair<ll,ll> v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			acl(lazy[k],v); // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	pair<ll,ll> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return {0,0}; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void upd(int a, int b, pair<ll,ll> v){upd(1,0,n,a,b,v);}
	pair<ll,ll> query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ll,ll>> v(n);
	fore(i,0,n)cin>>v[i].fst>>v[i].snd;
	pot2[0]=1;
	fore(i,1,300005)pot2[i]=pot2[i-1]*2ll%MOD;
	pot3[0]=1;
	fore(i,1,300005)pot3[i]=pot3[i-1]*3ll%MOD;
	STree st(300005);
	st.upd(v[0].fst,v[0].snd+1,{1,1});
	fore(i,1,n){
		st.upd(0,300005,{0,1});
		st.upd(v[i].fst,v[i].snd+1,{1,2ll*pot3[i-1]%MOD});
	}
	auto res=st.query(0,300005);
	cout<<res.fst*pot2[res.snd]%MOD<<"\n";
	
	return 0;
}