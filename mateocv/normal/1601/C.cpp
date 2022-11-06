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
	vector<int> st,lazy;int n;
	STree(int n): st(4*n+5,0), lazy(4*n+5,0), n(n) {}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]+=lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=min(st[2*k],st[2*k+1]); // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 1e9; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return min(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b)); // operation
	}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

vector<ll> oc[2000006];

ll cant=0;

ll n,m; 

void upd(ll x, STree &st){
	for(auto i:oc[x-1]){
		st.upd(i,n,-1);
		cant++;
	}
	for(auto i:oc[x]){
		st.upd(i,n,-1);
	}
}

/*----------------SEGMENT_TREE_ITERATIVO----------------*/
#define oper(a,b) a+b
#define NEUT 0
struct STrees{
	vector<int> t; int n;
	STrees(int n):t(2*n+5,NEUT),n(n){}
	void upd(int p, int value){
		for(t[p += n]+=value;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	int query(int l, int r){ // [l, r)
		int res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) res=oper(res,t[l++]);
			if(r&1) res=oper(res,t[--r]);
		}
		return res;
	}
};

STrees str(2000009);

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		vector<ll> a(n),b(m);
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		vector<ll> v={0};
		for(auto i:a)v.pb(i);
		for(auto i:b)v.pb(i);
		sort(ALL(v));
		v.erase(unique(ALL(v)), v.end());
		fore(i,0,n)a[i]=lower_bound(ALL(v),a[i])-v.begin();
		fore(i,0,m)b[i]=lower_bound(ALL(v),b[i])-v.begin();
		sort(ALL(b));
		/*
		for(auto i:a)cout<<i<<" ";
		cout<<"\n";
		for(auto i:b)cout<<i<<" ";
		cout<<"\n";
		*/
		fore(i,0,SZ(v)+1)oc[i].clear();
		fore(i,0,n)oc[a[i]].pb(i);
		STree st(n+10);
		fore(i,0,n)st.upd(i,i+1,i+1);
		ll ul=0,res=0;
		vector<pair<ll,ll>> ao;
		fore(i,0,n)ao.pb({a[i],i});
		sort(ALL(ao));
		for(auto i:ao){
			res+=str.query(i.snd,2000009);
			str.upd(i.snd,1);
		}
		for(auto i:ao)str.upd(i.snd,-1);
		cant=0;
		for(auto i:b){
			while(ul<i){
				ul++;
				upd(ul,st);
			}
			//fore(i,0,n)cout<<st.query(i,i+1)<<" ";
			//cout<<"\n";
			res+=cant+min(0,st.query(0,n));
		}
		cout<<res<<"\n";
	}
	
	
	return 0;
}