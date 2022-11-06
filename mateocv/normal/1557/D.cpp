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

const int MAXN=300005;

vector<pair<ll,ll>> ran[MAXN];

pair<ll,ll> NEUT={0,0};

struct STree { // example: range sum with range addition
	vector<pair<ll,ll>> st,lazy;int n;
	STree(int n): st(4*n+5,NEUT), lazy(4*n+5,NEUT), n(n) {}
	void push(int k, int s, int e){
		if(lazy[k]==NEUT)return; // if neutral, nothing to do
		st[k]=max(lazy[k],st[k]); // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]=max(lazy[k],lazy[2*k]);
			lazy[2*k+1]=max(lazy[k],lazy[2*k+1]);
		}
		lazy[k]=NEUT; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, pair<ll,ll> v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]=max(lazy[k],v); // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=max(st[2*k],st[2*k+1]); // operation
	}
	pair<ll,ll> query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return max(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void upd(int a, int b, pair<ll,ll> v){upd(1,0,n,a,b,v);}
	pair<ll,ll> query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

STree str(2*MAXN);

int main(){FIN;
	ll n,m; cin>>n>>m;
	set<ll> st;
	fore(i,0,m){
		ll pos,l,r; cin>>pos>>l>>r;
		pos--;
		ran[pos].pb({l,r});
		st.insert(l);
		st.insert(r);
	}
	ll va=0;
	map<ll,ll> mp;
	for(auto i:st)mp[i]=va++;
	fore(i,0,n){
		fore(j,0,SZ(ran[i])){
			ran[i][j].fst=mp[ran[i][j].fst];
			ran[i][j].snd=mp[ran[i][j].snd];
		}
	}
	vector<ll>p(n);
	fore(i,0,n)p[i]=-1;
	for(ll i=n-1;i>=0;i--){
		pair<ll,ll> va=NEUT;
		for(auto j:ran[i]){
			va=max(va,str.query(j.fst,j.snd+1));
		}
		if(va.fst==0)p[i]=-1;
		else p[i]=va.snd;
		va.fst++;
		va.snd=i;
		for(auto j:ran[i]){
			str.upd(j.fst,j.snd+1,va);
		}
	}
	auto res=str.query(0,2*m);
	cout<<n-res.fst<<"\n";
	set<ll> el;
	fore(i,0,n)el.insert(i);
	ll vam=res.snd;
	while(vam!=-1){
		el.erase(vam);
		vam=p[vam];
	}
	for(auto i:el)cout<<i+1<<" ";
	cout<<"\n";
	return 0;
}