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
	void init(int k, int s, int e, int *a){
		lazy[k]=0;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	void push(int k, int s, int e){
		if(!lazy[k])return; // if neutral, nothing to do
		st[k]=(e-s)*(lazy[k]-1); // update st according to lazy
		if(s+1<e){ // propagate to children
			if(lazy[k]!=0){
				lazy[2*k]=lazy[k];
				lazy[2*k+1]=lazy[k];
			}
		}
		lazy[k]=0; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, int v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			if(v!=0)lazy[k]=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	int query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return 0; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, int v){upd(1,0,n,a,b,v);}
	int query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);

const int MAXN=200005;

STree st(MAXN);

vector<pair<ll,ll>> p;

string s,f;

void print(ll n){
	fore(i,0,n){
		auto qu=st.query(i,i+1);
		cout<<qu<<" ";
	}
	cout<<"\n";
}


int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		cin>>s>>f;
		fore(i,0,n)st.upd(i,i+1,f[i]-'0'+1);
		//print(n);
		ll br=0;
		p.clear();
		while(q--){
			ll l,r; cin>>l>>r; l--;
			p.pb({l,r});
		}
		reverse(ALL(p));
		fore(_,0,SZ(p)){
			ll l=p[_].fst,r=p[_].snd;
			auto qu=st.query(l,r);
			if(2*qu==r-l){
				br++; break;
			}else if(2*qu<r-l){
				st.upd(l,r,1);
			}else{
				st.upd(l,r,2);
			}
			//print(n);
		}
		fore(i,0,n){
			if(s[i]-'0'!=st.query(i,i+1)){
				br++; break;
			}
		}
		if(br)cout<<"NO\n";
		else cout<<"YES\n";
	}
	
	return 0;
}